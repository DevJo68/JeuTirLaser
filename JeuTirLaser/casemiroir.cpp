#include "casemiroir.h"

caseMiroir::caseMiroir(geom::point p1, geom::point p2, miroir *m):
    Case{p1,p2},d_miroir{m}
{}

miroir* caseMiroir::getMiroir() const{
  return d_miroir;
}

void caseMiroir::print() const{
  dessinateur d{};
  d.dessinateurCaseMiroir(coinSupG().x(),coinSupG().y(),coinInfD().x(),coinInfD().y());
}

