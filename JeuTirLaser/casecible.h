#ifndef CASECIBLE_H
#define CASECIBLE_H

#include "point.h"
#include "cible.h"
#include "case.h"

class caseCible : public Case
{
    public:
        caseCible(geom::point p1, geom::point p2, cible *c);
        virtual void print() const override;
        virtual int typeCase() override;

    protected:

    private:
        cible *d_cible;
};

#endif // CASECIBLE_H
