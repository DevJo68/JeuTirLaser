#include "casemur.h"

caseMur::caseMur(const geom::point& p1, const geom::point& p2, mur *m):
    Case{p1,p2}, d_mur{m}
{}

void caseMur::print() const{
  d_dessinateur.dessinateurCaseMur(coinSupG().x(),coinSupG().y(),coinInfD().x(),coinInfD().y());
}

 int caseMur::typeCase(){
  return 4;
}


