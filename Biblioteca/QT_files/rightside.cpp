#include "headers/rightside.h"

rightside::rightside (/*content* contenuti,*/ leftside* left, QWidget *parent) :
QWidget(parent), /*contenuti(contenuti),*/ left(left) {
    right = new QVBoxLayout(this);

    modifica = new QPushButton("Modifica item");
    elimina = new QPushButton("Elimina item");
    aggiungi = new QPushButton("Aggiungi item");
    infobox = new QVBoxLayout();
    imageDescLayout = new QHBoxLayout();
    // Creazione QLabel per l'immagine
    imageLabel = new QLabel(this);
    /*QPixmap pixmap("");
    // Cambia con il percorso della tua immagine
    imageLabel->setPixmap(pixmap);
    imageLabel->setFixedSize(200, 200);  */ // Imposta la dimensione dell'immagine

    // Creazione QLabel per la descrizione
    descriptionLabel = new QLabel("Questa è la descrizione dell'immagine.", this);
    descriptionLabel->setWordWrap(true);  // Consente al testo di andare a capo

    // Aggiungi i QLabel al layout orizzontale
    imageDescLayout->addWidget(imageLabel);
    imageDescLayout->addWidget(descriptionLabel);


    infobox->addLayout(imageDescLayout);
    right->addWidget(modifica);
    right->addWidget(elimina);
    right->addWidget(aggiungi);
    right->addLayout(infobox);

    setLayout(right);

    //connect per fare update delle info dell'elemnto selezionato
    connect(left, &leftside::itemSelected, this, &rightside::updateInfo);

    //connect per elimina
    connect(elimina, &QPushButton::clicked, this, [this]() {
        if (currentItem) { // Supponiamo che `currentItem` sia un membro di `rightside` aggiornato con `updateInfo()`
            emit itemToDelete(QString::fromStdString(currentItem->getNome()));
        } else {
            QMessageBox::warning(this, "Errore", "Nessun elemento selezionato da eliminare.");
        }
    });

}

/*void rightside::updateInfo(biblioteca *selectedItem) {
    // Aggiorna la descrizione
    descriptionLabel->setText(QString::fromStdString(selectedItem->getDescrizione()));

    // Seleziona l'immagine (se esiste) associata all'oggetto
    QPixmap pixmap("/path/to/image/directory/" + QString::fromStdString(selectedItem->getNome()) + ".jpg");
    imageLabel->setPixmap(pixmap.scaled(imageLabel->size(), Qt::KeepAspectRatio));
}*/

void rightside::updateInfo(biblioteca *selectedItem) {
    if (!selectedItem) {
        std::cerr << "Errore: oggetto selezionato nullo!" << std::endl;
        return;
    }
    currentItem = selectedItem;
    descriptionLabel->setText(QString::fromStdString(selectedItem->getDescrizione()));
    std::cout << "Descrizione aggiornata: " << selectedItem->getDescrizione() << std::endl;
}

void rightside::eliminaItem() {
    if (currentItem) {
        emit eliminazione(QString::fromStdString(currentItem->getNome())); // Invio segnale a leftside
        currentItem = nullptr;
    } else {
        QMessageBox::warning(this, "Errore", "Nessun elemento selezionato da eliminare!");
    }
}
