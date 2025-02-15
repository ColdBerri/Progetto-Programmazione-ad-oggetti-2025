#include "headers/biblioteca.h"

biblioteca::biblioteca(std::string n, std::string d, std::string a, int dc, double v, bool p, std::string image) :
nome(n), descrizione(d), autentica(a), dataCreazione(dc), valore(v), preferiti(p), image(image){}

biblioteca::~biblioteca(){}

//metodi getter
std::string biblioteca::getNome()const {return nome;}
std::string biblioteca::getDescrizione()const {return descrizione;}
std::string biblioteca::getAutentica() const {return autentica;}
int biblioteca::getDataCreazione()const {return dataCreazione;}
bool biblioteca::getPreferiti() const {return preferiti;}
double biblioteca::getValAtt() const {return valore;}
std::string biblioteca::getImage()const {return image;}
//metodi setter
void biblioteca::setNome(const std::string no){nome = no;}
void biblioteca::setDescrizione(const std::string de){descrizione = de;}
void biblioteca::setAutentica(std::string au){autentica = au;}
void biblioteca::setData(int data) {dataCreazione = data;}
void biblioteca::setVal(double va){valore = va;}
void biblioteca::setPreferiti(bool pre){preferiti = pre;}
void biblioteca::setImage(std::string image2) {image = image2;}
