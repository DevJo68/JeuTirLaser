#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include "case.h"
#include "casevide.h"
#include "point.h"
#include "miroir.h"
#include "casemiroir.h"
#include "cible.h"
#include "casecible.h"
#include <time.h>
#include<iosfwd>
#include <iostream>



class terrain
{
    public:
        /**
          Constructeur de terrain, creer un terrain a partir des dimensions(ligne,colonne) et une case donner en paramètre
          @param int ligne nb ligne du terrain
          @param int colonne nb colonne du terrain
          @param Case* c pointeur sur une case
        */
        terrain(int ligne, int colonne);

         /// Crée un terrain et l'initialise avec les différentes types de cases
        void initialize(Case *c);

        ///@return un vecteur de vecteur de pointeur sur des cases qui vont constituer notre terrain
        std::vector<std::vector<Case*>>& getTerrain();

        /// Ajoute une case au terrain
        void ajouteCase(int i, int j,Case *c);

        /// @return Retourne une case du terrain récupérer grâce au indice i et j donnée en paramètre
        Case* recupereCase(int i, int j) const;

        /// Remplace la case courante par la case donnée en paramètre
        void remplaceCase(int i, int j,Case *c);

        /// Détruit la case donnee en paramaètre
        void detruireCase(int i , int j);

        /**
          Affiche le terrain
        */
        void afficheTerrain() const;

        ///@return un int représentant la taille du terrain
        int size();

        ///@return un int représentant le nombre de miroir du terrain
        int nbMiroir() const;

        ///@return un int représentant le nombre de mur du terrain
        int nbMur() const;

        ///@return un int représentant le nombre de laser du terrain
        int nbLaser() const;

        ///@return un int représentant le nombre de cible du terrain
        int nbCible() const;

        /**
          Saisie un nombre de miroir à mettre sur le terrain
          @param int nombre de miroir
        */
        void setNbMiroir(int nbmiroir);

        /**
          Saisie un nombre de mur à mettre sur le terrain
          @param int nombre de mur
        */
        void setNbMur(int nbmur);

         /**
          Saisie un nombre de laser à mettre sur le terrain
          @param int nombre de laser
        */
        void setNbLaser(int nblaser);

         /**
          Saisie un nombre de cible à mettre sur le terrain
          @param int nombre de cible
        */
        void setNbCible(int nbcible);

        virtual ~terrain();

    protected:

    private:
        std::vector< std::vector<Case*>> d_terrain;
        int d_nbmiroir;
        int d_nbmur;
        int d_nbcible;
        int d_nblaser;
};


///operator<< for writing a point on a output stream
std::ostream& operator<<(std::ostream& , const terrain& );
///operator>> for reading a point from a intput stream
std::istream& operator>>(std::istream& , terrain& );


#endif // TERRAIN_H
