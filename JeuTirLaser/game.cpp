#include "game.h"

 void game::run(){

   std::cout << "Voulez cr�e une case avec des coordonn�es par d�fauts ? (oui) o / (non) n"<< std::endl;
   char reponse;
   std::cin>>reponse;

   if(reponse == 'o'){
      caseVide c{};

    std::cout << "Veuillez � pr�sent saisir les dimensions de votre terrain en ligne et en colonne ?"<< std::endl;

    int lig,col;
    std::cin>>lig>>col;
    terrain t{lig,col};

    std::cout << "Combien de case miroir d�sirez vous dans votre terrain ? "<< std::endl;
    int nbMiroir, nbCible = 1,nbLaser = 1, nbMur=0 /*n'existe pas encore pour le moment*/;

    std::cin>>nbMiroir;
    caseVide *p = &c;
    t.initialize(p, nbMiroir, nbLaser, nbMur, nbCible);
    t.afficheTerrain();


   }
   else{

   /* On cr�e manuellement la case en saisissant les coordon�es */
    std::cout<< "Veuillez saisir le point haut gauche de la case"<<std::endl;
    geom::point p1{};
    p1.read(std::cin);

    std::cout<< "Veuillez saisir le point bas droite de la case"<<std::endl;
    geom::point p2{};
    p2.read(std::cin);

    caseVide c{p1,p2};
    /* On saisie le terrain en ligne et colonne */
    std::cout << "Veuillez � pr�sent saisir les dimensions de votre terrain en ligne et en colonne ?"<< std::endl;

    int lig,col;
    std::cin>>lig>>col;
    terrain t{lig,col};

    /* On saisie ensuite le nb d'�lement � mettre sur le terrain */
    std::cout << "Combien de case miroir d�sirez vous dans votre terrain ? "<< std::endl;
    int nbMiroir, nbCible = 1,nbLaser = 1, nbMur=0 /*n'existe pas encore pour le moment*/;

    std::cin>>nbMiroir;
    caseVide *p = &c;
    // On initialise le terrain avec les diff�rents �l�ments
    t.initialize(p, nbMiroir, nbLaser, nbMur, nbCible);
    //On l'affiche
    t.afficheTerrain();

   }
 }
