#include "casevide.h"

caseVide::caseVide():
    Case()
{}

caseVide::caseVide(geom::point p1, geom::point p2):
    Case(p1,p2)
{}

 void caseVide::print() const{
    d_dessinateur.dessinateurCaseVide(coinSupG().x(),coinSupG().y(),coinInfD().x(),coinInfD().y());
 }

