//
// Created by BRN on 07/03/25.
//

#ifndef ADDPAGINA_H
#define ADDPAGINA_H
#include <QVariantMap>
#include <QRadioButton>
#include <QButtonGroup>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QListWidget>
#include <QFormLayout>

class addPagina : public QWidget {
    Q_OBJECT
    private:
    // Bottoni per la scelta del tipo
    QRadioButton *bottoneArte;
    QRadioButton *bottoneGioielli;
    QRadioButton *bottoneOrologi;
    QButtonGroup *tipoGroup;
    QPushButton *confermaTipoButton;

    // Layout e widget del form di input (residenza per i campi dinamici)
    QWidget *formWidget;
    QFormLayout *formLayout;

    // Bottoni finali
    QPushButton *salvaButton;
    QPushButton *annullaButton;

    // Campi comuni
    QLineEdit *nomeNew;
    QLineEdit *descrizioneNew;
    QLineEdit *valoreNew;
    QLineEdit *autenticaNew;
    QLineEdit *dataNew;
    QLineEdit *imageNew;
    // Campi per "Arte"
    QLineEdit *artistaNew;
    QRadioButton *bottoneSi;
    QRadioButton *bottoneNO;
    QComboBox *tipoOperaEdit;
    QListWidget *eList;
    QLineEdit *nuovaEsposizioneInput;
    QPushButton *emAddButton;
    QPushButton *emDelButton;

    // Campi per "Gioielli"
    QLineEdit *orafoNew;
    QListWidget *mList;
    QLineEdit *nuovoMaterialeInput;
    // I bottoni per aggiungere/rimuovere materiale sono già dichiarati (riutilizziamo emAddButton ed emDelButton se non servono entrambi)

    // Campi per "Orologi"
    QLineEdit *modelloNew;
    QLineEdit *marcaNew;
    QLineEdit *esemplariNew;
    QComboBox *meccanismoNew;

public:
    explicit addPagina(QWidget *parent = nullptr);

    signals:
        void datiInseriti(const QString &tipo, const QVariantMap &dati);
        void closeAddPagina();
        void confermaAdd();
    private slots:
        void abilitaConferma();
        void confermaScelta();
        void salvaNuovo();
    // Metodi per gestire eventuali aggiunte/rimozioni nella lista
        void aggiungiAListaEsp();
        void togliDaListaEsp();
        void aggiungiAListaMat();
        void togliDaListaMat();
        void mostraArte();
        void mostraGioielli();
        void mostraOrologi();
        void pulisciForm();

};
#endif //ADDPAGINA_H
