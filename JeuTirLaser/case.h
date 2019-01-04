#ifndef CASE_H
#define CASE_H

#include "point.h"
#include "graphics.h"
#include "dessinateur.h"

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
        Case(const geom::point& p1, const geom::point& p2);

        ///@return un point qui repr�sente le coin sup�rieur gauche
        geom::point coinSupG() const;

        ///@return un point qui r�pr�sente le coin inf�rieur droit
        geom::point coinInfD() const;

        ///@return la longeur de la case
        int longeur();

        ///@return la largeur de la ca///@return un point qui r�pr�sente le coin inf�rieur droitse
        int largeur();

        ///@return un bool avec la valeur true si le laser est pass� par cette case, false dans l'autre cas
        bool contientLaser() const;

        /// change l'�tat de la case dans le cas ou le laser est passer par celle-ci
        void changeEtatCase();

        /// deplace la case  des coordon�es donn�es en param�tres
        void deplaceDe(double x, double y);

        /// deplace la case aux coordonn�es donn�es en param�tres
        void deplaceEn(double x, double y);

        ///  deplace le point haut gauche de la case au coordon�es du point inf�rieur droit
        void deplaceEnSupG(double x, double y);

        /// deplace le  point inf�rieur droit de la case au coordon�es du point haut gauche
        void deplaceEnInfD(double x, double y);

        /// deplace le point su�rieur gauche des coordon�es donn�es en param�tre
        void deplaceDeSupG(double x, double y);

        /// deplace le point inf�rieur droit des coordon�es donn�es en param�tre
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
