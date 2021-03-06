#ifndef CASEMONSTRE_H
#define CASEMONSTRE_H

#include "case.h"
#include "monstre.h"

class caseMonstre : public Case{
    public:
        caseMonstre(const geom::point& p1, const geom::point& p2, monstre *m);
        virtual void print() const override;
        virtual int typeCase() override;

    private:
        monstre* d_monstre;

};

#endif // CASEMONSTRE_H
