#include "cible.h"

cible::cible(const geom::point& p1, const geom::point& p2, int rayon):
    d_x{(p1.x()+p2.x())/2},d_y{(p1.y()+p2.y())/2},d_rayon{rayon}
{}

 double cible::cibleX() const{
    return d_x;
 }

 double cible::cibleY() const{
    return d_y;
 }

 int cible::cibleRayon() const{
    return d_rayon;
  }

