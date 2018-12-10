#ifndef MIROIR_H
#define MIROIR_H
#include "point.h"

class miroir
{
    public:
        miroir(geom::point pDepart , geom::point pArrivee);
        char inclinaison() const;
        geom::point depart() const;
        geom::point arrivee() const;
        void inclineG();
        void inclineD();
        void print() const;
        virtual ~miroir();

    protected:

    private:
        char d_inclinaison;
        geom::point d_depart;
        geom::point d_arrivee;
};

#endif // MIROIR_H
