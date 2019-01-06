#include "caselaser.h"

caseLaser::caseLaser(const geom::point& p1, const  geom::point& p2, laser *l):
    Case{p1,p2}, d_laser{l}
{
  d_contientLaser = true;
}

void caseLaser::print() const{
  d_dessinateur.dessinateurCaseLaser(coinSupG().x(),coinSupG().y(),coinInfD().x(),coinInfD().y());
}

geom::point caseLaser::coinHGLaser(){
 return d_laser->pHautGauche();
}

geom::point caseLaser::coinBDLaser(){
 return d_laser->pBasDroit();
}

void caseLaser::deplaceLaserEnHautG(double x, double y){
  d_laser->pHautGauche().moveTo(x,y);
}

void caseLaser::deplaceLaserEnInfD(double x, double y){
  d_laser->pBasDroit().moveTo(x,y);
}

int caseLaser::typeCase(){
  return 5;
}





