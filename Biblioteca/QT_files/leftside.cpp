#include "headers/leftside.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <list>
#include <sys/stat.h>

bool fileEsiste(const std::string& filePath) {
    struct stat buffer;
    return (stat(filePath.c_str(), &buffer) == 0);
}

leftside::leftside(/*content* contWidget,*/ QWidget *parent) : QWidget(parent){
    left = new QVBoxLayout(this);
    //this->contWidget = contWidget;

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

    toolBar->addAction(salvaAzione);
    toolBar->addAction(importa);

    bottoneArte->setCheckable(true);
    bottoenOrologi->setCheckable(true);
    bottoneGioielli->setCheckable(true);

    left->addWidget(toolBar);
    left->addWidget(ricerca);
    left->addWidget(bottoneArte);
    left->addWidget(bottoenOrologi);
    left->addWidget(bottoneGioielli);
    left->addWidget(listaItems);

    //connect elemnto cliccato con rightside
    connect(listaItems, &QListWidget::itemClicked, this, [this](QListWidgetItem* item) {
        std::string selectedItemName = item->text().toStdString();
        for (biblioteca* obj : oggetti) {
            if (obj->getNome() == selectedItemName) {
                emit itemSelected(obj);  // Emit the selected item to rightside
                break;
            }
        }
    });
    //connect ricerca
    connect(ricerca, &QLineEdit::textChanged, this, &leftside::filtraListaRicerca);
    //connect dei filtri
    connect(bottoneArte, &QPushButton::clicked, this, [this]() { filtraPerCategoria("arte", bottoneArte); });
    connect(bottoenOrologi, &QPushButton::clicked, this, [this]() { filtraPerCategoria("orologi", bottoenOrologi); });
    connect(bottoneGioielli, &QPushButton::clicked, this, [this]() { filtraPerCategoria("gioielli", bottoneGioielli); });
    //conncet dei salva e importa
    connect(salvaAzione, &QAction::triggered, this, &leftside::salvaLista);
    connect(importa, &QAction::triggered, this, &leftside::importaLista);

    //pezzo di codice per importare automaticamente qualcosa alla creazione, non necessario ma lo teniamo per ora
    /*std::string filePath = "/home/BRN/Scrivania/gg.json";
        if (!fileEsiste(filePath)) {
            std::cerr << "Errore: Il file " << filePath << " non esiste!" << std::endl;
        } else {
            std::cout << "Il file esiste: " << filePath << std::endl;

        }
    loadJson(filePath);
    popolaLista();*/
}

//METODI JSON
void leftside::saveToJson() {
    // Finestra di dialogo per scegliere il percorso di salvataggio
    QString filePath = QFileDialog::getSaveFileName(this, "Salva Lista", "", "JSON Files (*.json);;All Files (*)");

    //controlli vari
    if (filePath.isEmpty()) {
        qDebug() << "Salvataggio annullato dall'utente.";
        return;
    }

    if (oggetti.empty()) {
        QMessageBox::warning(this, "Errore", "La lista è vuota, non c'è nulla da salvare.");
        return;
    }

    //Inzializzazione visitor
    jsonVisitorSave visitor;

    for (biblioteca* obj : oggetti) {
        if (obj) {
            obj->accetta(visitor);
        } else {
            qDebug() << "Errore: oggetto nullo trovato nella lista!";
        }
    }

    if (visitor.arrayJ.isEmpty()) {
        QMessageBox::warning(this, "Errore", "Errore nella generazione del JSON: l'array JSON è vuoto.");
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Errore", "Impossibile aprire il file per scrivere: " + filePath);
        return;
    }
    //scrittura e chiusura del file
    file.write(QJsonDocument(visitor.arrayJ).toJson());
    file.close();
}

