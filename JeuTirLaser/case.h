#ifndef CASE_H
#define CASE_H

#include "point.h"

 class Case
{
    public:
        /**
        Constructeur par d�faut cr�er un case de base avec comme dimension case{(50,50),(100,100)}
        */
        Case();
        /**
          Constructeur de case avec en param�tre les deux points qui permette de tracer un carr�
          @param p1 point coin sup�rieur gauche (p1.x,p1.y)
          @param p2 point coin inf�rieur droit  (p2.x,p2.y)
        */
        Case(geom::point p1, geom::point p2);

        ///@return un point qui repr�sente le coin sup�rieur gauche
        geom::point coinSupG() const;

        ///@return un point qui r�pr�sente le coin inf�rieur droit
        geom::point coinInfD() const;

        ///@return la longeur de la case
        int longeur();
        ///@return la largeur de la case
        int largeur();



        virtual ~Case();

    protected:

    private:
       geom::point d_coinSupG;
       geom::point d_coinInfD;
};


#endif // CASE_H
