#include "QT_files/headers/mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include <QIcon>

int main(int argv, char** argc){
  QApplication BibliotecaDigitale(argv, argc);
  mainwindow finestra;
  finestra.resize(900,600);
  finestra.show();
  return BibliotecaDigitale.exec();
}
