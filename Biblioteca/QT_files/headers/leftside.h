#ifndef LEFTSIDE_H
#define LEFTSIDE_H

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
#include <QKeyEvent>
#include <iostream>
#include <QListWidget>
#include "libs.h"
#include "C++/headers/biblioteca.h"
#include "C++/headers/jsonVisitorSave.h"
#include <nlohmann/json.hpp>
#include <fstream>
class leftside : public QWidget {
    Q_OBJECT

    private:
        QVBoxLayout *left;
        QPushButton *bottoneArte;
        QPushButton *bottoneGioielli;
        QPushButton *bottoenOrologi;
        QLineEdit *ricerca;
        QListWidget *listaItems;
        QPushButton *add;
        std::vector<biblioteca*> oggetti;

        void popolaLista();
        void keyPressEvent(QKeyEvent *event)override;
        void saveToJson();
        void loadJson(nlohmann::json j);
    public:
        leftside(QWidget *parent = nullptr);

    public slots:
        //void ricercaOggetti(const QString &);
        //void selezionaTipoOggetto(const std::string tipo);
        void addObj();
        void removeObj();
    signals : 
        //void itemSelezionato(std::string id);
        //void tipoSelezionato(std::string tipo);
};

#endif