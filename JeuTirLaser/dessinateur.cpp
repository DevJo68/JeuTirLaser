#include "dessinateur.h"

void  dessinateur::dessinateurCaseVide(double x1, double y1, double x2, double y2) const{
   dessinateurCaseLigne(x1,y1,x2,y2);
  // rectangle(x1,y1,x2,y2);

 }

 void dessinateur::dessinateurCaseLigne(double x1, double y1, double x2, double y2)const {
    line(x1,y1,x2,y1);
    line(x2,y1,x2,y2);
    line(x2,y2,x1,y2);
    line(x1,y2,x1,y1);
 }


void dessinateur::dessinateurCaseMiroir(double x1, double y1, double x2, double y2) const{
   rectangle(x1,y1,x2,y2);
   line(x1,y1,x2,y2);
 }

void dessinateur::dessinateurCaseCible(double x1, double y1, double x2, double y2) const{
   rectangle(x1,y1,x2,y2);
   circle((x1+x2)/2,(y1+y2)/2,8);
   circle((x1+x2)/2,(y1+y2)/2,3);
}

void dessinateur::dessinateurCaseLaser(double x1, double y1, double x2, double y2)const {
    line(x1+((x2-x1)/2),y1+((y2-y1)/2),x2-((x2-x1)/2),y2);
}

void dessinateur::dessinateurCaseLaserHorizontal(double x1, double y1, double x2, double y2) const{
   line(x1+((x2-x1)/3),(y1+y2)/2,x2-((x2-x1)/3),(y1+y2)/2);
}


void dessinateur::dessinateurCaseMonstre(double x1, double y1, double x2, double y2) const{
   rectangle(x1,y1,x2,y2);
   circle((x1+x2)/2,(y1+y2)/2,8);
   line(x1+5,y1+5,x2-5,y2-5);
   line(x2-5,y1,x1-5,y2);
}

void dessinateur::dessinateurCaseMur(double x1, double y1, double x2, double y2)const {
   dessinateurCaseLigne(x1,y1,x2,y2);
   bar(x1,y1,x2,y2);
}
