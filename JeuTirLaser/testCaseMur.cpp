#include "doctest.h"
#include "casemur.h"



TEST_CASE("Une case mur  se cree ecorrectement ")
{
 geom::point p1{50,60};
     geom::point p2{80,100} ;
     geom::point droite{70,40};
     geom::point gauche{30,90} ;
     geom::point haut{87,65};
     geom::point bas{95,200} ;

     mur mu{droite,gauche,haut,bas};
      mur* mur2;
     mur2=&mu;

    caseMur casemur{p1,p2,mur2};
     int type =casemur.typeCase();
     REQUIRE_EQ(casemur.coinSupG(),p1);
     REQUIRE_EQ(casemur.coinInfD(),p2);

      REQUIRE_EQ(mur2->haut(),haut);
     REQUIRE_EQ(mur2->droite(),droite);
     REQUIRE_EQ(mur2->gauche(),gauche);
       REQUIRE_EQ(mur2->bas(),bas);
     REQUIRE_EQ(casemur.typeCase(),4);
}
