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
        std::string dataCreazione;
        double valore;
        bool preferiti;
        std::string id;
    public:
        //costruttore e distruttore
        biblioteca(std::string n, std::string d, std::string a, 
        std::string dc, double v, bool p, std::string id);
        virtual ~biblioteca();

        //metodi getter
        std::string getNome() const;
        std::string getDescrizione() const;
        std::string getAutentica()const;
        std::string getDataCreazione()const;
        bool getPreferiti() const;
        double getValAtt() const;
        std::string getId() const;

        //metodi setter
        void setNome(const std::string);
        void setDescrizione(const std::string);
        void setAutentica(std::string);
        void setData(std::string);
        void setVal(double);
        void setPreferiti(bool);
        void setId(std::string);

        //metodi virtuali puri
        //virtual double calcolaVarValore(biblioteca&)=0;
        //virtual std::string calcolaId(biblioteca&)=0;
        //virtual void aggiornaValore(double)=0;
        virtual void accetta(bibliotecaVisitorInterface& visitor) =0;
    };

#endif