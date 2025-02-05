#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"leftside.h"
#include"rightside.h"
#include<QMainWindow>
#include<QWidget>
#include<QHBoxLayout>
#include<QSplitter>
#include "libs.h"
class mainwindow : public QWidget {
    Q_OBJECT

    private:
        QHBoxLayout *mainWind;
        QSplitter *split;
        leftside* left;
        rightside *right;
        //conent* content;
    public:
        explicit mainwindow(QWidget *parent = nullptr);
};

#endif