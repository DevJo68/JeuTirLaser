#include "doctest.h"
#include "terrain.h"
#include <vector>

TEST_CASE("Une laser se cree et se modifie correctement  ")
{         terrain tr{12,13};
          geom::point p1{50,60};
           geom::point p2{80,100} ;
          caseVide cas{p1,p2};
           caseVide* c;
           c=&cas;
        SUBCASE("un terrain se cree correctement")
    {

       REQUIRE_EQ(tr.size(),156);
    }

       SUBCASE("initialiser un terrain correctement")
    {
       tr.initialize(c);
        caseVide cas2;
       REQUIRE_EQ(cas2.coinSupG(),p1);
        REQUIRE_EQ(cas2.coinInfD(),p2);
    }
        SUBCASE("ajout d'une case se fait correctement  ")
    {    int i =13;
          int j =4;
         tr.ajouteCase(i,j,c);
         REQUIRE_EQ(tr.size(),169);

    }

   /*
     SUBCASE("recuperation d'une case se fait correctement  ")
    {   int i =13;
          int j =4;
         tr.ajouteCase(i,j,c);
        caseVide* caseRecuperee=tr.recupereCase(i,j) ;on ne peut pas faire ce test pck le type de retour est case* et case est une clase abstraite
        REQUIRE_EQ(caseRecuperee->coinSupG(),p1);
        REQUIRE_EQ(caseRecuperee->coinInfD(),p2);

    }*/
        SUBCASE("remplacer une case avec une autre se fait correctement  ")
    {   int i =13;
        int j =4;
        tr.ajouteCase(i,j,c);
        geom::point p3{30,40};
        geom::point p4{70,20} ;
        caseVide cas2{p3,p4};
        caseVide* c2;
        c2=&cas2;
        tr.remplaceCase(i,j,c2);
        REQUIRE_EQ(c->coinSupG(),p3);
        REQUIRE_EQ(c->coinInfD(),p4);
    }
        SUBCASE("detruire  une case se fait correctement  ")
    {
        int i =13;
        int j =4;
        tr.ajouteCase(i,j,c);
        tr.detruireCase(i,j);
        REQUIRE_EQ(tr.size(),156);

    }
      SUBCASE("le nombre des miroirs est exacte  ")
    {
        tr.setNbMiroir(5);
       int nb= tr.nbMiroir();
       REQUIRE_EQ(nb,5);
    }
      SUBCASE("le nombre des murs est exacte  ")
    {
        tr.setNbMur(5);
       int nb= tr.nbMur();
       REQUIRE_EQ(nb,5);
    }
       SUBCASE("le nombre des monstres est exacte  ")
    {
        tr.setNbMonstre(5);
       int nb= tr.nbMonstre();
       REQUIRE_EQ(nb,5);
    }
       SUBCASE("le nombre des lasers est exacte  ")
    {
        tr.setNbLaser(5);
       int nb= tr.nbLaser();
       REQUIRE_EQ(nb,5);
    }
       SUBCASE("le nombre des cibles est exacte  ")
    {
        tr.setNbCible(5);
        int nb= tr.nbCible();
       REQUIRE_EQ(nb,5);
    }
       SUBCASE("le score se calcule correctement  ")
    {
        tr.setScore(10);
        tr.setScore(3);
        int score= tr.nbScore();
        REQUIRE_EQ(score,13);
    }
        SUBCASE("limite du Terrain en Haut se calcule  correctement ")
    {
              tr.remplaceCase(0,0,c);
              double limit =tr.limiteTerrainHaut();
               REQUIRE_EQ(limit,55);
    }
        SUBCASE("limite du Terrain en bas se calcule  correctement ")
    {
              tr.remplaceCase(155,155,c);
              double limit =tr.limiteTerrainHaut();
               REQUIRE_EQ(limit,95);
    }
      SUBCASE("limite du Terrain en gauche se calcule  correctement ")
    {
              tr.remplaceCase(0,0,c);
              double limit =tr.limiteTerrainHaut();
               REQUIRE_EQ(limit,45);
    }
     SUBCASE("limite du Terrain en droite se calcule  correctement ")
    {
              tr.remplaceCase(0,155,c);
              double limit =tr.limiteTerrainHaut();
               REQUIRE_EQ(limit,75);
    }

      SUBCASE("l'etat d'un du Terrain se change correctement ")
    {          terrain tr2{1,1};
               tr2.remplaceCase(0,0,c);
               geom::point p3{30,40};
               geom::point p4{70,20} ;
               tr2.ChangeEtatCaseTerrain(p3,p4);
               REQUIRE_EQ(c->contientLaser() ,true);
    }

     SUBCASE("deviation tir se fait correctement ")
    {    geom::point p3{30,40};
        geom::point p4{70,20} ;
        miroir m{p3,p4};
        miroir* mi;
        mi=&m;
        caseMiroir caseM{p1,p2,mi};
        caseM.inclinaisonMiroir() == 'g';
        std::vector<caseMiroir*>  miroirs;
        miroirs.push_back(mi);
        tr.devierTir(c);
               SUBCASE("quand on presse la touche up ")
                     {

                      }
}}
