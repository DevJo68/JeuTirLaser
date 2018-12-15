#ifndef CASEVIDE_H
#define CASEVIDE_H

#include "case.h"
#include "dessinateur.h"

class caseVide : public Case
{
    public:
        caseVide();
        caseVide(geom::point p1, geom::point p2);
        virtual void print() const override;

    protected:

    private:
};

#endif // CASEVIDE_H
