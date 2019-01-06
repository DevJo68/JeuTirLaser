#include "miroir.h"

miroir::miroir(const geom::point& pDepart ,const  geom::point& pArrivee):
    d_depart{pDepart}, d_arrivee{pArrivee}, d_inclinaison{'g'}
{}

 char miroir::inclinaison() const{
  return d_inclinaison;
 }
 geom::point miroir::depart() const{
   return d_depart;
 }
 geom::point miroir::arrivee() const{
   return d_arrivee;
 }

 void miroir::inclineG() {

   double mx = d_arrivee.x() - d_depart.x();
   double mx2 = - mx;

   d_depart.moveTo(d_depart.x()+ mx ,d_depart.y());
   d_arrivee.moveTo(d_arrivee.x() + mx2,d_arrivee.y());
   d_inclinaison = 'g';

 }

  void miroir::inclineD() {

   double mx = (d_arrivee.x() - d_depart.x()) + (d_arrivee.x() - d_depart.x())  ;
   double mx2 = d_arrivee.x() - d_depart.x() ;

   d_depart.moveTo(mx,d_depart.y());
   d_arrivee.moveTo(mx2,d_arrivee.y());
   d_inclinaison = 'd';

 }

