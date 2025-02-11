#include "headers/jsonVisitorSave.h"
#include <string>
#include <QString>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <iostream>

void jsonVisitorSave::visitArte(arte& a) {
    QJsonObject obj;
    obj["tipo"] = "arte";
    obj["nome"] = QString::fromStdString(a.getNome());
    obj["descrizione"] = QString::fromStdString(a.getDescrizione());
    obj["autentica"] = QString::fromStdString(a.getAutentica());
    obj["data creazione"] = QString::fromStdString(a.getDataCreazione());
    obj["valore"] = a.getValAtt();
    obj["preferiti"] = a.getPreferiti();
    obj["artista"] = QString::fromStdString(a.getArtista());
    obj["tipo opera"] = QString::fromStdString(a.getTipoOpera());
    obj["artista vivo"] = a.getVivo();
    std::string result;
    std::list<std::string> lista = a.getEspo();
    for (auto it = lista.begin(); it != lista.end(); it++) {
        result += *it;
        if (std::next(it) != lista.end()) {
            result += ";";
        }
    }
    obj["esposizione"] = QString::fromStdString(result);
    arrayJ.append(obj);
}


void jsonVisitorSave::visitOrologi(orologi& o) {
    QJsonObject obj;
    obj["tipo"] = "orologi";
    obj["nome"] = QString::fromStdString(o.getNome());
    obj["descrizione"] = QString::fromStdString(o.getDescrizione());
    obj["autentica"] = QString::fromStdString(o.getAutentica());
    obj["data creazione"] = QString::fromStdString(o.getDataCreazione());
    obj["valore"] = o.getValAtt();
    obj["preferiti"] =  o.getPreferiti();
    obj["modello"] = QString::fromStdString(o.getModello());
    obj["marca"] = QString::fromStdString(o.getMarca());
    obj["numero esemplari"] = o.getEsemplari();
    obj["meccanismo"] = QString::fromStdString(o.getMecc());
    arrayJ.append(obj);
}

void jsonVisitorSave::visitGioielli(gioielli& g) {
    QJsonObject obj;
    obj["tipo"] = "gioielli";
    obj["nome"] = QString::fromStdString(g.getNome());
    obj["descrizione"] = QString::fromStdString(g.getDescrizione());
    obj["autentica"] = QString::fromStdString(g.getAutentica());
    obj["data creazione"] = QString::fromStdString(g.getDataCreazione());
    obj["valore"] = g.getValAtt();
    obj["preferiti"] =  g.getPreferiti();
    std::string result;
    std::list<std::string> lista = g.getMateriali();
    for (auto it = lista.begin(); it != lista.end(); it++) {
        result += *it;
        if (std::next(it) != lista.end()) { // Se non è l'ultimo elemento, aggiungi ";"
            result += ";";
        }
    }
    obj["materiali"] = QString::fromStdString(result);
    obj["orafo"] = QString::fromStdString(g.getOrafo());
    arrayJ.append(obj);
}
