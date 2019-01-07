#include "monstre.h"

monstre::monstre(const geom::point& p1, const geom::point& p2, int rayon):
    d_x{(p1.x()+p2.x())/2},d_y{(p1.y()+p2.y())/2},d_rayon{rayon}
{}


 double monstre::monstreX() const{
    return d_x;
 }

 double monstre::monstreY() const{
    return d_y;
 }

 int monstre::monstreRayon() const{
    return d_rayon;
  }

