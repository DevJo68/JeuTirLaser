#include "casevide.h"

caseVide::caseVide():
    Case()
{}

caseVide::caseVide(const geom::point& p1, const geom::point& p2):
    Case(p1,p2)
{}

 void caseVide::print() const{
    d_dessinateur.dessinateurCaseVide(coinSupG().x(),coinSupG().y(),coinInfD().x(),coinInfD().y());
 }

