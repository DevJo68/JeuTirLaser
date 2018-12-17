#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include "case.h"
#include "casevide.h"
#include "point.h"
#include "miroir.h"
#include "casemiroir.h"
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
        void initialize(Case *c,int nbMiroir, int nbMur, int nbCible, int nbLaser);

        ///@return un vecteur de vecteur de pointeur sur des cases qui vont constituer notre terrain
        std::vector<std::vector<Case*>>& getTerrain();

        /// Ajoute une case au terrain
        void ajouteCase(int i, int j,Case *c);

        /// @return retourne une case du terrain récupérer grâce au indice i et j donnée en paramètre
        Case* recupereCase(int i, int j) const;


        /**
          Affiche le terrain
        */
        void afficheTerrain() const;

        ///@return un int représentant la taille du terrain
        int size();

        virtual ~terrain();

    protected:

    private:
        std::vector< std::vector<Case*>> d_terrain;

};


///operator<< for writing a point on a output stream
std::ostream& operator<<(std::ostream& , const terrain& );
///operator>> for reading a point from a intput stream
std::istream& operator>>(std::istream& , terrain& );


#endif // TERRAIN_H
