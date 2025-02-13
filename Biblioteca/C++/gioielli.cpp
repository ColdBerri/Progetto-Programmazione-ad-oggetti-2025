#include "headers/gioielli.h"

gioielli::gioielli(std::string n, std::string d, std::string a, int dc,
double vt, bool p, std::list<std::string> ma, std::string ora) :
biblioteca(n, d, a, dc, vt, p), materiali(ma), orafo(ora) {}

gioielli::~gioielli(){}

//metodi getter
std::list<std::string> gioielli::getMateriali() const {return materiali;}
std::string gioielli::getOrafo() const{return orafo;}
//std::list<gioielli::pietra*> gioielli::getPietre() const {return pietre;}

//metodi setter
void gioielli::setMateriali(std::list<std::string>& mat){
    if(mat.empty()) throw std::string("La lista dei materiali è vuota");
    else if (!materiali.empty()) {
        materiali.clear();
        for (auto itm = mat.begin(); itm != mat.end(); itm++){
            materiali.push_back(*itm);
        }
    }else{
        for(auto it = mat.begin(); it != mat.end(); it++){
            materiali.push_back(*it);
        }
    }
}
void gioielli::setOrafo(const std::string oraf) {orafo = oraf;}

//accetta
void gioielli::accetta(bibliotecaVisitorInterface& visitor) {
    visitor.visitGioielli(*this);
};


/*
metodi pietre
void gioielli::setPietre(std::list<gioielli::pietra*>& pi) {
    if(pi.empty()) throw std::string("La lista delle pietre è vuota");
    else if(!pietre.empty()){
        pietre.clear();
        for(auto it = pi.begin(); it!=pi.end(); it++){
            pietre.push_back(*it);
        }
    }else{
        for(auto it2 = pi.begin(); it2!=pi.end(); it2++){
            pietre.push_back(*it2);
        }
    }

}

void gioielli::addPietra(gioielli::pietra& p){
    pietre.push_back(&p);
}

void gioielli::removePietra(gioielli::pietra& p){
    for(auto it = pietre.begin(); it!=pietre.end(); i++){
        if(p.)
    }
}*/