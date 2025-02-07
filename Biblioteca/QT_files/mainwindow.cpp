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
    sizes << 175 << 500 << 100; // Dimensione leftSideBarWidget, contentWidget, rightSideBarWidget
    split->setSizes(sizes);

    mainWind->addWidget(split);
    connect(right, &rightside::itemToDelete, left, &leftside::rimuoviItem);

    setLayout(mainWind);
}
    