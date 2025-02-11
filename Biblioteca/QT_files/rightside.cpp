#include "headers/rightside.h"
#include "headers/modificadialog.h"
#include "headers/aggiungidialog.h"


rightside::rightside (leftside* left, QWidget *parent) :
QWidget(parent), left(left) {
    right = new QVBoxLayout(this);

    modifica = new QPushButton("Modifica item");
    elimina = new QPushButton("Elimina item");
    aggiungi = new QPushButton("Aggiungi item");
    infobox = new QVBoxLayout();
    imageDescLayout = new QHBoxLayout();
    imageLabel = new QLabel(this);
    descriptionLabel = new QLabel("", this);

    descriptionLabel->setAlignment(Qt::AlignLeft);
    descriptionLabel->setWordWrap(true);
    imageLabel->setAlignment(Qt::AlignRight);
    imageLabel->setScaledContents(true);
    imageDescLayout->addWidget(descriptionLabel, 1);
    imageDescLayout->addWidget(imageLabel, 2);
    descriptionLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    infobox->addLayout(imageDescLayout);
    right->addWidget(modifica);
    right->addWidget(elimina);
    right->addWidget(aggiungi);
    right->addLayout(infobox);

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

    connect(modifica, &QPushButton::clicked, this, &rightside::modificare);
    connect(aggiungi, &QPushButton::clicked, this, &rightside::aggiungere);
}

//metodo di update delle informazioni dell'oggetto
void rightside::updateInfo(biblioteca *selectedItem) {
    if (!selectedItem) {
        std::cerr << "Errore: oggetto selezionato nullo!" << std::endl;
        return;
    }
    QString descrizione;
    descriptionBuildVisitor visitor(descrizione);
    selectedItem->accetta(visitor);  // `oggetto` è un puntatore a `biblioteca`
    qDebug() << descrizione;   // Ora `descrizione` è già pronta

    currentItem = selectedItem;

    descriptionLabel->setText(visitor.descrizioneBuild);
    std::cout << "Descrizione aggiornata: " << selectedItem->getDescrizione() << std::endl;
}

//metodo di eliminazione
void rightside::eliminaItem() {
    if (currentItem) {
        emit eliminazione(QString::fromStdString(currentItem->getNome())); // Invio segnale a leftside
        currentItem = nullptr;
    } else {
        QMessageBox::warning(this, "Errore", "Nessun elemento selezionato da eliminare!");
    }
}

void rightside::svuotaDescrizione() {
    descriptionLabel->clear();
}


//metodo per modifica dell'elemento selezionato
void rightside::modificare() {
    if (!currentItem) {
        QMessageBox::warning(this, "Errore", "Nessun elemento selezionato per la modifica.");
        return;
    }

    // Apri finestra di modifica specifica per il tipo dell'oggetto
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
