#include "headers/leftside.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <list>

leftside::leftside(/*content* contWidget,*/ QWidget *parent) : QWidget(parent){
    left = new QVBoxLayout(this);
    //this->contWidget = contWidget;

    bottoneArte = new QPushButton("ARTE");
    bottoenOrologi = new QPushButton("OROLOGI");
    bottoneGioielli = new QPushButton("GIOIELLI");
    ricerca = new QLineEdit();
    ricerca->setPlaceholderText("Search...");
    listaItems = new QListWidget(this);
    add = new QPushButton("aggiungi oggetto", this);

    left->addWidget(ricerca);
    left->addWidget(bottoneArte);
    left->addWidget(bottoenOrologi);
    left->addWidget(bottoneGioielli);
    left->addWidget(listaItems);
    left->addWidget(add);


    connect(add, &QPushButton::clicked, this, &leftside::addObj);

    //loadJson();
    popolaLista();
} 

/*void leftside::removeObj(){
    QListWidgetItem *selezionato = listaItems->currentItem();
    if(!selezionato) return;

    int i = listaItems->row(selezionato);
    if (i>=0 && i<oggetti.size()){
        delete oggetti[i];
        oggetti.erase(oggetti.begin()+i);
        delete selezionato;
        saveToJson();
    } 
}*/

void leftside::saveToJson(){
    jsonVisitorSave visitor;
    for(biblioteca* obj : oggetti) obj->accetta(visitor);

    QFile file("dati.json");
    if(file.open(QIODevice::WriteOnly)){
        file.write(QJsonDocument(visitor.arrayJ).toJson());
        file.close();
    }
}

void leftside::loadJson(nlohmann::json j) {
    // Se il JSON è nullo, carica dal file
    if (j.is_null()) {
        std::ifstream file("dati.json");
        if (!file.is_open()) return;

        file >> j;  // Carica il JSON nel parametro 'j'
        file.close();
    }

    if (!j.is_array()) return;  // Verifica che il JSON sia un array

    oggetti.clear();  // Pulisce la lista degli oggetti esistenti

    // Itera su ogni oggetto JSON
    for (const auto& jsonObj : j) {
        if (!jsonObj.contains("tipo")) continue;  // Ignora se il tipo non è presente

        std::string type = jsonObj["tipo"];

        // Crea gli oggetti in base al tipo
        if (type == "gioielli") {
            const auto& item = j[0]; // Assume che ci sia almeno un elemento
            double v = item["value"].get<double>();
            std::list<std::string> ma;
            std::istringstream iss(item["materiali"].get<std::string>());
            std::string word;
            while (iss >> word) {
                ma.push_back(word);
            }
            biblioteca *g = new gioielli(item["nome"], item["descrizione"], item["autentica"], item["data creazione"],
            v, item["preferiti"], item["id"], ma, item["orafo"]);
            oggetti.push_back(g);  // Aggiungi all'elenco degli oggetti
        }
        else if (type == "orologi") {
            const auto& item = j[0]; // Assume che ci sia almeno un elemento
            double v = item["valore"].get<double>();
            int ne = item["numero elementi"].get<int>();

            biblioteca *o = new orologi(item["nome"], item["descrizione"], item["autentica"], item["data creazione"],
                           v, item["preferiti"], item["id"], item["modello"],
                           item["marca"], ne, item["meccanismo"]);
            oggetti.push_back(o);  // Aggiungi all'elenco degli oggetti
        }
        else if (type == "arte") {
            const auto& item = j[0];
            double v = item["valore"].get<double>();
            std::list<std::string> esp;
            std::istringstream iss(item["esposizioni"].get<std::string>());
            std::string word;
            while (iss >> word) {
                esp.push_back(word);
            }
           biblioteca *a = new arte(item["nome"], item["descrizione"], item["autentica"], item["data creazione"],
                        v, item["preferiti"], item["id"], item["artista"],
                        item["tipo opera"], item["artista vivo"], esp);

           oggetti.push_back(a);
        }
              // Aggiungi all'elenco degli oggetti
    }
    popolaLista();  // Aggiorna la lista visualizzata
}



void leftside::addObj(){
  return;
}

void leftside::popolaLista(){
    /*listaItems->clear();
    for(biblioteca* obj : oggetti) listaItems->addObj(obj->getNome());
     */
    return;
}

void leftside::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Delete) removeObj();
}