#ifndef ARTE_H
#define ARTE_H
#include<stdio.h>
#include<vector>
#include<string>
#include"biblioteca.h"
//#include"../bibliotecaVisitorInterface.h"

class arte : public biblioteca{
    private:
        std::string artista;
        std::string tipoOpera;
        bool artistaVivo;
        std::list<std::string> esposizione;
    public:
        //costruttore e distruttore
        arte(std::string n, std::string d, std::string a, std::string dc, double v, bool p,
        std::string artista, std::string tipoOpera, bool artistaVivo, std::list<std::string> esposizione);
        ~arte();

        //metodi getter
        std::string getArtista()const;
        std::string getTipoOpera()const;
        bool getVivo() const;
        std::list<std::string> getEspo() const;
        //metodi setter
        void setArtista(const std::string);
        void setTipoOpera(const std::string);
        void setVivo(bool);
        void setEsposizione(const std::list<std::string>&);

        void accetta(bibliotecaVisitorInterface& visitor) override;
};

#endif