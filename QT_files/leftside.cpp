#include "headers/leftside.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
//#include <nlohmann/json.hpp>
#include <list>
#include <sys/stat.h>

bool fileEsiste(const std::string& filePath) {
    struct stat buffer;
    return (stat(filePath.c_str(), &buffer) == 0);
}

leftside::leftside(QWidget *parent) : QWidget(parent){
    left = new QVBoxLayout(this);

    bottoneArte = new QPushButton("ARTE");
    bottoenOrologi = new QPushButton("OROLOGI");
    bottoneGioielli = new QPushButton("GIOIELLI");
    ricerca = new QLineEdit();
    ricerca->setPlaceholderText("Search...");
    listaItems = new QListWidget(this);
    filtroAttivo = QString::fromStdString("");
    toolBar = new QToolBar(this);
    salvaAzione = new QAction("Salva", this);
    importa = new QAction("Importa", this);
    bottonePreferiti = new QPushButton("PREFERITI");
    toolBar->addAction(salvaAzione);
    toolBar->addAction(importa);
    bottoneArte->setCheckable(true);
    bottoenOrologi->setCheckable(true);
    bottoneGioielli->setCheckable(true);
    bottonePreferiti->setCheckable(true);
    left->addWidget(toolBar);
    left->addWidget(ricerca);
    left->addWidget(bottoneArte);
    left->addWidget(bottoenOrologi);
    left->addWidget(bottoneGioielli);
    left->addWidget(bottonePreferiti);
    left->addWidget(listaItems);

    //connect elemento cliccato con rightside
    connect(listaItems, &QListWidget::itemClicked, this, [this](QListWidgetItem* item) {
        static QListWidgetItem* lastClickedItem = nullptr;
        if (lastClickedItem == item) {
            item->setSelected(false);
            listaItems->setCurrentItem(nullptr);
            lastClickedItem = nullptr;
            deselezionaElemento();
        } else {
            listaItems->setCurrentItem(item);
            lastClickedItem = item;
            std::string selectedItemName = item->text().toStdString();
            for (biblioteca* obj : oggetti) {
                if (obj->getNome() == selectedItemName) {
                    emit itemSelected(obj);
                    break;
                }
            }
        }
    });

    //connect ricerca
    connect(ricerca, &QLineEdit::textChanged, this, &leftside::filtraListaRicerca);
    //connect dei filtri
    connect(bottoneArte, &QPushButton::clicked, this, [this]() { filtraPerCategoria("arte", bottoneArte); });
    connect(bottoenOrologi, &QPushButton::clicked, this, [this]() { filtraPerCategoria("orologi", bottoenOrologi); });
    connect(bottoneGioielli, &QPushButton::clicked, this, [this]() { filtraPerCategoria("gioielli", bottoneGioielli); });
    connect(bottonePreferiti, &QPushButton::clicked, this, [this]() {filtraPerCategoria("preferiti", bottonePreferiti); });

    //conncet dei salva e importa
    connect(salvaAzione, &QAction::triggered, this, &leftside::salvaLista);
    connect(importa, &QAction::triggered, this, &leftside::importaLista);
}

//METODI JSON
bool leftside::saveToJson() {
  //controllo per vedere se il file è nuovo o è stato importato
  QString filePath;
  if (jsonFilePath == nullptr){
    	filePath = QFileDialog::getSaveFileName(this, "Salva Lista", "", "JSON Files (*.json);;All Files (*)");
    }else{
		filePath = (*jsonFilePath);
    }
    //controlli vari
    if (filePath.isEmpty()) {
        qDebug() << "Salvataggio annullato dall'utente.";
        return false;
    }

    if (oggetti.empty()) {
        QMessageBox::warning(this, "Errore", "La lista è vuota, non c'è nulla da salvare.");
        return false;
    }

    //Inzializzazione visitor
    jsonVisitorSave visitor;
    //controlli su oggetto
    for (biblioteca* obj : oggetti) {
        if (obj) {
            obj->accetta(visitor);
        } else {
            qDebug() << "Errore: oggetto nullo trovato nella lista!";
        }
    }
    if (visitor.arrayJ.isEmpty()) {
        QMessageBox::warning(this, "Errore", "Errore nella generazione del JSON: l'array JSON è vuoto.");
        return false;
    }
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Errore", "Impossibile aprire il file per scrivere: " + filePath);
        return false;
    }
    //scrittura e chiusura del file
    file.write(QJsonDocument(visitor.arrayJ).toJson());
    file.close();
    return true;
}

