#ifndef MONSTRE_H
#define MONSTRE_H

#include "point.h"
class monstre
{
    public:
        monstre(const geom::point& p1, const geom::point& p2, int rayon);
        double monstreX() const;
        double monstreY() const;
        int monstreRayon() const;

    private:
        double d_x;
        double d_y;
        int d_rayon;
};

#endif // MONSTRE_H
