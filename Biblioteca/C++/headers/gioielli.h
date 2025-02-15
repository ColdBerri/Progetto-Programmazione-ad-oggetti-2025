#ifndef GIOIELLI_H
#define GIOIELLI_H
#include<stdio.h>
#include"biblioteca.h"
#include<string>
#include<list>
#include<vector>
#include"bibliotecaVisitorInterface.h"
class gioielli : public biblioteca {
    private:
        std::list<std::string> materiali;
        std::string orafo;
    public:
        //costruttore e distruttore
        gioielli(std::string n, std::string d, std::string a, int dc,
        double vt, bool p,std::string image, std::list<std::string> ma, std::string ora);
        ~gioielli();

        //metodi getter
        std::list<std::string> getMateriali() const;
        std::string getOrafo() const;
        
        //metodi setter 
        void setMateriali(std::list<std::string>&);
        void setOrafo(const std::string);

        //accept
        void accetta(bibliotecaVisitorInterface& visitor) override;

};

#endif