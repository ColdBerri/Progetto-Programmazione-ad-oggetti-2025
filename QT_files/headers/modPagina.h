#ifndef MODPAGINA_H
#define MODPAGINA_H

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
class modPagina : public QWidget {
    Q_OBJECT

public:
    explicit modPagina(biblioteca *item, QWidget *parent = nullptr);

private:
    biblioteca *item;
    QLineEdit *nomeEdit;
    QLineEdit *descrizioneEdit;
    QLineEdit *autenticaEdit;
    QLineEdit *dataEdit;
    QLineEdit *valoreEdit;
    QLineEdit *imageEdit;
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

signals:
	void confermaMod();
    void closeModPagina();
};

#endif //MODPAGINA_H
