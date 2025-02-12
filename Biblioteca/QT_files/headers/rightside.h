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
    QHBoxLayout *imageDescLayout;
    QLabel *imageLabel;
    QLabel *descriptionLabel;
    QPushButton *preferitiButton;
    QHBoxLayout *preferitiLayout;
    leftside *left;
    void inviaDatiAggiunti(const QString &tipo, const QVariantMap &dati);
public:
    rightside(leftside *left, QWidget *parent = nullptr);

    public slots:
    void updateInfo(biblioteca *selectedItem);
    void svuotaDescrizione();
    void modificare();
    void aggiungere();

    signals:
		void itemPointed(const QString& itemName);
        void oggettoAggiunto(const QString &tipo, const QVariantMap &dati);
        void preferitoCambiato(bool);
};

#endif