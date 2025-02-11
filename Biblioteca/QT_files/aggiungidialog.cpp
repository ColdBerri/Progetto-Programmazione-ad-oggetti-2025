#include "headers/aggiungidialog.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

AggiungiDialog::AggiungiDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Aggiungi Elemento");
    setFixedSize(700,600);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Creazione dei bottoni per la scelta del tipo
    bottoneArte = new QRadioButton("Arte", this);
    bottoneGioielli = new QRadioButton("Gioielli", this);
    bottoneOrologi = new QRadioButton("Orologi", this);

    tipoGroup = new QButtonGroup(this);
    tipoGroup->addButton(bottoneArte);
    tipoGroup->addButton(bottoneGioielli);
    tipoGroup->addButton(bottoneOrologi);
    tipoGroup->setExclusive(true);

    confermaTipoButton = new QPushButton("Conferma Tipo", this);
    confermaTipoButton->setEnabled(false);

    QHBoxLayout *tipoLayout = new QHBoxLayout();
    tipoLayout->addWidget(bottoneArte);
    tipoLayout->addWidget(bottoneGioielli);
    tipoLayout->addWidget(bottoneOrologi);
    tipoLayout->addWidget(confermaTipoButton);
    mainLayout->addLayout(tipoLayout);

    // Creazione del contenitore per il form di input
    formWidget = new QWidget(this);
    formLayout = new QFormLayout(formWidget);
    formWidget->setLayout(formLayout);
    formWidget->setEnabled(false);
    mainLayout->addWidget(formWidget);

    // Bottoni finali
    salvaButton = new QPushButton("Salva", this);
    annullaButton = new QPushButton("Annulla", this);
    mainLayout->addWidget(salvaButton);
    mainLayout->addWidget(annullaButton);

    // Connessioni
    connect(bottoneArte, &QRadioButton::clicked, this, &AggiungiDialog::abilitaConferma);
    connect(bottoneGioielli, &QRadioButton::clicked, this, &AggiungiDialog::abilitaConferma);
    connect(bottoneOrologi, &QRadioButton::clicked, this, &AggiungiDialog::abilitaConferma);
    connect(confermaTipoButton, &QPushButton::clicked, this, &AggiungiDialog::confermaScelta);
    connect(salvaButton, &QPushButton::clicked, this, &AggiungiDialog::salvaNuovo);
    connect(annullaButton, &QPushButton::clicked, this, &QDialog::reject);
    pulisciForm();
}

void AggiungiDialog::abilitaConferma() {
    confermaTipoButton->setEnabled(true);
}

void AggiungiDialog::confermaScelta() {
    // Disabilita i bottoni di scelta e abilita il form
    bottoneArte->setEnabled(false);
    bottoneGioielli->setEnabled(false);
    bottoneOrologi->setEnabled(false);
    confermaTipoButton->setEnabled(false);
    formWidget->setEnabled(true);

    if (bottoneArte->isChecked()) {
        mostraArte();
    } else if (bottoneGioielli->isChecked()) {
        mostraGioielli();
    } else if (bottoneOrologi->isChecked()) {
        mostraOrologi();
    }
}

