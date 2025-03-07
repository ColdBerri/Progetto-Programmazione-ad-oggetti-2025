#include "headers/addPagina.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

addPagina::addPagina(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Aggiungi Elemento");
    setFixedSize(700,675);
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
    salvaButton->setEnabled(false);
    annullaButton = new QPushButton("Annulla", this);
    mainLayout->addWidget(salvaButton);
    mainLayout->addWidget(annullaButton);

    // Connessioni
    connect(bottoneArte, &QRadioButton::clicked, this, &addPagina::abilitaConferma);
    connect(bottoneGioielli, &QRadioButton::clicked, this, &addPagina::abilitaConferma);
    connect(bottoneOrologi, &QRadioButton::clicked, this, &addPagina::abilitaConferma);
    connect(confermaTipoButton, &QPushButton::clicked, this, &addPagina::confermaScelta);
    connect(confermaTipoButton, &QPushButton::clicked, this, [this]() {
        this->salvaButton->setEnabled(true);
    });
    connect(salvaButton, &QPushButton::clicked, this, &addPagina::salvaNuovo);
    connect(annullaButton, &QPushButton::clicked, this, &addPagina::closeAddPagina);
    pulisciForm();
}


void addPagina::abilitaConferma() {
    confermaTipoButton->setEnabled(true);
}

void addPagina::confermaScelta() {
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

void addPagina::aggiungiAListaEsp() {
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

void addPagina::togliDaListaEsp() {
    QListWidgetItem* selectedItem = eList->currentItem();
    if (selectedItem) {
        delete selectedItem;
    }
}

void addPagina::aggiungiAListaMat() {
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

void addPagina::togliDaListaMat() {

    QListWidgetItem* selectedItem = mList->currentItem();
    if (selectedItem) {
        delete selectedItem;
    }
}

// Cambiato il return type in void, visto che non utilizziamo il valore restituito.
void addPagina::mostraArte() {
    // Campi comuni
    nomeNew = new QLineEdit(this);
    descrizioneNew = new QLineEdit(this);
    valoreNew = new QLineEdit(this);
    autenticaNew = new QLineEdit(this);
    dataNew = new QLineEdit(this);
    imageNew = new QLineEdit(this);
    formLayout->addRow("Nome:", nomeNew);
    formLayout->addRow("Descrizione:", descrizioneNew);
    formLayout->addRow("Valore (€):", valoreNew);
    formLayout->addRow("Autentica:", autenticaNew);
    formLayout->addRow("Data della Creazione:", dataNew);
    formLayout->addRow("Percorso dell'immagine :\n(usare percorso completo\nsu linux e mac)", imageNew);
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
    connect(emAddButton, &QPushButton::clicked, this, &addPagina::aggiungiAListaEsp);
    connect(emDelButton, &QPushButton::clicked, this, &addPagina::togliDaListaEsp);

    formLayout->addRow("Artista:", artistaNew);
    formLayout->addRow("Artista Vivo:", radioWidget);
    formLayout->addRow("Tipo Opera:", tipoOperaEdit);
    formLayout->addRow("Esposizioni:", espLayout);
}

void addPagina::mostraGioielli() {
    // Campi comuni
    nomeNew = new QLineEdit(this);
    descrizioneNew = new QLineEdit(this);
    valoreNew = new QLineEdit(this);
    autenticaNew = new QLineEdit(this);
    dataNew = new QLineEdit(this);
    imageNew = new QLineEdit(this);
    formLayout->addRow("Nome:", nomeNew);
    formLayout->addRow("Descrizione:", descrizioneNew);
    formLayout->addRow("Valore (€):", valoreNew);
    formLayout->addRow("Autentica:", autenticaNew);
    formLayout->addRow("Data della Creazione:", dataNew);
    formLayout->addRow("Percorso dell'immagine :\n(usare percorso completo\nsu linux e mac)", imageNew);

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

    connect(emAddButton, &QPushButton::clicked, this, &addPagina::aggiungiAListaMat);
    connect(emDelButton, &QPushButton::clicked, this, &addPagina::togliDaListaMat);

    formLayout->addRow("Orafo:", orafoNew);
    formLayout->addRow("Materiali:", matLayout);
}

void addPagina::mostraOrologi() {
    // Campi comuni
    nomeNew = new QLineEdit(this);
    descrizioneNew = new QLineEdit(this);
    valoreNew = new QLineEdit(this);
    autenticaNew = new QLineEdit(this);
    dataNew = new QLineEdit(this);
    imageNew = new QLineEdit(this);
    formLayout->addRow("Nome:", nomeNew);
    formLayout->addRow("Descrizione:", descrizioneNew);
    formLayout->addRow("Valore (€):", valoreNew);
    formLayout->addRow("Autentica:", autenticaNew);
    formLayout->addRow("Data della Creazione:", dataNew);
    formLayout->addRow("Percorso dell'immagine :\n(usare percorso completo\nsu linux e mac)", imageNew);

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

void addPagina::pulisciForm() {
    QLayoutItem *item;
    while ((item = formLayout->takeAt(0)) != nullptr) {
        if(item->widget())
            delete item->widget();
        delete item;
    }
}

void addPagina::salvaNuovo() {
    QVariantMap dati;
    if (nomeNew->text().isEmpty()) {
        QMessageBox::warning(this, "Errore di Salvataggio",
                     "NON PUOI SALVARE UN OGGETTO SENZA NOME!");
        return;
    }

    dati["nome"] = nomeNew->text();
    dati["descrizione"] = descrizioneNew->text();
    dati["valore"] = valoreNew->text();
    dati["autentica"] = autenticaNew->text();
    dati["data"] = dataNew->text();
    dati["immagine"] = imageNew->text();
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
        if (materiali.empty()) {
            QMessageBox::warning(this, "Errore di Salvataggio",
            "Non puoi salvare un gioiello senza almeno un materiale!");
            return;
        }
    } else if (bottoneOrologi->isChecked()) {
        dati["tipo"] = "Orologi";
        dati["modello"] = modelloNew->text();
        dati["marca"] = marcaNew->text();
        dati["esemplari"] = esemplariNew->text();
        dati["meccanismo"] = meccanismoNew->currentText();
    }

    emit datiInseriti(dati["tipo"].toString(), dati);
    emit confermaAdd();
}