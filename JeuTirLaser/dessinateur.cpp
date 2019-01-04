#include "dessinateur.h"



void  dessinateur::dessinateurCaseVide(double x1, double y1, double x2, double y2) const{
   dessinateurCaseLigne(x1,y1,x2,y2);
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

void dessinateur::dessinateurCaseCible(double x1, double y1, double x2, double y2) const{
   rectangle(x1,y1,x2,y2);
   circle(x1+ x1/2,y2-(y2-y1)/2,(x2-x1)/3);
   circle(x1 + x1/2,y2-(y2-y1)/2,(x2-x1)/3/2);
}

void dessinateur::dessinateurCaseLaser(double x1, double y1, double x2, double y2)const {
   /* x1 = x1 + x1/2;
    y1 = y1 + y1/3;
    x2 = x2 - x2/2;
    y2 = y2 - y2/10;
    25+25/2,25+25/3,25+25/2, 50-50/6*/
    //std::cout << " Valeur des cases "<< (x1+x2)/2 << " "<< y1+(y1/8) << " "<< (x1+x2)/2 << y2-(y2/8) << std::endl;
    line((x1+x2)/2,y1/2 ,(x1+x2)/2 ,y2/2);
      /*
      int x3 = x1+x1/3, y3 = y1-10, x4 = x1+x1/3, y4 = y1+10;
       line(x1,y1,x3,y3);
       line(x1,y1,x4,y4);
       line(x3,y3,x3,y4);*/
}






