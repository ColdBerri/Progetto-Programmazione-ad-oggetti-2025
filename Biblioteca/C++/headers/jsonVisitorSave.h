#ifndef JOSNVISITORSAVE_H
#define JSONVISITORSAVE_H
#include"bibliotecaVisitorInterface.h"
#include"orologi.h"
#include"arte.h"
#include"gioielli.h"
#include<QJsonObject>
#include<QJsonArray>

class jsonVisitorSave : public bibliotecaVisitorInterface{
    public :
        QJsonArray arrayJ;

        void visitArte(arte& a) override;
        void visitGioielli(gioielli& g) override;
        void visitOrologi(orologi& o) override;
};

#endif