#include "monstre.h"

monstre::monstre(double x, double y, int rayon):
    d_x{x},d_y{y},d_rayon{rayon}
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