void leftside::loadJson(const std::string& filePath) {
    //controlli su file e contenuto del file
    jsonFilePath = new QString(QString::fromStdString(filePath));
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Errore: impossibile aprire il file " << filePath << std::endl;
        return;
    }
    nlohmann::json j;
    file >> j;
    file.close();
    if (!j.is_array()) {
        std::cerr << "Errore: il file JSON non contiene un array valido." << std::endl;
        return;
    }
    oggetti.clear();

    for (const auto& jsonObj : j) {
        if (!jsonObj.contains("tipo")) continue;

        std::string type = jsonObj["tipo"];
        //scelta in base al tipo
        if (type == "gioielli") {
            std::string nome = jsonObj["nome"].get<std::string>();
            std::string descrizione = jsonObj["descrizione"].get<std::string>();
            std::string autentica = jsonObj["autentica"].get<std::string>();
            int data = jsonObj["data creazione"].get<int>();
            double v = jsonObj["valore"].get<double>();
            bool b = jsonObj["preferiti"].get<bool>();
            std::string im = jsonObj ["immagine"].get<std::string>();
            std::list<std::string> ma;
            std::string materiali = jsonObj["materiali"].get<std::string>();
            std::istringstream iss(materiali);
            std::string word;
            while (std::getline(iss, word, ';')) {
                if (!word.empty()) {
                    ma.push_back(word);
                }
            }
            std::string orafo = jsonObj["orafo"].get<std::string>();
            biblioteca *g = new gioielli(nome, descrizione, autentica, data, v, b, im, ma, orafo);
            oggetti.push_back(g);
        }
        else if (type == "orologi") {
            std::string nome = jsonObj["nome"].get<std::string>();
            std::string descrizione = jsonObj["descrizione"].get<std::string>();
            std::string autentica = jsonObj["autentica"].get<std::string>();
            int data = jsonObj["data creazione"].get<int>();
            double v = jsonObj["valore"].get<double>();
            bool b = jsonObj["preferiti"].get<bool>();
            std::string im = jsonObj ["immagine"].get<std::string>();
            std::string modello = jsonObj["modello"].get<std::string>();
            std::string marca = jsonObj["marca"].get<std::string>();
            int ne = jsonObj["numero esemplari"].get<int>();
            std::string meccanismo = jsonObj["meccanismo"].get<std::string>();
            biblioteca *o = new orologi(nome, descrizione, autentica, data, v, b, im, modello, marca, ne, meccanismo);
            oggetti.push_back(o);  // Aggiungi l'oggetto alla lista
        }
        else if (type == "arte") {
            std::string nome = jsonObj["nome"].get<std::string>();
            std::string descrizione = jsonObj["descrizione"].get<std::string>();
            std::string autentica = jsonObj["autentica"].get<std::string>();
            int data = jsonObj["data creazione"].get<int>();
            double v = jsonObj["valore"].get<double>();
            bool b = jsonObj["preferiti"].get<bool>();
            std::string im = jsonObj ["immagine"].get<std::string>();
            std::string artista = jsonObj["artista"].get<std::string>();
            std::string opera = jsonObj["tipo opera"].get<std::string>();
            bool vivo = jsonObj["artista vivo"].get<bool>();
            std::list<std::string> esp;
            std::string esposizioni = jsonObj["esposizione"].get<std::string>();
            std::istringstream iss(esposizioni);
            std::string word;
            while (std::getline(iss, word, ';')) {
                if (!word.empty()) {
                    esp.push_back(word);
                }
            }
            biblioteca *a = new arte(nome, descrizione, autentica, data, v, b, im, artista, opera, vivo, esp);
            oggetti.push_back(a);
        }
    }
    popolaLista();
}


