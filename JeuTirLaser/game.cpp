#include "game.h"

 void game::run(){

    caseVide c{};

    std::cout << "Veuillez à présent saisir les dimensions de votre terrain en ligne et en colonne ?"<< std::endl;

    int lig,col;
    std::cin>>lig>>col;
    terrain t{lig,col};


    int  nbMonstre =0 ,nbCible=0, nbMur = (lig*col)/2;
    std::cout << "Combien de cible désirez désirez-vous dans votre terrain ? "<< std::endl;
    std::cin>>nbCible;
    t.setNbCible(nbCible);
    t.setNbLaser(1);
    t.setNbMur(nbMur);
    t.setNbMiroir(0);
    t.setScore(0);

    std::cout << "Combien de case monstre désirez-vous dans votre terrain ? "<< std::endl;

    std::cin>>nbMonstre;
    t.setNbMonstre(nbMonstre);

    caseVide *p = &c;
    t.initialize(p);
    //On fait tourner le jeu ici
    opengraphsize(( p->longeur() * (t.size() * 2)) , ( p->longeur() * (t.size() * 2)));
    setcolor(WHITE);



   while(1){
      int x = 500 , y = 100;
       char const* Score =  (char const*) t.nbScore();
       //std::cout << t.nbScore() << std::endl;
      settextjustify(RIGHT_TEXT,CENTER_TEXT);
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
      outtextxy(x, y, "Score");
      t.afficheTerrain();
      t.deplaceLaserSurTerrain();
      t.placeMiroir();
      t.collisionLaser();
      t.verifGagner();
      t.afficheTerrain();
      delay(0.00000000000000000001);
    }

    getch();
    closegraph();

   }