// Cambiato il return type in void, visto che non utilizziamo il valore restituito.
void AggiungiDialog::mostraArte() {
    // Campi comuni
    nomeNew = new QLineEdit(this);
    descrizioneNew = new QLineEdit(this);
    valoreNew = new QLineEdit(this);
    autenticaNew = new QLineEdit(this);
    dataNew = new QLineEdit(this);

    formLayout->addRow("Nome:", nomeNew);
    formLayout->addRow("Descrizione:", descrizioneNew);
    formLayout->addRow("Valore (€):", valoreNew);
    formLayout->addRow("Autentica:", autenticaNew);
    formLayout->addRow("Data della Creazione:", dataNew);

    // Campi specifici per Arte
    artistaNew = new QLineEdit(this);
    bottoneSi = new QRadioButton("Sì", this);
    bottoneNO = new QRadioButton("No", this);

    tipoOperaEdit = new QComboBox(this);
    tipoOperaEdit->addItem("Quadro");
    tipoOperaEdit->addItem("Scultura");
    tipoOperaEdit->addItem("Concettuale");
    tipoOperaEdit->addItem("Installazione");

    QButtonGroup *buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(bottoneSi);
    buttonGroup->addButton(bottoneNO);

    QWidget *radioWidget = new QWidget(this);
    QHBoxLayout *radioLayout = new QHBoxLayout(radioWidget);
    radioLayout->addWidget(bottoneSi);
    radioLayout->addWidget(bottoneNO);

    // Lista esposizioni
    QVBoxLayout *espLayout = new QVBoxLayout();
    QLabel *label = new QLabel("Esposizioni:", this);
    espLayout->addWidget(label);
    eList = new QListWidget(this);
    espLayout->addWidget(eList);

    QHBoxLayout *addLayout = new QHBoxLayout();
    nuovaEsposizioneInput = new QLineEdit(this);
    emAddButton = new QPushButton("Aggiungi Esposizione", this);
    emDelButton = new QPushButton("Rimuovi Esposizione", this);

    addLayout->addWidget(nuovaEsposizioneInput);
    addLayout->addWidget(emAddButton);
    addLayout->addWidget(emDelButton);
    espLayout->addLayout(addLayout);

    // Usa i metodi della stessa classe (non ModificaDialog)
    connect(emAddButton, &QPushButton::clicked, this, &AggiungiDialog::aggiungiAListaEsp);
    connect(emDelButton, &QPushButton::clicked, this, &AggiungiDialog::togliDaListaEsp);

    formLayout->addRow("Artista:", artistaNew);
    formLayout->addRow("Artista Vivo:", radioWidget);
    formLayout->addRow("Tipo Opera:", tipoOperaEdit);
    formLayout->addRow("Esposizioni:", espLayout);
}

void AggiungiDialog::mostraGioielli() {
    // Campi comuni
    nomeNew = new QLineEdit(this);
    descrizioneNew = new QLineEdit(this);
    valoreNew = new QLineEdit(this);
    autenticaNew = new QLineEdit(this);
    dataNew = new QLineEdit(this);

    formLayout->addRow("Nome:", nomeNew);
    formLayout->addRow("Descrizione:", descrizioneNew);
    formLayout->addRow("Valore (€):", valoreNew);
    formLayout->addRow("Autentica:", autenticaNew);
    formLayout->addRow("Data della Creazione:", dataNew);

    // Campi specifici per Gioielli
    orafoNew = new QLineEdit(this);
    QVBoxLayout *matLayout = new QVBoxLayout();
    QLabel *label = new QLabel("Materiali:", this);
    matLayout->addWidget(label);
    mList = new QListWidget(this);
    matLayout->addWidget(mList);

    QHBoxLayout *addLayout = new QHBoxLayout();
    nuovoMaterialeInput = new QLineEdit(this);
    emAddButton = new QPushButton("Aggiungi Materiale", this);
    emDelButton = new QPushButton("Rimuovi Materiale", this);

    addLayout->addWidget(nuovoMaterialeInput);
    addLayout->addWidget(emAddButton);
    addLayout->addWidget(emDelButton);
    matLayout->addLayout(addLayout);

    connect(emAddButton, &QPushButton::clicked, this, &AggiungiDialog::aggiungiAListaMat);
    connect(emDelButton, &QPushButton::clicked, this, &AggiungiDialog::togliDaListaMat);

    formLayout->addRow("Orafo:", orafoNew);
    formLayout->addRow("Materiali:", matLayout);
}

