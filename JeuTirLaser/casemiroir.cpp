#include "casemiroir.h"

caseMiroir::caseMiroir(const geom::point& p1, const geom::point& p2, miroir *m):
    Case{p1,p2},d_miroir{m}
{}

void caseMiroir::print() const{
  if(d_miroir->inclinaison() == 'd')
     d_dessinateur.dessinateurCaseMiroir(d_miroir->depart().x(),d_miroir->depart().y(),d_miroir->arrivee().x(),d_miroir->arrivee().y());
  else
     d_dessinateur.dessinateurCaseMiroir(coinSupG().x(),coinSupG().y(),coinInfD().x(),coinInfD().y());
}

char caseMiroir::inclinaisonMiroir() const{
 return d_miroir->inclinaison();
}

int  caseMiroir::typeCase(){
 return  2 ;
}

 geom::point caseMiroir::pointHGMiroir() const{
   return d_miroir->depart();
 }

 geom::point caseMiroir::pointBDMiroir() const{
   return d_miroir->arrivee();
 }



void caseMiroir::changeInclinaison(){
   if(d_miroir->inclinaison() == 'd')
        d_miroir->inclineG();
   else
        d_miroir->inclineD();
}

