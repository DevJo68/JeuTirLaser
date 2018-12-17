#ifndef CASE_H
#define CASE_H

#include "point.h"
#include "dessinateur.h"

 class Case
{
    public:
        /**
        Constructeur par défaut créer un case de base avec comme dimension case{(50,50),(100,100)}
        */
        Case();
        /**
          Constructeur de case avec en paramètre les deux points qui permette de tracer un carré
          @param p1 point coin supérieur gauche (p1.x,p1.y)
          @param p2 point coin inférieur droit  (p2.x,p2.y)
        */
        Case(geom::point p1, geom::point p2);

        ///@return un point qui représente le coin supérieur gauche
        geom::point coinSupG() const;

        ///@return un point qui réprésente le coin inférieur droit
        geom::point coinInfD() const;

        ///@return la longeur de la case
        int longeur();

        ///@return la largeur de la ca///@return un point qui réprésente le coin inférieur droitse
        int largeur();

        ///@return un bool avec la valeur true si le laser est passé par cette case, false dans l'autre cas
        bool ContientLaser() const;

        /// change l'état de la case dans le cas ou le laser est passer par celle-ci
        void changeEtatCase();



        /// affiche une case
        virtual void print() const = 0;

        virtual ~Case();

    protected:
        geom::point d_coinSupG;
        geom::point d_coinInfD;
        bool d_contientLaser;

   /* private:
       geom::point d_coinSupG;
       geom::point d_coinInfD;
       bool d_contientLaser;*/
};


#endif // CASE_H