void AggiungiDialog::mostraOrologi() {
    // Campi comuni
    nomeNew = new QLineEdit(this);
    descrizioneNew = new QLineEdit(this);
    valoreNew = new QLineEdit(this);
    autenticaNew = new QLineEdit(this);
    dataNew = new QLineEdit(this);

    formLayout->addRow("Nome:", nomeNew);
    formLayout->addRow("Descrizione:", descrizioneNew);
    formLayout->addRow("Valore (€):", valoreNew);
    formLayout->addRow("Autentica:", autenticaNew);
    formLayout->addRow("Data della Creazione:", dataNew);

    // Campi specifici per Orologi
    modelloNew = new QLineEdit(this);
    marcaNew = new QLineEdit(this);
    esemplariNew = new QLineEdit(this);
    meccanismoNew = new QComboBox(this);
    meccanismoNew->addItem("Al Quarzo");
    meccanismoNew->addItem("Automatico");
    meccanismoNew->addItem("A Pila");
    meccanismoNew->addItem("Manuale");

    formLayout->addRow("Modello:", modelloNew);
    formLayout->addRow("Marca:", marcaNew);
    formLayout->addRow("Esemplari:", esemplariNew);
    formLayout->addRow("Meccanismo:", meccanismoNew);
}

void AggiungiDialog::pulisciForm() {
    QLayoutItem *item;
    while ((item = formLayout->takeAt(0)) != nullptr) {
        if(item->widget())
            delete item->widget();
        delete item;
    }
}

void AggiungiDialog::salvaNuovo() {
    QVariantMap dati;
    dati["nome"] = nomeNew->text();
    dati["descrizione"] = descrizioneNew->text();
    dati["valore"] = valoreNew->text();
    dati["autentica"] = autenticaNew->text();
    dati["data"] = dataNew->text();

    if (bottoneArte->isChecked()) {
        dati["tipo"] = "Arte";
        dati["artista"] = artistaNew->text();
        dati["artista_vivo"] = bottoneSi->isChecked();
        dati["tipo_opera"] = tipoOperaEdit->currentText();

        QStringList esposizioni;
        for (int i = 0; i < eList->count(); ++i) {
            esposizioni.append(eList->item(i)->text());
        }
        dati["esposizioni"] = esposizioni;

    } else if (bottoneGioielli->isChecked()) {
        dati["tipo"] = "Gioielli";
        dati["orafo"] = orafoNew->text();

        QStringList materiali;
        for (int i = 0; i < mList->count(); ++i) {
            materiali.append(mList->item(i)->text());
        }
        dati["materiali"] = materiali;

    } else if (bottoneOrologi->isChecked()) {
        dati["tipo"] = "Orologi";
        dati["modello"] = modelloNew->text();
        dati["marca"] = marcaNew->text();
        dati["esemplari"] = esemplariNew->text();
        dati["meccanismo"] = meccanismoNew->currentText();
    }

    emit datiInseriti(dati["tipo"].toString(), dati);
    accept();
}

void AggiungiDialog::aggiungiAListaEsp() {
    QString nuovaEsposizione = nuovaEsposizioneInput->text().trimmed();
    if (!nuovaEsposizione.isEmpty()) {
        for (int i = 0; i < eList->count(); ++i) {
            if (eList->item(i)->text().isEmpty()) {
                delete eList->takeItem(i);
                i--;
            }
        }
        eList->addItem(nuovaEsposizione);
        nuovaEsposizioneInput->clear();
    }else QMessageBox::information(this, "Esposizione Nulla","Stai cercando di inserire una stringa vuota!");
}

void AggiungiDialog::togliDaListaEsp() {
    QListWidgetItem* selectedItem = eList->currentItem();
    if (selectedItem) {
        delete selectedItem;
    }
}

void AggiungiDialog::aggiungiAListaMat() {
    QString nuovoMateriale = nuovoMaterialeInput->text().trimmed();
    if (!nuovoMateriale.isEmpty()) {
        for (int i = 0; i < mList->count(); ++i) {
            if (mList->item(i)->text().isEmpty()) {
                delete mList->takeItem(i);
                i--;
            }
        }

        mList->addItem(nuovoMateriale);
        nuovoMaterialeInput->clear();
    }else QMessageBox::information(this, "Materiale Nullo","Stai cercando di inserire una stringa vuota!");
}

void AggiungiDialog::togliDaListaMat() {

    QListWidgetItem* selectedItem = mList->currentItem();
    if (selectedItem) {
        delete selectedItem;
    }
}
