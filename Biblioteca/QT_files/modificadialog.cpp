#include "headers/modificadialog.h"

#include <ios>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <list>
#include <string>
#include <bits/ios_base.h>

#include "../C++/headers/biblioteca.h"

ModificaDialog::ModificaDialog(biblioteca *item, QWidget *parent) :
    QDialog(parent), item(item){


    setWindowTitle("Modifica Elemento");
    setFixedSize(800, 600);
    QVBoxLayout *layout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout();

    //Slot generali uguali per tutti
    nomeEdit = new QLineEdit(QString::fromStdString(item->getNome()), this);
    descrizioneEdit = new QLineEdit(QString::fromStdString(item->getDescrizione()), this);
    valoreEdit = new QLineEdit(QString::number(item->getValAtt()), this);
    autenticaEdit = new QLineEdit(QString::fromStdString(item->getAutentica()), this);
    dataEdit = new QLineEdit(QString::fromStdString(item->getDataCreazione()), this);

    formLayout->addRow("Nome:", nomeEdit);
    formLayout->addRow("Descrizione:", descrizioneEdit);
    formLayout->addRow("Valore (€):", valoreEdit);
    formLayout->addRow("Autentica:" ,autenticaEdit);
    formLayout->addRow("Data della Creazione:", dataEdit);

    if (auto m = dynamic_cast<arte*>(item)) {
        //costruzione dei campi in base al tipo
        artistaEdit = new QLineEdit(QString::fromStdString(m->getArtista()), this);
        bottoneSi = new QRadioButton("Sì", this);
        bottoneNO = new QRadioButton("No", this);

        //tendina di scelta per il tipo dell'opera
        tipoOperaEdit = new QComboBox(this);
        tipoOperaEdit->addItem("Quadro");
        tipoOperaEdit->addItem("Scultura");
        tipoOperaEdit->addItem("Concettuale");
        tipoOperaEdit->addItem("Installazione");

        //bottone di scelta tra artista vivo o no
        QButtonGroup* buttonGroup = new QButtonGroup(this);
        buttonGroup->addButton(bottoneSi);
        buttonGroup->addButton(bottoneNO);
        QWidget* radioWidget = new QWidget(this);
        QHBoxLayout* radioLayout = new QHBoxLayout(radioWidget);
        radioLayout->addWidget(bottoneSi);
        radioLayout->addWidget(bottoneNO);
        if (m->getVivo() == true) {
            bottoneSi->setChecked(true);
        }else {
            bottoneNO->setChecked(true);
        }

        //modifica della lista delle esposizioni
        QVBoxLayout *espLayout = new QVBoxLayout();
        QLabel *label = new QLabel("Esposizioni:");
        espLayout->addWidget(label);
        eList = new QListWidget(this);
        espLayout->addWidget(eList);
        int cont = 0;
        for (const auto &i : m->getEspo()) {
            if (!i.empty()) {
                eList->addItem(QString::fromStdString(i));
            }
            if (i == " ") delete eList->takeItem(cont);
            cont++;
        }
        QHBoxLayout *addLayout = new QHBoxLayout();
        nuovaEsposizioneInput = new QLineEdit(this);
        emAddButton = new QPushButton("Aggiungi Esposizione");
        emDelButton = new QPushButton("Rimuovi Esposizione", this);

        addLayout->addWidget(nuovaEsposizioneInput);
        addLayout->addWidget(emAddButton);
        addLayout->addWidget(emDelButton);
        espLayout->addLayout(addLayout);
        connect(emAddButton, &QPushButton::clicked, this, &ModificaDialog::aggiungiAListaEsp);
        connect(emDelButton, &QPushButton::clicked, this, &ModificaDialog::togliDaListaEsp);

        //assegnazione campi alla finestra
        formLayout->addRow("Artista:", artistaEdit);
        formLayout->addRow("Artista Vivo", radioWidget);
        formLayout->addRow("Tipo Opera:", tipoOperaEdit);
        formLayout->addRow("Esposizioni",espLayout);

    } else if (auto m = dynamic_cast<gioielli*>(item)) {
        orafoEdit = new QLineEdit(QString::fromStdString(m->getOrafo()), this);
        QVBoxLayout *matLayout = new QVBoxLayout();
        QLabel *label = new QLabel("Materiali:");
        matLayout->addWidget(label);
        mList = new QListWidget(this);
        matLayout->addWidget(mList);
        int cont = 0;
        for (const auto &i : m->getMateriali()) {
            if (!i.empty()) {
                mList->addItem(QString::fromStdString(i));
            }
            if (i == " ") delete mList->takeItem(cont);
            cont++;
        }
        QHBoxLayout *addLayout = new QHBoxLayout();
        nuovoMaterialeInput = new QLineEdit(this);
        emAddButton = new QPushButton("Aggiungi Materiale");
        emDelButton = new QPushButton("Rimuovi Materiale", this);

        addLayout->addWidget(nuovoMaterialeInput);
        addLayout->addWidget(emAddButton);
        addLayout->addWidget(emDelButton);
        matLayout->addLayout(addLayout);
        connect(emAddButton, &QPushButton::clicked, this, &ModificaDialog::aggiungiAListaMat);
        connect(emDelButton, &QPushButton::clicked, this, &ModificaDialog::togliDaListaMat);

        formLayout->addRow("Orafo:", orafoEdit);
        formLayout->addRow("Materiali:", matLayout);

    }else if (auto m = dynamic_cast<orologi*>(item)){
        modelloEdit = new QLineEdit(QString::fromStdString(m->getModello()), this);
        marcaEdit = new QLineEdit(QString::fromStdString(m->getMarca()), this);
        esemplariEdit = new QLineEdit(QString::number(m->getEsemplari()), this);
        meccanismoEdit = new QComboBox(this);
        meccanismoEdit->addItem("Al Quarzo");
        meccanismoEdit->addItem("Automatico");
        meccanismoEdit->addItem("A Pila");
        meccanismoEdit->addItem("Manuale");

        formLayout->addRow("Modello:", modelloEdit);
        formLayout->addRow("Marca:", marcaEdit);
        formLayout->addRow("Esemplari:", esemplariEdit);
        formLayout->addRow("Meccanismo:", meccanismoEdit);
    }

    salvaButton = new QPushButton("Salva", this);
    annullaButton = new QPushButton("Annulla", this);

    layout->addLayout(formLayout);
    layout->addWidget(salvaButton);
    layout->addWidget(annullaButton);

    connect(salvaButton, &QPushButton::clicked, this, &ModificaDialog::salvaModifiche);
    connect(annullaButton, &QPushButton::clicked, this, &QDialog::reject);

}

