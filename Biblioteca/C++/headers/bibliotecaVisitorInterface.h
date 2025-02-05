#ifndef BIBLIOTECAVISITORINTERFACE_H
#define BIBLIOTECAVISITORINTERFACE_H
#include<QWidget>

class orologi;
class arte;
class gioielli;


class bibliotecaVisitorInterface {
    public:
        virtual ~bibliotecaVisitorInterface()= default;
        virtual void visitOrologi(orologi& orologio)=0;
        virtual void visitArte(arte& opera)=0;
        virtual void visitGioielli(gioielli& gioiello)=0;

};

#endif