//METODI SULLA LISTA
//popola la lista
void leftside::popolaLista(){
    listaItems->clear();
    for(biblioteca* obj : oggetti) {
        if(dynamic_cast<orologi*>(obj)) {
            QListWidgetItem *icons = new QListWidgetItem(QString::fromStdString(obj->getNome()));
            icons->setIcon(QIcon(":QT_files/assets/orlogiopolso.png"));
            listaItems->addItem(icons);
        }else if(dynamic_cast<arte*>(obj)){
            QListWidgetItem *icons = new QListWidgetItem(QString::fromStdString(obj->getNome()));
            icons->setIcon(QIcon(":QT_files/assets/tavolozza.png"));
            listaItems->addItem(icons);
        }else if(dynamic_cast<gioielli*>(obj)) {
            QListWidgetItem *icons = new QListWidgetItem(QString::fromStdString(obj->getNome()));
            icons->setIcon(QIcon(":QT_files/assets/diamante.png"));
            listaItems->addItem(icons);
        }
        listaItems->setIconSize(QSize(24, 24));
    }
}

//filtro della ricerca
void leftside::filtraListaRicerca() {
    bottoneArte->setChecked(false);
    bottoenOrologi->setChecked(false);
    bottoneGioielli->setChecked(false);
    QString filtro = ricerca->text().trimmed().toLower();
    listaItems->clear();
    for (biblioteca* obj : oggetti) {
        QString nomeOggetto = QString::fromStdString(obj->getNome()).toLower();

        if (nomeOggetto.contains(filtro)) {
            if(dynamic_cast<arte*>(obj)) {
                QListWidgetItem *icons = new QListWidgetItem(QString::fromStdString(obj->getNome()));
                icons->setIcon(QIcon(":QT_files/assets/tavolozza.png"));
                listaItems->addItem(icons);
            }else if(dynamic_cast<orologi*>(obj)) {
                QListWidgetItem *icons = new QListWidgetItem(QString::fromStdString(obj->getNome()));
                icons->setIcon(QIcon(":QT_files/assets/orlogiopolso.png"));
                listaItems->addItem(icons);
            }else if(dynamic_cast<gioielli*>(obj)) {
                QListWidgetItem *icons = new QListWidgetItem(QString::fromStdString(obj->getNome()));
                icons->setIcon(QIcon(":QT_files/assets/diamante.png"));
                listaItems->addItem(icons);
            }
        }
    }
}

