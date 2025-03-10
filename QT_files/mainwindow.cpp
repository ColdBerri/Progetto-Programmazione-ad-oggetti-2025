#include "headers/mainwindow.h"

mainwindow::mainwindow(QWidget* parent) : QWidget(parent){
    setWindowTitle("Biblioteca del lusso");

    mainWind = new QHBoxLayout(this);
    split = new QSplitter(Qt::Horizontal, this);
    left = new leftside(this);
    right = new rightside(left, this);

    split->addWidget(left);
    split->addWidget(right);

    QList<int> sizes;
    sizes << 200 << 500 << 100;
    split->setSizes(sizes);

    mainWind->addWidget(split);
    connect(right, &rightside::itemPointed, left, &leftside::rimuoviItem);
    connect(right, &rightside::oggettoAggiunto, left, &leftside::costruisciOggetto);
    setLayout(mainWind);
}
    