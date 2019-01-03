#include "game.h"

 void game::run(){

   std::cout << "Voulez crée une case avec des coordonnées par défauts ? (oui) o / (non) n"<< std::endl;
   char reponse;
   std::cin>>reponse;

   if(reponse == 'o'){
      caseVide c{};

    std::cout << "Veuillez à présent saisir les dimensions de votre terrain en ligne et en colonne ?"<< std::endl;

    int lig,col;
    std::cin>>lig>>col;
    terrain t{lig,col};

    std::cout << "Combien de case miroir désirez vous dans votre terrain ? "<< std::endl;
    int nbM =0;
    t.setNbCible(1);
    t.setNbMur(0);
    t.setNbLaser(1);

    std::cin>>nbM;

    t.setNbMiroir(nbM);

    caseVide *p = &c;
    t.initialize(p);
    //On fait tourner le jeu ici
    opengraphsize(800,800);
    setcolor(WHITE);

   while(1){
      t.afficheTerrain();
      t.deplaceLaserSurTerrain();
      t.afficheTerrain();
      delay(0.0000000001);
    }
    getch();
    closegraph();

   }
   else{

   /* On crée manuellement la case en saisissant les coordonées */
    std::cout<< "Veuillez saisir le point haut gauche de la case"<<std::endl;
    geom::point p1{};
    p1.read(std::cin);

    std::cout<< "Veuillez saisir le point bas droite de la case"<<std::endl;
    geom::point p2{};
    p2.read(std::cin);

    caseVide c{p1,p2};
    /* On saisie le terrain en ligne et colonne */
    std::cout << "Veuillez à présent saisir les dimensions de votre terrain en ligne et en colonne ?"<< std::endl;

    int lig,col;
    std::cin>>lig>>col;
    terrain t{lig,col};

    /* On saisie ensuite le nb d'élement à mettre sur le terrain */
    std::cout << "Combien de case miroir désirez vous dans votre terrain ? "<< std::endl;
    int nbMiroir;
    t.setNbCible(1);
    t.setNbMur(0);
    t.setNbLaser(1);
    std::cin>>nbMiroir;

    t.setNbMiroir(nbMiroir);

    caseVide *p = &c;
    // On initialise le terrain avec les différents éléments
    t.initialize(p);
    //On l'affiche
    t.afficheTerrain();


   }
 }
