#include "caselaser.h"

caseLaser::caseLaser(const geom::point& p1, const  geom::point& p2, laser *l):
    Case{p1,p2}, d_laser{l}
{
  d_contientLaser = true;
}

void caseLaser::print() const{
  if(d_laser->isHorizontal())
      d_dessinateur.dessinateurCaseLaserHorizontal(coinSupG().x(),coinSupG().y(),coinInfD().x(),coinInfD().y());
  else
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

bool caseLaser::isHorizontal() const{
   return d_laser->isHorizontal();
}

void caseLaser::setHorizontal(){
  d_laser->setHorizontal();
}

void caseLaser::setVertical(){
  d_laser->setVertical();
}

int caseLaser::typeCase(){
  return 5;
}
