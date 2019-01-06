#include "mur.h"
#include "point.h"


mur::mur(geom::point droite,geom::point gauche,geom::point haut,geom::point bas):
    d_droite{droite}, d_gauche{gauche}, d_haut{haut},d_bas{bas}
{}
 geom::point mur::droite() const{
   return d_droite;
 }
 geom::point mur::gauche() const{
   return d_gauche;
 }
geom::point mur::haut() const{
   return d_haut;
 }
 geom::point mur::bas() const{
   return d_bas;
 }
