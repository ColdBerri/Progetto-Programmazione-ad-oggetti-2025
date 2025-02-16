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
#include <QVariantMap>
#include "libs.h"
#include "C++/headers/biblioteca.h"
#include "C++/headers/jsonVisitorSave.h"
#include "../nlohmann/json.hpp"
#include <fstream>
class leftside : public QWidget {
    Q_OBJECT

    private:
        std::vector<biblioteca*> preferitiList;
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
        QString *jsonFilePath;
        QPushButton *bottonePreferiti;
        void popolaLista();
        void loadJson(const std::string& filePath);
        void importaLista();
        void deselezionaElemento();
        bool saveToJson();
        void checkName(biblioteca* );
    public:
        leftside(QWidget *parent = nullptr);

    public slots:
        void filtraListaRicerca();
        void filtraPerCategoria(const QString &categoria, QPushButton *bottoneSelezionato);
        void salvaLista();
        void rimuoviItem(const QString& itemName);
        void aggiornaItem(biblioteca* );
        void costruisciOggetto(const QString &tipo, const QVariantMap &dati);
    signals :
        void itemSelected(biblioteca *selectedItem);
        void elementoDeselezionato();
};

#endif
