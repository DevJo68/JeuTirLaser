#include "cible.h"

cible::cible(double x, double y, int rayon):
    d_x{x},d_y{y},d_rayon{rayon}
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

cible::~cible()
{
    //dtor
}
