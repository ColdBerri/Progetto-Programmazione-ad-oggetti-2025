#include "headers/orologi.h"

orologi::orologi(std::string n, std::string d, std::string a, std::string dc, 
double v, bool p, std::string id, std::string mod,
std::string ma, int ne, std::string tm) : biblioteca(n, d, a, dc, v, p, id), modello(mod),
marca(ma), nEsemplari(ne), meccanismo(tm) {}

orologi::~orologi() {}

//getter
std::string orologi::getModello() const {return modello;}
std::string orologi::getMarca() const {return marca;}
int orologi::getEsemplari() const {return nEsemplari;}
std::string orologi::getMecc() const {return meccanismo;}

//setter
void orologi::setModdello(std::string m) {modello = m;}
void orologi::setMarca(std::string ma) {marca = ma;}
void orologi::setEsemplari(int i) {nEsemplari = i;}
void orologi::setMecc(std::string me) {meccanismo = me;}

//acce
void orologi::accetta(bibliotecaVisitorInterface& visitor) {
    visitor.visitOrologi(*this);
};
