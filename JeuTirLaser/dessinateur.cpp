#include "dessinateur.h"



void  dessinateur::dessinateurCase(const Case *c) const{
   rectangle(c->coinSupG().x(),c->coinSupG().y(),c->coinInfD().x(),c->coinInfD().y());

 }


void  dessinateur::dessinateurCaseMiroir(const Case *c,const miroir *m) const{

   rectangle(c->coinSupG().x(),c->coinSupG().y(),c->coinInfD().x(),c->coinInfD().y());
   line(m->depart().x(), m->depart().y(), m->arrivee().x(), m->arrivee().y());

 }

void dessinateur::dessinateurCaseCible(const Case *c, const cible *cib ) const{
   rectangle(c->coinSupG().x(),c->coinSupG().y(),c->coinInfD().x(),c->coinInfD().y());
   circle(cib->cibleX(),cib->cibleY(),cib->cibleRayon());
   //circle(cib->cibleX(),cib->cibleY(),cib->cibleRayon()/2);
}




