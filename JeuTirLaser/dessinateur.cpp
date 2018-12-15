#include "dessinateur.h"



void  dessinateur::dessinateurCaseVide(double x1, double y1, double x2, double y2) const{
   rectangle(x1,y1,x2,y2);

 }

 void dessinateur::dessinateurCaseLigne(double x1, double y1, double x2, double y2)const {
    line(x1,y1,x2,y1);
    line(x2,y1,x2,y2);
	line(x2,y2,x1,y2);
	line(x1,y2,x1,y1);
 }


void  dessinateur::dessinateurCaseMiroir(double x1, double y1, double x2, double y2) const{
   rectangle(x1,y1,x2,y2);
   line(x1,y1,x2,y2);
 }

//void dessinateur::dessinateurCaseCible(const Case *c) const{

 //  cible cib{ c->coinSupG().x()+(c->coinSupG().x()/2) , c->coinInfD().y()- c->longeur()/2 , c->largeur()/3};

  // rectangle(c->coinSupG().x(),c->coinSupG().y(),c->coinInfD().x(),c->coinInfD().y());
  // circle( c->coinSupG().x()+(c->coinSupG().x()/2) , c->coinInfD().y()- c->longeur()/2 , c->largeur()/3);
   //circle( c->coinSupG().x()+(c->coinSupG().x()/2) , c->coinInfD().y()- c->longeur()/2 , c->largeur()/3/2);
//}




