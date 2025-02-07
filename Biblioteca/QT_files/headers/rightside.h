#ifndef RIGHTSIDE_H
#define RIGHTSIDE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QVector>
#include <iostream>
#include "libs.h"
#include "leftside.h"
#include "C++/headers/descriptionBuildVisitor.h"
#include "C++/headers/biblioteca.h"


class rightside : public QWidget {
    Q_OBJECT

    private:
private:
    biblioteca* currentItem = nullptr;
    QVBoxLayout *right;
    QPushButton *modifica;
    QPushButton *elimina;
    QPushButton *aggiungi;
    QVBoxLayout *infobox;
    QHBoxLayout *imageDescLayout;  // Layout orizzontale per immagine e descrizione
    QLabel *imageLabel;            // QLabel per l'immagine
    QLabel *descriptionLabel;      // QLabel per la descrizione
    leftside *left;
    void eliminaItem();
public:
    rightside(leftside *left, QWidget *parent = nullptr);

    public slots:
    void updateInfo(biblioteca *selectedItem);
    signals:
        void itemToDelete(const QString& itemName);
        void eliminazione(const QString& nomeElemento);
};

#endif