void ModificaDialog::salvaModifiche() {

    item->setNome(nomeEdit->text().toStdString());
    item->setDescrizione(descrizioneEdit->text().toStdString());
    item->setVal(valoreEdit->text().toDouble());
    item->setAutentica(autenticaEdit->text().toStdString());
    item->setData(dataEdit->text().toStdString());

    if (auto a = dynamic_cast<arte*>(item)) {
        a->setArtista(artistaEdit->text().toStdString());
        a->setVivo(bottoneSi->isChecked());

        std::list<std::string> esposizioniStd;
        for (int i = 0; i < eList->count(); ++i) {
            QString esposizione = eList->item(i)->text().trimmed();
            if (!esposizione.isEmpty()) {  // Filtra elementi vuoti
                esposizioniStd.push_back(esposizione.toStdString());
            }
        }
        if (esposizioniStd.empty()) {
            esposizioniStd.push_back("Nessuna esposizione");
        }
        a->setEsposizione(esposizioniStd);

        QString tipoOp = tipoOperaEdit->currentText();
        a->setTipoOpera(tipoOp.toStdString());

    } else if (auto g = dynamic_cast<gioielli*>(item)) {
        g->setOrafo(orafoEdit->text().toStdString());
        std::list<std::string> materialiStd;
        for (int i = 0; i < mList->count(); ++i) {
            QString materiale = mList->item(i)->text().trimmed();
            if (!materiale.isEmpty()) {  // Filtra elementi vuoti
                materialiStd.push_back(materiale.toStdString());
            }
        }
        if (materialiStd.empty()) {
                QMessageBox::warning(this, "Errore di Salvataggio",
                                     "Non puoi salvare un gioiello senza almeno un materiale!");
                return;}
        g->setMateriali(materialiStd);

    } else if (auto o = dynamic_cast<orologi*>(item)) {
        o->setModello(modelloEdit->text().toStdString());
        o->setMarca(marcaEdit->text().toStdString());
        o->setEsemplari(esemplariEdit->text().toInt());
        QString mecca = meccanismoEdit->currentText();
        o->setMecc(mecca.toStdString());

    }
    if (item->getNome().empty()) {
        QMessageBox::warning(this, "Errore di Salvataggio",
                                        "Non puoi salvare un oggetto senza nome!");
        return;
    }
    accept();
}


void ModificaDialog::aggiungiAListaEsp() {
    QString nuovaEsposizione = nuovaEsposizioneInput->text().trimmed();
    if (!nuovaEsposizione.isEmpty()) {
        // Cerca e rimuove eventuali elementi vuoti nella lista
        for (int i = 0; i < eList->count(); ++i) {
            if (eList->item(i)->text().isEmpty()) {
                delete eList->takeItem(i);
                i--; // Decrementa l'indice perché la lista si riduce di uno
            }
        }
        // Aggiunge la nuova esposizione solo se non è vuota
        eList->addItem(nuovaEsposizione);
        nuovaEsposizioneInput->clear();
    }else QMessageBox::information(this, "Esposizione Nulla","Stai cercando di inserire una stringa vuota!");
}


// **Metodo per rimuovere un'esposizione selezionata**
void ModificaDialog::togliDaListaEsp() {
    QListWidgetItem* selectedItem = eList->currentItem();
    if (selectedItem) {
        delete selectedItem;
    }
}

void ModificaDialog::aggiungiAListaMat() {
    QString nuovoMateriale = nuovoMaterialeInput->text().trimmed();
    if (!nuovoMateriale.isEmpty()) {
        // Cerca e rimuove eventuali elementi vuoti nella lista
        for (int i = 0; i < mList->count(); ++i) {
            if (mList->item(i)->text().isEmpty()) {
                delete mList->takeItem(i);
                i--; // Decrementa l'indice perché la lista si riduce di uno
            }
        }

        mList->addItem(nuovoMateriale);
        nuovoMaterialeInput->clear();
    }else QMessageBox::information(this, "Materiale Nullo","Stai cercando di inserire una stringa vuota!");
}

void ModificaDialog::togliDaListaMat() {
    QListWidgetItem* selectedItem = mList->currentItem();
    if (selectedItem) {
        delete selectedItem;
    }
}