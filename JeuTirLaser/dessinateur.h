#ifndef DESSINATEUR_H
#define DESSINATEURE_H

#include "graphics.h"

class dessinateur{

     public:
       void dessinateurCaseVide(double x1, double y1, double x2, double y2) const;
       void dessinateurCaseLigne(double x1, double y1, double x2, double y2) const;
       void dessinateurCaseMiroir(double x1, double y1, double x2, double y2) const;
    //   void dessinateurCaseCible(const Case *cib ) const;

};

#endif
