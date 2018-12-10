#include "case.h"

    Case::Case():
        d_coinSupG{25,25},d_coinInfD{50,50}
    {
    }

    Case::Case(geom::point p1, geom::point p2):
        d_coinSupG{p1},d_coinInfD{p2}
    {
    }

    int Case::longeur(){
      return d_coinInfD.y() - d_coinSupG.y();
    }

    int Case::largeur(){
      return d_coinInfD.x() - d_coinSupG.x();
    }

     geom::point Case::coinSupG() const{
       return d_coinSupG;
     }

     geom::point Case::coinInfD() const{
       return d_coinInfD;
     }

    Case::~Case()
    {
    //dtor
    }
