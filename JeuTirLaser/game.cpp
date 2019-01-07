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


    std::cout << "Combien de case miroir désirez-vous dans votre terrain ? "<< std::endl;
    int nbM =0, nbMonstre =0 , nbMur = (lig*col)/2;
    t.setNbCible(1);
    t.setNbLaser(1);
    t.setNbMur(nbMur);
    t.setScore(0);

    std::cin>>nbM;

    t.setNbMiroir(nbM);

    std::cout << "Combien de case monstre désirez-vous dans votre terrain ? "<< std::endl;

    std::cin>>nbMonstre;
    t.setNbMonstre(nbMonstre);

    caseVide *p = &c;
    t.initialize(p);
    //On fait tourner le jeu ici
    opengraphsize(( p->longeur() * (t.size() * 2)) , ( p->longeur() * (t.size() * 2)));
    setcolor(WHITE);


    int x = 500 , y = 500;
    settextjustify(RIGHT_TEXT,CENTER_TEXT);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
    outtextxy(x, y, "Score");

   while(1){
      t.afficheTerrain();
      t.deplaceLaserSurTerrain();
      t.collisionLaser();
      t.verifGagner();
      t.afficheTerrain();
      delay(0.00000000000000000001);
    }

    getch();
    closegraph();

   }else{

   /* On crée manuellement la case en saisissant les coordonées */
    std::cout<< "Veuillez saisir le point haut gauche de la case"<<std::endl;
    geom::point p1{};
    p1.read(std::cin);

    std::cout<< "Veuillez saisir le point bas droite de la case"<<std::endl;
    geom::point p2{};
    p2.read(std::cin);

    caseVide c{p1,p2};

        std::cout << "Veuillez à présent saisir les dimensions de votre terrain en ligne et en colonne ?"<< std::endl;

    int lig,col;
    std::cin>>lig>>col;
    terrain t{lig,col};


    std::cout << "Combien de case miroir désirez-vous dans votre terrain ? "<< std::endl;
    int nbM =0, nbMonstre =0 , nbMur = (lig*col)/2;
    t.setNbCible(1);
    t.setNbLaser(1);
    t.setNbMur(nbMur);
    t.setScore(0);

    std::cin>>nbM;

    t.setNbMiroir(nbM);

    std::cout << "Combien de case monstre désirez-vous dans votre terrain ? "<< std::endl;

    std::cin>>nbMonstre;
    t.setNbMonstre(nbMonstre);

    caseVide *p = &c;
    t.initialize(p);
    //On fait tourner le jeu ici
    opengraphsize(( p->longeur() * (t.size() * 2)) , ( p->longeur() * (t.size() * 2)));
    setcolor(WHITE);


    int x = 50 , y = 50;
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
    outtextxy(x,y, "Score");

   while(1){
      t.afficheTerrain();
      t.deplaceLaserSurTerrain();
      t.collisionLaser();
      t.afficheTerrain();
      delay(0.00000000000000000001);
    }

    getch();
    closegraph();


   }
 }