//filtra la lista per tipo
void leftside::filtraPerCategoria(const QString &categoria, QPushButton *bottoneSelezionato) {
    if (filtroAttivo == categoria) {
        filtroAttivo = "";
        bottoneSelezionato->setChecked(false);
    } else {
        filtroAttivo = categoria;
        bottoneArte->setChecked(bottoneSelezionato == bottoneArte);
        bottoenOrologi->setChecked(bottoneSelezionato == bottoenOrologi);
        bottoneGioielli->setChecked(bottoneSelezionato == bottoneGioielli);
        bottonePreferiti->setChecked(bottoneSelezionato == bottonePreferiti);
    }
    listaItems->clear();
    for (biblioteca* obj : oggetti) {
        std::string tipo = "";
        if (dynamic_cast<arte*>(obj)) {
            tipo = "arte";
        } else if (dynamic_cast<orologi*>(obj)) {
            tipo = "orologi";
        } else if (dynamic_cast<gioielli*>(obj)) {
            tipo = "gioielli";
        }
        bool flag = obj->getPreferiti();
        if(filtroAttivo.isEmpty() || (filtroAttivo == QString::fromStdString("preferiti") && flag==true)) {
            if(dynamic_cast<arte*>(obj)) {
                QListWidgetItem *icons = new QListWidgetItem(QString::fromStdString(obj->getNome()));
                icons->setIcon(QIcon(":QT_files/assets/tavolozza.png"));
                listaItems->addItem(icons);
            }else if(dynamic_cast<orologi*>(obj)) {
                QListWidgetItem *icons = new QListWidgetItem(QString::fromStdString(obj->getNome()));
                icons->setIcon(QIcon(":QT_files/assets/orlogiopolso.png"));
                listaItems->addItem(icons);
            }else if(dynamic_cast<gioielli*>(obj)) {
                QListWidgetItem *icons = new QListWidgetItem(QString::fromStdString(obj->getNome()));
                icons->setIcon(QIcon(":QT_files/assets/diamante.png"));
                listaItems->addItem(icons);
            }
        }
        else if (filtroAttivo.isEmpty() || QString::fromStdString(tipo) == filtroAttivo) {
            if(dynamic_cast<arte*>(obj)) {
                QListWidgetItem *icons = new QListWidgetItem(QString::fromStdString(obj->getNome()));
                icons->setIcon(QIcon(":QT_files/assets/tavolozza.png"));
                listaItems->addItem(icons);
            }else if(dynamic_cast<orologi*>(obj)) {
                QListWidgetItem *icons = new QListWidgetItem(QString::fromStdString(obj->getNome()));
                icons->setIcon(QIcon(":QT_files/assets/orlogiopolso.png"));
                listaItems->addItem(icons);
            }else if(dynamic_cast<gioielli*>(obj)) {
                QListWidgetItem *icons = new QListWidgetItem(QString::fromStdString(obj->getNome()));
                icons->setIcon(QIcon(":QT_files/assets/diamante.png"));
                listaItems->addItem(icons);
            }
        }
    }
}


//METODI DI AZIONE
//salvataggio
void leftside::salvaLista() {
    filtroAttivo = "";  // Reset del filtro
    ricerca->clear();
    bottoneArte->setChecked(false);
    bottoenOrologi->setChecked(false);
    bottoneGioielli->setChecked(false);
    if (jsonFilePath != nullptr) {
		QMessageBox::StandardButton risposta;
    	risposta = QMessageBox::question(this, "Conferma Salvataggio",
                                     "Sei sicuro di voler salvare le modifiche sul file corrente?",
                                     QMessageBox::Yes | QMessageBox::No);
		if(risposta == QMessageBox::Yes) {
   	    	popolaLista();
        	bool salvataggio = saveToJson();
    	if (salvataggio) QMessageBox::information(this, "Salvataggio", "Lista salvata correttamente!");
		}else return;
    }
    else{
		popolaLista();
		bool salvataggio = saveToJson();
    	if (salvataggio) QMessageBox::information(this, "Salvataggio", "Lista salvata correttamente!");
    }
}

//importazione del file json
void leftside::importaLista() {
    QString filePath = QFileDialog::getOpenFileName(this, "Importa Lista", "", "JSON Files (*.json);;All Files (*)");

    if (filePath.isEmpty()) return;

    if (!fileEsiste(filePath.toStdString())) {
        std::cerr << "Errore: Il file " << filePath.toStdString() << " non esiste!" << std::endl;
        return;
    } else {
        std::cout << "Il file esiste: " << filePath.toStdString() << std::endl;
    }

    loadJson(filePath.toStdString());

    for (biblioteca* obj : oggetti) {
        delete obj;
    }

    oggetti.clear();
    listaItems->clear();
    loadJson(filePath.toStdString());
    popolaLista();
}

