#include "headers/modificadialog.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <list>
#include <string>
ModificaDialog::ModificaDialog(biblioteca *item, QWidget *parent) :
    QDialog(parent), item(item) {

    setWindowTitle("Modifica Elemento");
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
        QVBoxLayout *layout = new QVBoxLayout(this);
        QLabel *label = new QLabel("Esposizioni:");
        layout->addWidget(label);
        emList = new QListWidget(this);
        layout->addWidget(emList);
        int cont = 0;
        for (const auto &i : m->getEspo()) {
            if (!i.empty()) {
                emList->addItem(QString::fromStdString(i));
            }
            if (i.empty() || i == " ") delete emList->takeItem(cont);
            cont++;
        }
        QHBoxLayout *addLayout = new QHBoxLayout();
        nuovaEsposizioneInput = new QLineEdit(this);
        emAddButton = new QPushButton("Aggiungi Esposizione");
        emDelButton = new QPushButton("Rimuovi Esposizione", this);

        addLayout->addWidget(nuovaEsposizioneInput);
        addLayout->addWidget(emAddButton);
        addLayout->addWidget(emDelButton);
        layout->addLayout(addLayout);
        connect(emAddButton, &QPushButton::clicked, this, &ModificaDialog::aggiungiAList);
        connect(emDelButton, &QPushButton::clicked, this, &ModificaDialog::togliDaList);

        //assegnazione campi alla finestra
        formLayout->addRow("Artista:", artistaEdit);
        formLayout->addRow("Artista Vivo", radioWidget);
        formLayout->addRow("Tipo Opera:", tipoOperaEdit);
        formLayout->addRow("Esposizioni",layout);

    } else if (auto m = dynamic_cast<gioielli*>(item)) {
        orafoEdit = new QLineEdit(QString::fromStdString(m->getOrafo()), this);
        formLayout->addRow("Orafo:", orafoEdit);
    }else if (auto m = dynamic_cast<orologi*>(item)){
        modelloEdit = new QLineEdit(QString::fromStdString(m->getModello()), this);
        formLayout->addRow("Modello:", modelloEdit);
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

    if (auto o = dynamic_cast<arte*>(item)) {
        o->setArtista(artistaEdit->text().toStdString());
        o->setVivo(bottoneSi->isChecked());

        // **Conversione della lista esposizioni**
        std::list<std::string> esposizioniStd;
        for (int i = 0; i < emList->count(); ++i) {
            esposizioniStd.push_back(emList->item(i)->text().toStdString());
        }
        o->setEsposizione(esposizioniStd);  // **Ora viene effettivamente salvata**

        QString tipoOp = tipoOperaEdit->currentText();
        o->setTipoOpera(tipoOp.toStdString());
    } else if (auto o = dynamic_cast<gioielli*>(item)) {
        o->setOrafo(orafoEdit->text().toStdString());
    } else if (auto o = dynamic_cast<orologi*>(item)) {
        o->setModello(modelloEdit->text().toStdString());
    }

    accept();
}


void ModificaDialog::aggiungiAList() {
    QString nuovaEsposizione = nuovaEsposizioneInput->text().trimmed();
    if (!nuovaEsposizione.isEmpty()) {
        // Cerca e rimuove eventuali elementi vuoti nella lista
        for (int i = 0; i < emList->count(); ++i) {
            if (emList->item(i)->text().isEmpty()) {
                delete emList->takeItem(i);
                i--; // Decrementa l'indice perché la lista si riduce di uno
            }
        }
        // Aggiunge la nuova esposizione solo se non è vuota
        emList->addItem(nuovaEsposizione);
        nuovaEsposizioneInput->clear();
    }else QMessageBox::information(this, "Esposizione Nulla","Stai cercando di inserire una stringa vuota!");
}


// **Metodo per rimuovere un'esposizione selezionata**
void ModificaDialog::togliDaList() {
    QListWidgetItem* selectedItem = emList->currentItem();
    if (selectedItem) {
        delete selectedItem;
    }
}



