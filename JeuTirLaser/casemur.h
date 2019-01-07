#ifndef CASEMUR_H
#define CASEMUR_H

#include "case.h"
#include "mur.h"

class caseMur :public Case
{
    public:
        caseMur(const geom::point& p1, const geom::point& p2, mur *m);
        virtual void print() const override;
        virtual int typeCase() override;
    protected:

    private:
        mur *d_mur;
};

#endif // CASEMUR_H

