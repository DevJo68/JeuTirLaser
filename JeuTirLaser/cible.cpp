#include "cible.h"

cible::cible(int x, int y, int rayon):
    d_x{x},d_y{y},d_rayon{rayon}
{}

 int cible::cibleX() const{
    return d_x;
 }

 int cible::cibleY() const{
    return d_y;
 }

 int cible::cibleRayon() const{
    return d_rayon;
  }


 void cible::print() const{

 }
cible::~cible()
{
    //dtor
}