void leftside::loadJson(const std::string& filePath) {
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
        if (!jsonObj.contains("tipo")) continue;  // Ignora se il tipo non è presente

        std::string type = jsonObj["tipo"];

        if (type == "gioielli") {
            std::string nome = jsonObj["nome"].get<std::string>();
            std::string descrizione = jsonObj["descrizione"].get<std::string>();
            std::string autentica = jsonObj["autentica"].get<std::string>();
            std::string data = jsonObj["data creazione"].get<std::string>();
            double v = jsonObj["valore"].get<double>();
            bool b = jsonObj["preferiti"].get<bool>();
            std::string id = jsonObj["id"].get<std::string>();

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
            biblioteca *g = new gioielli(nome, descrizione, autentica, data, v, b, id, ma, orafo);
            oggetti.push_back(g);
        }
        else if (type == "orologi") {
            // Recupera i dati per l'oggetto "orologi"
            std::string nome = jsonObj["nome"].get<std::string>();
            std::string descrizione = jsonObj["descrizione"].get<std::string>();
            std::string autentica = jsonObj["autentica"].get<std::string>();
            std::string data = jsonObj["data creazione"].get<std::string>();
            double v = jsonObj["valore"].get<double>();
            bool b = jsonObj["preferiti"].get<bool>();
            std::string id = jsonObj["id"].get<std::string>();
            std::string modello = jsonObj["modello"].get<std::string>();
            std::string marca = jsonObj["marca"].get<std::string>();
            int ne = jsonObj["numero esemplari"].get<int>();
            std::string meccanismo = jsonObj["meccanismo"].get<std::string>();
            biblioteca *o = new orologi(nome, descrizione, autentica, data, v, b, id, modello, marca, ne, meccanismo);
            oggetti.push_back(o);  // Aggiungi l'oggetto alla lista
        }
        else if (type == "arte") {
            // Recupera i dati per l'oggetto "arte"
            std::string nome = jsonObj["nome"].get<std::string>();
            std::string descrizione = jsonObj["descrizione"].get<std::string>();
            std::string autentica = jsonObj["autentica"].get<std::string>();
            std::string data = jsonObj["data creazione"].get<std::string>();
            double v = jsonObj["valore"].get<double>();
            bool b = jsonObj["preferiti"].get<bool>();
            std::string id = jsonObj["id"].get<std::string>();
            std::string artista = jsonObj["artista"].get<std::string>();
            std::string opera = jsonObj["tipo opera"].get<std::string>();
            bool vivo = jsonObj["artista vivo"].get<bool>();

            std::list<std::string> esp;
            std::string esposizioni = jsonObj["esposizione"].get<std::string>();
            std::istringstream iss(esposizioni);
            std::string word;
            while (std::getline(iss, word, ';')) {  // Usa ';' come delimitatore
                if (!word.empty()) {
                    esp.push_back(word);  // Aggiungi la parola alla lista
                }
            }
            biblioteca *a = new arte(nome, descrizione, autentica, data, v, b, id, artista, opera, vivo, esp);
            oggetti.push_back(a);  // Aggiungi l'oggetto alla lista
        }
    }
    popolaLista();  // Aggiorna la lista visualizzata
}

//METODI SULLA LISTA
//popola la lista
void leftside::popolaLista(){
    listaItems->clear();
    for(biblioteca* obj : oggetti) {
        listaItems->addItem(QString::fromStdString(obj->getNome()));
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
            listaItems->addItem(QString::fromStdString(obj->getNome()));
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
        if (filtroAttivo.isEmpty() || QString::fromStdString(tipo) == filtroAttivo) {
            listaItems->addItem(QString::fromStdString(obj->getNome()));
        }
    }
}


//METODI DI AZIONE
//salvataggio
void leftside::salvaLista() {
    // Rimuovi i filtri e la ricerca
    filtroAttivo = "";  // Reset del filtro
    ricerca->clear();
    bottoneArte->setChecked(false);
    bottoenOrologi->setChecked(false);
    bottoneGioielli->setChecked(false);

    popolaLista();

    saveToJson();
    QMessageBox::information(this, "Salvataggio", "Lista salvata correttamente!");
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
