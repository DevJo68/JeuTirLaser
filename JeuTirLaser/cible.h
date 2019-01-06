#ifndef CIBLE_H
#define CIBLE_H

#include "point.h"

class cible
{
    public:

        cible(const geom::point& p1, const geom::point& p2, int rayon);
        double cibleX() const;
        double cibleY() const;
        int cibleRayon() const;

    private:
        double d_x;
        double d_y;
        int d_rayon;
};

#endif // CIBLE_H