//eliminazione e rimozione di un item
void leftside::rimuoviItem(const QString& itemName) {
    auto it = std::find_if(oggetti.begin(), oggetti.end(), [&](biblioteca* obj) {
        return obj->getNome() == itemName.toStdString();
    });
    QMessageBox::StandardButton risposta;
    risposta = QMessageBox::question(this, "Conferma eliminazione",
                                     "Sei sicuro di voler eliminare questo elemento?",
                                     QMessageBox::Yes | QMessageBox::No);

    if (risposta == QMessageBox::Yes) {
        if (it != oggetti.end()) {

          	delete *it;
            oggetti.erase(it);
            popolaLista();
        }
        qDebug() << "Elemento eliminato!";
    } else {
        qDebug() << "Eliminazione annullata.";
    }
}
void leftside::checkName(biblioteca* item) {
    QString baseName = QString::fromStdString(item->getNome());
    QString nuovoNome = baseName;
    int contatore = 0;
    bool nomeEsistente = true;
    int posizioneCorrente;

    while (nomeEsistente) {
        nomeEsistente = false;
        for (int i = 0; i < listaItems->count(); ++i) {
            QListWidgetItem *listItem = listaItems->item(i);
            if (oggetti [i] == item){
                posizioneCorrente = i;}
            if (listItem->text() == nuovoNome && i != posizioneCorrente){
                nomeEsistente = true;
                break;
            }
        }
        if (nomeEsistente) {
            contatore++;
            nuovoNome = baseName + " " + QString::number(contatore+1);
        }
    }
    item->setNome(nuovoNome.toStdString());
}

void leftside::aggiornaItem(biblioteca *item) {
    checkName(item);
    for (int i = 0; i < listaItems->count(); ++i) {
        QListWidgetItem *list = listaItems->item(i);
        list->setText(QString::fromStdString(item->getNome()));
        break;
    }
    popolaLista();
}


//deselezione dell'elemento
void leftside::deselezionaElemento() {
    if (listaItems->selectedItems().isEmpty()) {
        emit elementoDeselezionato();
    }
}

void leftside::costruisciOggetto(const QString &tipo, const QVariantMap &dati) {
    if (tipo == "Arte") {
        QStringList esposizioni_qstringlist = dati["esposizioni"].toStringList();
        std::list<std::string> esposizioni;
        for (const QString &esposizione : esposizioni_qstringlist) {
            esposizioni.push_back(esposizione.toStdString());
        }
        arte *art = new arte(
            dati["nome"].toString().toStdString(),
            dati["descrizione"].toString().toStdString(),
            dati["autentica"].toString().toStdString(),
            dati["data creazione"].toInt(),
            dati["valore"].toDouble(),
            dati["preferiti"].toBool(),
            dati["immagine"].toString().toStdString(),
            dati["artista"].toString().toStdString(),
            dati["tipo opera"].toString().toStdString(),
            dati["artista vivo"].toBool(),
            esposizioni);

        if(art) {
            checkName(art);
            oggetti.push_back(art);
            popolaLista();
        }
    } else if (tipo == "Gioielli") {

        QStringList materiali_qstringlist = dati["materiali"].toStringList();
        std::list<std::string> materiali;
        for (const QString &materiale : materiali_qstringlist) {
            materiali.push_back(materiale.toStdString());
        }
        gioielli *gio = new gioielli(
            dati["nome"].toString().toStdString(),
            dati["descrizione"].toString().toStdString(),
            dati["autentica"].toString().toStdString(),
            dati["data creazione"].toInt(),
            dati["valore"].toDouble(),
            dati["preferiti"].toBool(),
            dati["immagine"].toString().toStdString(),
            materiali,
            dati["orafo"].toString().toStdString());
        if(gio) {
            checkName(gio);
            oggetti.push_back(gio);
            popolaLista();
        }
    } else if (tipo == "Orologi") {
        orologi *orol = new orologi(
            dati["nome"].toString().toStdString(),
            dati["descrizione"].toString().toStdString(),
            dati["autentica"].toString().toStdString(),
            dati["data creazione"].toInt(),
            dati["valore"].toDouble(),
            dati["preferiti"].toBool(),
            dati["immagine"].toString().toStdString(),
            dati["modello"].toString().toStdString(),
            dati["marca"].toString().toStdString(),
            dati["esemplari"].toInt(),
            dati["meccanismo"].toString().toStdString());
        checkName(orol);
        if(orol) {
            oggetti.push_back(orol);
            popolaLista();
        }
    }
}


