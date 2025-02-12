#include "headers/rightside.h"
#include "headers/modificadialog.h"
#include "headers/aggiungidialog.h"


rightside::rightside (leftside* left, QWidget *parent) :
QWidget(parent), left(left) {
    right = new QVBoxLayout(this);

    modifica = new QPushButton("Modifica item");
    modifica->setFixedSize(250,30);
    elimina = new QPushButton("Elimina item");
    elimina->setFixedSize(250,30);
    aggiungi = new QPushButton("Aggiungi item");
    aggiungi->setFixedSize(250,30);
    infobox = new QVBoxLayout();
    imageDescLayout = new QHBoxLayout();
    imageLabel = new QLabel(this);
    descriptionLabel = new QLabel("", this);
    preferitiButton = new QPushButton(this);
    preferitiLayout = new QHBoxLayout();
    preferitiLayout->addStretch();
    preferitiButton->setCheckable(true);
    preferitiButton->setIcon(QIcon(":/QT_files/assets/vuota.png"));
    preferitiButton->setIconSize(QSize(30, 30));
    descriptionLabel->setAlignment(Qt::AlignLeft);
    descriptionLabel->setWordWrap(true);
    imageLabel->setAlignment(Qt::AlignRight);
    imageDescLayout->addWidget(descriptionLabel, 1);
    imageDescLayout->addWidget(imageLabel, 2);
    descriptionLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    preferitiLayout->addWidget(preferitiButton);
    infobox->addLayout(imageDescLayout);
    right->addWidget(modifica);
    right->addWidget(elimina);
    right->addWidget(aggiungi);
    right->addLayout(infobox);
    right->addLayout(preferitiLayout);
    setLayout(right);

    //connect per fare update delle info dell'elemnto selezionato e per svuotare quando deselezionato
    connect(left, &leftside::itemSelected, this, &rightside::updateInfo);
    connect(left, &leftside::elementoDeselezionato, this, &rightside::svuotaDescrizione);

    //connect per elimina
    connect(left, &leftside::elementoDeselezionato, this, [this]() {
        currentItem = nullptr;
    });
    connect(elimina, &QPushButton::clicked, this, [this]() {
        if (currentItem) {
            emit itemPointed(QString::fromStdString(currentItem->getNome()));
            currentItem = nullptr;
            svuotaDescrizione();
        } else {
            QMessageBox::warning(this, "Errore", "Nessun elemento selezionato da eliminare.");
        }
    });

    connect(preferitiButton, &QPushButton::toggled, this, [this](bool checked) {
    // Aggiorna l'attributo "preferiti" dell'oggetto corrente (se presente)
    if (currentItem) {
        currentItem->setPreferiti(checked);
    }

    // Aggiorna l'icona in base allo stato
    if (checked) {
        preferitiButton->setIcon(QIcon(":/QT_files/assets/piena.png"));
    } else {
        preferitiButton->setIcon(QIcon(":/QT_files/assets/vuota.png"));
    }

    // Se necessario, emetti il segnale per notificare il cambiamento
    emit preferitoCambiato(checked);
});

    //connect modifca e aggiungi
    connect(modifica, &QPushButton::clicked, this, &rightside::modificare);
    connect(aggiungi, &QPushButton::clicked, this, &rightside::aggiungere);

}

//metodo di update delle informazioni dell'oggetto
void rightside::updateInfo(biblioteca *selectedItem) {
    if (!selectedItem) {
        std::cerr << "Errore: oggetto selezionato nullo!" << std::endl;
        return;
    } else {
        preferitiButton->setEnabled(true);
        QString descrizione;
        descriptionBuildVisitor visitor(descrizione);
        selectedItem->accetta(visitor);  // L'oggetto accetta il visitor
        qDebug() << descrizione;   // Ora `descrizione` è già pronta

        descriptionLabel->setText(visitor.descrizioneBuild);
        std::cout << "Descrizione aggiornata: " << selectedItem->getDescrizione() << std::endl;

        if (dynamic_cast<orologi*>(selectedItem)) {
            QPixmap pixmap(":/QT_files/assets/polso.png");
            QPixmap scaledMap = pixmap.scaled(200, 200, Qt::KeepAspectRatio);
            imageLabel->setPixmap(scaledMap);
            imageLabel->setScaledContents(true);
        } else if(dynamic_cast<arte*>(selectedItem)) {
            QPixmap pixmap(":/QT_files/assets/quadro.png");
            QPixmap scaledMap = pixmap.scaled(200, 200, Qt::KeepAspectRatio);
            imageLabel->setPixmap(scaledMap);
            imageLabel->setScaledContents(true);
        } else if(dynamic_cast<gioielli*>(selectedItem)) {
            QPixmap pixmap(":/QT_files/assets/anello.png");
            QPixmap scaledMap = pixmap.scaled(200, 200, Qt::KeepAspectRatio);
            imageLabel->setPixmap(scaledMap);
            imageLabel->setScaledContents(true);
        }
        currentItem = selectedItem;

        // Imposta lo stato del preferitiButton in base all'attributo "preferiti"
        bool isPreferito = currentItem->getPreferiti();
        preferitiButton->blockSignals(true);  // Blocca temporaneamente i segnali per evitare trigger indesiderati
        preferitiButton->setChecked(isPreferito);
        if (isPreferito) {
            preferitiButton->setIcon(QIcon(":/QT_files/assets/piena.png"));
        } else {
            preferitiButton->setIcon(QIcon(":/QT_files/assets/vuota.png"));
        }
        preferitiButton->blockSignals(false);
    }
}


void rightside::svuotaDescrizione() {
    descriptionLabel->clear();
    imageLabel->clear();
}

//metodo per modifica dell'elemento selezionato
void rightside::modificare() {
    if (!currentItem) {
        QMessageBox::warning(this, "Errore", "Nessun elemento selezionato per la modifica.");
        return;
    }

    ModificaDialog dialog(currentItem, this);
    if (dialog.exec() == QDialog::Accepted) {
        updateInfo(currentItem);
        left->aggiornaItem(currentItem);
    }
}

void rightside::aggiungere() {
    AggiungiDialog *dialog = new AggiungiDialog(this);
    connect(dialog, &AggiungiDialog::datiInseriti, this, &rightside::inviaDatiAggiunti);
    dialog->exec();
}

void rightside::inviaDatiAggiunti(const QString &tipo, const QVariantMap &dati) {
    emit oggettoAggiunto(tipo, dati);
}

