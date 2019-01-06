#ifndef CASEVIDE_H
#define CASEVIDE_H

#include "case.h"


class caseVide : public Case
{
    public:
        caseVide();
        caseVide(const geom::point& p1,const geom::point& p2);
        virtual int  typeCase() override;
        virtual void print() const override;

    protected:

    private:
};

#endif // CASEVIDE_H
