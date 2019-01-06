#ifndef DESSINATEUR_H
#define DESSINATEURE_H

#include "graphics.h"
#include <iostream>

class dessinateur{

     public:
       void dessinateurCaseVide(double x1, double y1, double x2, double y2) const;
       void dessinateurCaseLigne(double x1, double y1, double x2, double y2) const;
       void dessinateurCaseMiroir(double x1, double y1, double x2, double y2) const;
       void dessinateurCaseCible(double x1, double y1, double x2, double y2) const;
       void dessinateurCaseLaser(double x1, double y1, double x2, double y2) const;
       void dessinateurCaseMonstre(double x1, double y1, double x2, double y2) const;
       void dessinateurCaseMur(double x1, double y1, double x2, double y2)const ;

};

#endif
