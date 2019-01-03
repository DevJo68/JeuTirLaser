#include "laser.h"
#include <iostream>
laser::laser(const geom::point& p1, const geom::point& p2, bool isHorizontal):
  d_pointHautGauche{p1}, d_pointBasDroit{p2}, d_isHorizontal{isHorizontal}
{}

geom::point laser::pHautGauche() const{
   return d_pointHautGauche;
}

geom::point laser::pBasDroit() const {
   return  d_pointBasDroit;
}

bool laser::isHorizontal() const{
   return d_isHorizontal;
}

void laser::setHorizontal(){
    d_isHorizontal = true;
}

void laser::setVertical(){
    d_isHorizontal = false;
}





