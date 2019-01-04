#include "casemiroir.h"

caseMiroir::caseMiroir(const geom::point& p1, const geom::point& p2, miroir *m):
    Case{p1,p2},d_miroir{m}
{}

miroir* caseMiroir::getMiroir() const{
  return d_miroir;
}

void caseMiroir::print() const{
  d_dessinateur.dessinateurCaseMiroir(coinSupG().x(),coinSupG().y(),coinInfD().x(),coinInfD().y());
}

