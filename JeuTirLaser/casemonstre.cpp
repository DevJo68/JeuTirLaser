#include "casemonstre.h"

caseMonstre::caseMonstre(const geom::point& p1, const geom::point& p2, monstre *m):
    Case(p1,p2),d_monstre{m}
{}

void caseMonstre::print() const{
  d_dessinateur.dessinateurCaseMonstre(coinSupG().x(),coinSupG().y(),coinInfD().x(),coinInfD().y());
}

int caseMonstre::typeCase(){
  return 6;
}
