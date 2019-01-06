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
#include "caselaser.h"
#include <time.h>
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

        /// Cr�e un terrain et l'initialise avec les diff�rentes types de cases
        void initialize(Case *c);

        /// ajoute des cases vides au terrain
        void creerCaseVide(Case*c);

        /// ajoute des cases miroir sur le terrain a des coordon�es i et j tir� au hasard ou  bien � l'aide de la souris
        void creerCaseMiroir();

        /// ajoute des cases mur sur le terrain a des coordon�es i et j tir�e au hasard
        void creerCaseMur();

        /// ajoute des cases cible sur le terrain a des coordon�es i et j tir�e au hasard
        void creerCaseCible();
        /// ajoute des cases laser sur le terrain a des coordon�es i et j tir�e au hasard
        void creerCaseLaser();

        ///@return un vecteur de vecteur de pointeur sur des cases qui vont constituer notre terrain
        std::vector<std::vector<Case*>>& getTerrain();

        /// Ajoute une case au terrain
        void ajouteCase(int i, int j,Case *c);

        /// @return Retourne une case du terrain r�cup�rer gr�ce au indice i et j donn�e en param�tre
        Case* recupereCase(int i, int j) const;

        caseLaser* recupereLaser() const;

        /// Remplace la case courante par la case donn�e en param�tre
        void remplaceCase(int i, int j,Case *c);

        /// D�truit la case donnee en parama�tre
        void detruireCase(int i , int j);

        /// D�place le laser sur le terrain
        void deplaceLaserSurTerrain();

        /**
          Affiche le terrain
        */
        void afficheTerrain();

        ///@return un int repr�sentant la taille du terrain
        int size();

        ///@return un int repr�sentant le nombre de miroir du terrain
        int nbMiroir() const;

        ///@return un int repr�sentant le nombre de mur du terrain
        int nbMur() const;

        ///@return un int repr�sentant le nombre de laser du terrain
        int nbLaser() const;

        ///@return un int repr�sentant le nombre de cible du terrain
        int nbCible() const;

        /**
          Saisie un nombre de miroir � mettre sur le terrain
          @param int nombre de miroir
        */
        void setNbMiroir(int nbmiroir);

        /**
          Saisie un nombre de mur � mettre sur le terrain
          @param int nombre de mur
        */
        void setNbMur(int nbmur);

         /**
          Saisie un nombre de laser � mettre sur le terrain
          @param int nombre de laser
        */
        void setNbLaser(int nblaser);

         /**
          Saisie un nombre de cible � mettre sur le terrain
          @param int nombre de cible
        */
        void setNbCible(int nbcible);

        /**
          M�thode qui permet d'effectuer les actions qui vont faire en sorte que le jeu fonctionne
        */
        void startGame();

        ///@return un double repr�sentant la limite en haut du terrain pour le d�placement du laser
        double limiteTerrainHaut();

        ///@return un double repr�sentant la limite en bas du terrain pour le d�placement du laser
        double limiteTerrainBas();

        ///@return un double repr�sentant la limite � gauche du terrain pour le d�placement du laser
        double limiteTerrainGauche();

        ///@return un double repr�sentant la limite � droite du terrain pour le d�placement du laser
        double limiteTerrainDroite();

        /**
          Foncton qui va g�rer la collision du laser avec les autres �l�ments du terrain et int�ragir en cons�quence
        */
        void collisionLaser();

        /**
         Parcours le terrain et modifie l'�tat de la case correspondant au coordon�es donn�es en param�tres
        */
        void ChangeEtatCaseTerrain(const geom::point& p1, const geom::point& p2);

        /**
         Fonction qui va devier le tir du laser
        */
        void devierTir(Case *c);

        /**
         Place des miroirs sur le terrain
        */
        void placeMiroir();


    protected:

    private:
        std::vector< std::vector<Case*>> d_terrain;
        int d_nbmiroir;
        int d_nbmur;
        int d_nbcible;
        int d_nblaser;
        caseLaser* d_laser;
        std::vector<caseMiroir*> d_miroirs;

};


///operator<< for writing a point on a output stream
std::ostream& operator<<(std::ostream& , const terrain& );
///operator>> for reading a point from a intput stream
std::istream& operator>>(std::istream& , terrain& );


#endif // TERRAIN_H
