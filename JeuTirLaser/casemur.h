#ifndef CASEMUR_H
#define CASEMUR_H

#include "case.h"
#include "mur.h"

class caseMur :public Case
{
    public:
        caseMur(geom::point p1, geom::point p2, mur *m);
        virtual void print() const override;
    protected:

    private:
        mur *d_mur;
};

#endif // CASEMUR_H

