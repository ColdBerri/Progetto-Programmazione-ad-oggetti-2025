#include "headers/arte.h"

//costruttore e edistruttore
arte::arte(std::string n, std::string d, std::string a, int dc, double v,
bool p, std::string ar, std::string to,
bool viv, std::list<std::string> esp) : biblioteca(n, d, a, dc, v, p), artista(ar), tipoOpera(to),
artistaVivo(viv), esposizione(esp) {}

arte::~arte(){}

//getter
std::string arte::getArtista() const{return artista;}
std::string arte::getTipoOpera() const {return tipoOpera;}
bool arte::getVivo() const {return artistaVivo;}
std::list<std::string> arte::getEspo() const {return esposizione;}

//setter
void arte::setArtista(const std::string a) {artista = a;}
void arte::setTipoOpera(const std::string to) {tipoOpera = to;}
void arte::setVivo(bool v) {artistaVivo = v;}

void arte::setEsposizione(const std::list<std::string>& es) {
    if(es.empty()) throw std::string("La lista è vuota");
    else if(!esposizione.empty()) {
        esposizione.clear();
        for(auto it = es.begin(); it!=es.end(); it++){
            esposizione.push_back(*it);
        }
    }else{
        for(auto it2 = es.begin(); it2 !=es.end(); it2++) {
            esposizione.push_back(*it2);
        } 
    }
}

//accetta
void arte::accetta(bibliotecaVisitorInterface& visitor) {
    visitor.visitArte(*this);
};
