#include "dessinateur.h"



void  dessinateur::dessinateurCase(const Case *c) const{

   rectangle(c->coinSupG().x(),c->coinSupG().y(),c->coinInfD().x(),c->coinInfD().y());

 }


void  dessinateur::dessinateurCaseMiroir(const Case *c,const miroir *m) const{

   rectangle(c->coinSupG().x(),c->coinSupG().y(),c->coinInfD().x(),c->coinInfD().y());
   line(m->depart().x(), m->depart().y(), m->arrivee().x(), m->arrivee().y());

 }




