#include "case.h"

    Case::Case():
        d_coinSupG{25,25},d_coinInfD{50,50}, d_contientLaser{false}
    {}

    Case::Case(const geom::point& p1, const geom::point& p2):
        d_coinSupG{p1},d_coinInfD{p2},d_contientLaser{false}
    {}

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

     bool Case::contientLaser()const {
       return d_contientLaser;
     }

     void Case::changeEtatCase(){
        if(d_contientLaser)
            d_contientLaser = false;
        else
            d_contientLaser = true;
     }

     void Case::deplaceDe(double x, double y){
        d_coinSupG.move(x,y);
        d_coinInfD.move(x,y);
     }

     void Case::deplaceEn(double x, double y){
        d_coinSupG.moveTo(x,y);
        d_coinInfD.moveTo(x,y);
     }

     void Case::deplaceDeSupG(double x, double y){
       d_coinSupG.move(x,y);
     }

     void Case::deplaceDeInfD(double x, double y){
       d_coinInfD.move(x,y);
     }

     void Case::deplaceEnSupG(double x, double y){
       d_coinSupG.moveTo(x,y);
     }

     void Case::deplaceEnInfD(double x, double y){
       d_coinInfD.moveTo(x,y);
     }



