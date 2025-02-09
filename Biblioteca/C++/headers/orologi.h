#ifndef OROLOGI_H
#define OROLOGI_H
#include"biblioteca.h"
#include<stdio.h>
#include<vector>
#include<string>
#include"bibliotecaVisitorInterface.h"

class orologi : public biblioteca{
    private:
        std::string modello;
        std::string marca;
        int nEsemplari; //se non è numerato non appare
        std::string meccanismo;
    public:
        orologi(std::string n, std::string d, std::string a, std::string dc, 
        double v, bool p, std::string id, std::string mod,
        std::string ma, int ne, std::string tm);
        ~orologi();

        //getter
        std::string getModello() const;
        std::string getMarca() const;
        int getEsemplari() const;
        std::string getMecc()const;

        //setter
        void setModello(std::string);
        void setMarca(std::string);
        void setEsemplari(int);
        void setMecc(std::string);

        //acc
        void accetta(bibliotecaVisitorInterface& visitor) override; 

        
};
#endif