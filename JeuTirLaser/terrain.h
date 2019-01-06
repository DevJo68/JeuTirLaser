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
          Constructeur de terrain, creer un terrain a partir des dimensions(ligne,colonne) et une case donner en paramètre
          @param int ligne nb ligne du terrain
          @param int colonne nb colonne du terrain
          @param Case* c pointeur sur une case
        */
        terrain(int ligne, int colonne);

        /// Crée un terrain et l'initialise avec les différentes types de cases
        void initialize(Case *c);

        /// ajoute des cases vides au terrain
        void creerCaseVide(Case*c);

        /// ajoute des cases miroir sur le terrain a des coordonées i et j tiré au hasard ou  bien à l'aide de la souris
        void creerCaseMiroir();

        /// ajoute des cases mur sur le terrain a des coordonées i et j tirée au hasard
        void creerCaseMur();

        /// ajoute des cases cible sur le terrain a des coordonées i et j tirée au hasard
        void creerCaseCible();
        /// ajoute des cases laser sur le terrain a des coordonées i et j tirée au hasard
        void creerCaseLaser();

        ///@return un vecteur de vecteur de pointeur sur des cases qui vont constituer notre terrain
        std::vector<std::vector<Case*>>& getTerrain();

        /// Ajoute une case au terrain
        void ajouteCase(int i, int j,Case *c);

        /// @return Retourne une case du terrain récupérer grâce au indice i et j donnée en paramètre
        Case* recupereCase(int i, int j) const;

        caseLaser* recupereLaser() const;

        /// Remplace la case courante par la case donnée en paramètre
        void remplaceCase(int i, int j,Case *c);

        /// Détruit la case donnee en paramaètre
        void detruireCase(int i , int j);

        /// Déplace le laser sur le terrain
        void deplaceLaserSurTerrain();

        /**
          Affiche le terrain
        */
        void afficheTerrain();

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

        /**
          Méthode qui permet d'effectuer les actions qui vont faire en sorte que le jeu fonctionne
        */
        void startGame();

        ///@return un double représentant la limite en haut du terrain pour le déplacement du laser
        double limiteTerrainHaut();

        ///@return un double représentant la limite en bas du terrain pour le déplacement du laser
        double limiteTerrainBas();

        ///@return un double représentant la limite à gauche du terrain pour le déplacement du laser
        double limiteTerrainGauche();

        ///@return un double représentant la limite à droite du terrain pour le déplacement du laser
        double limiteTerrainDroite();

        /**
          Foncton qui va gérer la collision du laser avec les autres éléments du terrain et intéragir en conséquence
        */
        void collisionLaser();

        /**
         Parcours le terrain et modifie l'état de la case correspondant au coordonées données en paramètres
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
