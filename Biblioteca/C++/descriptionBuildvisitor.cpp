#include "headers/descriptionBuildVisitor.h"
#include <sstream>
void descriptionBuildVisitor::visitArte(arte &art) {
    std::string result;
    std::list<std::string> lista = art.getEspo();
    for (auto it = lista.begin(); it != lista.end(); it++) {
        result += *it;
        if (std::next(it) != lista.end()) {
            result += ";";
        }
    }
    QString desc = QString ("🎨 <b>Opera d'Arte</b>: %1<br>"
                           "🔹 <b>Descrizione</b>: %2<br>"
                           "✅ <b>Autenticità</b>: %3<br>"
                           "📆 <b>Data Creazione</b>: %4<br>"
                           "💰 <b>Valore</b>: %5€<br>"
                           "🖌️ <b>Artista</b>: %8<br>"
                           "🏺 <b>Tipo Opera</b>: %9<br>"
                           "👨‍🎨 <b>Artista Vivo</b>: %10<br>"
                           "🏛️ <b>Esposizioni</b>: %11<br>")
            .arg(QString::fromStdString(art.getNome()))
            .arg(QString::fromStdString(art.getDescrizione()))
            .arg(QString::fromStdString(art.getAutentica()))
            .arg(QString::fromStdString(art.getDataCreazione()))
            .arg(art.getValAtt())
            .arg(QString::fromStdString(art.getArtista()))
            .arg(QString::fromStdString(art.getTipoOpera()))
            .arg(art.getVivo() ? "Sì" : "No")
            .arg(QString::fromStdString(result));
    descrizioneBuild = desc;
}

void descriptionBuildVisitor::visitGioielli(gioielli &gio) {
    std::string result;
    std::list<std::string> lista = gio.getMateriali();
    for (auto it = lista.begin(); it != lista.end(); it++) {
        result += *it;
        if (std::next(it) != lista.end()) { // Se non è l'ultimo elemento, aggiungi ";"
            result += ";";
        }
    }
    QString desc = QString ("📿 <b>Gioiello</b>: %1<br>"
                               "🔹 <b>Descrizione</b>: %2<br>"
                               "✅ <b>Autenticità</b>: %3<br>"
                               "📆 <b>Data Creazione</b>: %4<br>"
                               "💰 <b>Valore</b>: %5€<br>"
                               "🔗 <b>Materiali</b>: %8<br>"
                               "👨‍🎨 <b>Orafo</b>: %9<br>")
    .arg(QString::fromStdString(gio.getNome()))
    .arg(QString::fromStdString(gio.getDescrizione()))
    .arg(QString::fromStdString(gio.getAutentica()))
    .arg(QString::fromStdString(gio.getDataCreazione()))
    .arg(gio.getValAtt())
    .arg(QString::fromStdString(result))
    .arg(QString::fromStdString(gio.getOrafo()));
    descrizioneBuild = desc;
}

void descriptionBuildVisitor::visitOrologi(orologi &oro) {
    if (oro.getEsemplari() == 0) {
        QString desc = QString ("⌚ <b>Orologio</b>: %1<br>"
                           "🔹 <b>Descrizione</b>: %2<br>"
                           "✅ <b>Autenticità</b>: %3<br>"
                           "📆 <b>Data Creazione</b>: %4<br>"
                           "💰 <b>Valore</b>: %5€<br>"
                           "⌛ <b>Modello</b>: %8<br>"
                           "🏭 <b>Marca</b>: %9<br>"
                           "🔢 <b>Numero esemplari</b>: %10<br>"
                           "⚙️ <b>Meccanismo</b>: %11<br>")
        .arg(QString::fromStdString(oro.getNome()))
        .arg(QString::fromStdString(oro.getDescrizione()))
        .arg(QString::fromStdString(oro.getAutentica()))
        .arg(QString::fromStdString(oro.getDataCreazione()))
        .arg(oro.getValAtt())
        .arg(QString::fromStdString(oro.getModello()))
        .arg(QString::fromStdString(oro.getMarca()))
        .arg(QString::fromStdString("Numero esemplari non specificato"))
        .arg(QString::fromStdString(oro.getMecc()));
        descrizioneBuild = desc;
    }else {
        QString desc = QString ("⌚ <b>Orologio</b>: %1<br>"
                           "🔹 <b>Descrizione</b>: %2<br>"
                           "✅ <b>Autenticità</b>: %3<br>"
                           "📆 <b>Data Creazione</b>: %4<br>"
                           "💰 <b>Valore</b>: %5€<br>"
                           "⌛ <b>Modello</b>: %8<br>"
                           "🏭 <b>Marca</b>: %9<br>"
                           "🔢 <b>Numero esemplari</b>: %10<br>"
                           "⚙️ <b>Meccanismo</b>: %11<br>")
        .arg(QString::fromStdString(oro.getNome()))
        .arg(QString::fromStdString(oro.getDescrizione()))
        .arg(QString::fromStdString(oro.getAutentica()))
        .arg(QString::fromStdString(oro.getDataCreazione()))
        .arg(oro.getValAtt())
        .arg(QString::fromStdString(oro.getModello()))
        .arg(QString::fromStdString(oro.getMarca()))
        .arg(oro.getEsemplari())
        .arg(QString::fromStdString(oro.getMecc()));
        descrizioneBuild = desc;
    }

}

