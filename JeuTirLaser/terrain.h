#ifndef TERRAIN_H
#define TERRAIN_H
#include <vector>
#include "case.h"
#include "point.h"
#include<iosfwd>
#include <iostream>



class terrain
{
    public:
        /**
          Constructeur de terrain, creer un terrain a partir des dimensions(ligne,colonne) et une case donner en param�tre
          @param int ligne nb ligne du terrain
          @param int colonne nb colonne du terrain
          @param Case* c pointeur sur une case
        */
        terrain(int ligne, int colonne);

        void initialize(Case *c);

        ///@return un vecteur de vecteur de pointeur sur des cases qui vont constituer notre terrain
        std::vector<std::vector<Case*>>& getTerrain();

         /// Ajoute une case au terrain
        void ajouteCase(int i, int j,Case *c);
        /**
          Affiche le terrain
          @param ost un flot de sortie
        */
        void print() const;

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