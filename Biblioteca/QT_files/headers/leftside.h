#ifndef LEFTSIDE_H
#define LEFTSIDE_H

#include <QFileDialog>
#include <QMessageBox>
#include <QToolBar>
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
        std::vector<biblioteca*> oggetti;
        QString filtroAttivo;
        QToolBar *toolBar;
        QAction *salvaAzione;
        QAction* importa;

        void popolaLista();
        void saveToJson();
        void loadJson(const std::string& filePath);
        void importaLista();
    public:
        leftside(QWidget *parent = nullptr);

    public slots:
        //void addObj();
        //void removeObj();
        void filtraListaRicerca();
        void filtraPerCategoria(const QString &categoria, QPushButton *bottoneSelezionato);
        void salvaLista();

    signals : 
        void itemSelected(biblioteca *selectedItem);
};

#endif