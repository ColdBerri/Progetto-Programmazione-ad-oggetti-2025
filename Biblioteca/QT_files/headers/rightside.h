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
class rightside : public QWidget {
    Q_OBJECT

    private:
        QVBoxLayout *right;
        QPushButton *modifica;
        QPushButton *elimina;
        QPushButton *aggiungi;
        QVBoxLayout *infobox;
        //content *contenuti;
        leftside *left;
    public:
        rightside(/*content* contenuti,*/ leftside *left, QWidget *parent = nullptr);
        
    public slots:
        //void modificaItem();
        //void eliminaItem();
        //void aggiungiItem();
    signals:

};

#endif