#ifndef CASE_H
#define CASE_H

#include "point.h"
#include "graphics.h"
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
        Case(const geom::point& p1, const geom::point& p2);

        ///@return un point qui représente le coin supérieur gauche
        geom::point coinSupG() const;

        ///@return un point qui réprésente le coin inférieur droit
        geom::point coinInfD() const;

        ///@return la longeur de la case
        int longeur();

        ///@return la largeur de la ca///@return un point qui réprésente le coin inférieur droitse
        int largeur();

        ///@return un bool avec la valeur true si le laser est passé par cette case, false dans l'autre cas
        bool contientLaser() const;

        /// change l'état de la case dans le cas ou le laser est passer par celle-ci
        void changeEtatCase();

        /// deplace la case  des coordonées données en paramètres
        void deplaceDe(double x, double y);

        /// deplace la case aux coordonnées données en paramètres
        void deplaceEn(double x, double y);

        ///  deplace le point haut gauche de la case au coordonées du point inférieur droit
        void deplaceEnSupG(double x, double y);

        /// deplace le  point inférieur droit de la case au coordonées du point haut gauche
        void deplaceEnInfD(double x, double y);

        /// deplace le point suérieur gauche des coordonées données en paramètre
        void deplaceDeSupG(double x, double y);

        /// deplace le point inférieur droit des coordonées données en paramètre
        void deplaceDeInfD(double x, double y);

        /// affiche une case
        virtual void print() const = 0;

    protected:
        geom::point d_coinSupG;
        geom::point d_coinInfD;
        dessinateur d_dessinateur;
        bool d_contientLaser;

   /* private:
       geom::point d_coinSupG;
       geom::point d_coinInfD;
       bool d_contientLaser;*/
};


#endif // CASE_H
