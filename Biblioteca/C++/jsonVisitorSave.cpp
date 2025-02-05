#include "headers/jsonVisitorSave.h"
#include <string>
#include <QString>
#include <sstream>
#include <iterator>
#include <algorithm>

void jsonVisitorSave::visitArte(arte& a) {
    QJsonObject obj;
    obj["tipo"] = "arte";
    obj["nome"] = QString::fromStdString(a.getNome());
    obj["descrizione"] = QString::fromStdString(a.getDescrizione());
    obj["autentica"] = QString::fromStdString(a.getAutentica());
    obj["data creazione"] = QString::fromStdString(a.getDataCreazione());
    obj["valore"] = QString::fromStdString(std::to_string(a.getValAtt()));
    obj["preferiti"] = QString::fromStdString(std::to_string(a.getPreferiti()));
    obj["id"] = QString::fromStdString(a.getId());
    obj["artista"] = QString::fromStdString(a.getArtista());
    obj["tipo opera"] = QString::fromStdString(a.getTipoOpera());
    obj["artista vivo"] = QString::fromStdString(std::to_string(a.getVivo()));
    std::string result;
    for (auto it = a.getEspo().begin(); it!=a.getEspo().end(); it++) {
        result += *it;
        result+=" ";
    }
    result+=";";
    obj["esposizioni"] = QString::fromStdString(result);  // Lista di stringhe

    arrayJ.append(obj);
}

void jsonVisitorSave::visitOrologi(orologi& o) {
    QJsonObject obj;
    obj["tipo"] = "orologi";
    obj["nome"] = QString::fromStdString(o.getNome());
    obj["descrizione"] = QString::fromStdString(o.getDescrizione());
    obj["autentica"] = QString::fromStdString(o.getAutentica());
    obj["data creazione"] = QString::fromStdString(o.getDataCreazione());
    obj["valore"] = QString::fromStdString(std::to_string(o.getValAtt()));
    obj["preferiti"] = QString::fromStdString(std::to_string(o.getPreferiti()));
    obj["id"] = QString::fromStdString(o.getId());
    obj["modello"] = QString::fromStdString(o.getModello());
    obj["marca"] = QString::fromStdString(o.getMarca());
    obj["numero esemplari"] = QString::fromStdString(std::to_string(o.getEsemplari()));
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
    obj["valore"] = QString::fromStdString(std::to_string(g.getValAtt()));
    obj["preferiti"] = QString::fromStdString(std::to_string(g.getPreferiti()));
    obj["id"] = QString::fromStdString(g.getId());
    obj["orafo"] = QString::fromStdString(g.getOrafo());
    std::string result2;
    for (auto it2 = g.getMateriali().begin(); it2 !=g.getMateriali().end(); it2++) {
        result2+= *it2;
        result2+=" ";
    }
    result2+=";";
    obj["materiali"] = QString::fromStdString(result2);
    arrayJ.append(obj);
}
