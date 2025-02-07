#ifndef DESCRIPTIONBUILDVISITOR_H
#define DESCRIPTIONBUILDVISITOR_H
#include <QString>
#include"biblioteca.h"
#include"gioielli.h"
#include"arte.h"
#include"orologi.h"
class descriptionBuildVisitor : public bibliotecaVisitorInterface {
public:
    QString descrizioneBuild;
    explicit descriptionBuildVisitor(QString& desc) : descrizioneBuild(desc) {}

    void visitOrologi(orologi& oro) override;
    void visitArte(arte& art) override;
    void visitGioielli(gioielli& gio) override;
};

#endif //DESCRIPTIONBUILDVISITOR_H
