#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include<string>
#include<stdio.h>
#include<vector>
#include<list>
#include"bibliotecaVisitorInterface.h"

class biblioteca {
    private:
        std::string nome;
        std::string descrizione;
        std::string autentica;
        int dataCreazione;
        double valore;
        bool preferiti;
    public:
        //costruttore e distruttore
        biblioteca(std::string n, std::string d, std::string a, 
        int dc, double v, bool p);
        virtual ~biblioteca()=0;

        //metodi getter
        std::string getNome() const;
        std::string getDescrizione() const;
        std::string getAutentica()const;
        int getDataCreazione()const;
        bool getPreferiti() const;
        double getValAtt() const;

        //metodi setter
        void setNome(const std::string);
        void setDescrizione(const std::string);
        void setAutentica(std::string);
        void setData(int);
        void setVal(double);
        void setPreferiti(bool);

        virtual void accetta(bibliotecaVisitorInterface& visitor) =0;
    };

#endif