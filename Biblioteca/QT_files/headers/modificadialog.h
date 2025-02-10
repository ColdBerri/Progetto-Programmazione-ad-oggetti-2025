#ifndef MODIFICADIALOG_H
#define MODIFICADIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include "C++/headers/biblioteca.h"
#include "C++/headers/arte.h"
#include "C++/headers/gioielli.h"
#include "C++/headers/orologi.h"
#include "leftside.h"
class ModificaDialog : public QDialog {
    Q_OBJECT

public:
    explicit ModificaDialog(biblioteca *item, QWidget *parent = nullptr);

private:
    biblioteca *item;
    QLineEdit *nomeEdit;
    QLineEdit *descrizioneEdit;
    QLineEdit *autenticaEdit;
    QLineEdit *dataEdit;
    QLineEdit *valoreEdit;

    //modifiche solo per arte
    QLineEdit *artistaEdit;
    QRadioButton *bottoneSi; //vivo
    QRadioButton *bottoneNO;
    QComboBox *tipoOperaEdit;

    //serve sia ad arte che gioielli
    QListWidget *eList;
    QListWidget *mList;
    QLineEdit *nuovoMaterialeInput;
    QLineEdit *nuovaEsposizioneInput;
    QPushButton *emAddButton;
    QPushButton *emDelButton;

    //modifiche solo per gioielli
    QLineEdit *materialiEdit;
    QLineEdit *orafoEdit;

    //modifiche sollo per orologi
    QLineEdit *modelloEdit;
    QLineEdit *marcaEdit;
    QLineEdit *esemplariEdit;
    QComboBox *meccanismoEdit;

    QPushButton *salvaButton;
    QPushButton *annullaButton;

private slots:
    void salvaModifiche();
    void aggiungiAListaEsp();
    void aggiungiAListaMat();
    void togliDaListaEsp();
    void togliDaListaMat();


};

#endif // MODIFICADIALOG_H

