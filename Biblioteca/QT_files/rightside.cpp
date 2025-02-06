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

    connect(left, &leftside::itemSelected, this, &rightside::updateInfo);
}

/*void rightside::removeObj(){
    QListWidgetItem *selezionato = listaItems->currentItem();
    if(!selezionato) return;

    int i = listaItems->row(selezionato);
    if (i>=0 && i<oggetti.size()){
        delete oggetti[i];
        oggetti.erase(oggetti.begin()+i);
        delete selezionato;
        saveToJson();
    }
}*/
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

    // Aggiorna la descrizione
    descriptionLabel->setText(QString::fromStdString(selectedItem->getDescrizione()));

    // (Non gestiamo l'immagine per ora)
    std::cout << "Descrizione aggiornata: " << selectedItem->getDescrizione() << std::endl;
}