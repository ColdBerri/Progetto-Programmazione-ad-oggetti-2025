#include "headers/rightside.h"

rightside::rightside (/*content* contenuti,*/ leftside* left, QWidget *parent) : 
QWidget(parent), /*contenuti(contenuti),*/ left(left) {
    right = new QVBoxLayout(this);

    modifica = new QPushButton("Modifica item");
    elimina = new QPushButton("Elimina item");
    aggiungi = new QPushButton("Aggiungi item");

    right->addWidget(modifica);
    right->addWidget(elimina);
    right->addWidget(aggiungi);
    
    //connect
}

