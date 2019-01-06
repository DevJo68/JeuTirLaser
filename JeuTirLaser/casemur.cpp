#include "casemur.h"


caseMur::caseMur(geom::point p1, geom::point p2, mur *m):
    Case{p1,p2}, d_mur{m}
{}

void caseMur::print() const{
  d_dessinateur.dessinateurCaseMur(coinSupG().x(),coinSupG().y(),coinInfD().x(),coinInfD().y());
}

virtual int typeCase() override{
 return 4;
}


