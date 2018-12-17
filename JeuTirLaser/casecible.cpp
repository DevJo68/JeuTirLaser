#include "casecible.h"

caseCible::caseCible(geom::point p1, geom::point p2, cible *c):
    Case{p1,p2},d_cible{c}
{}

cible* caseCible::getCible() const{
  return d_cible;
}

void caseCible::print() const{
  dessinateur d{};
  d.dessinateurCaseCible(coinSupG().x(),coinSupG().y(),coinInfD().x(),coinInfD().y());
}

