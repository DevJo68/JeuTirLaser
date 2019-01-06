#include "doctest.h"
#include "mur.h"
TEST_CASE("Un mur se cree correctement  ")
{
     geom::point droite{70,40};
     geom::point gauche{30,90} ;
     geom::point haut{87,65};
     geom::point bas{95,200} ;
     mur mur{droite,gauche,haut,bas};
     REQUIRE_EQ(mur.bas(),bas);
     REQUIRE_EQ(mur.droite(),droite);
     REQUIRE_EQ(mur.gauche(),gauche);
     REQUIRE_EQ(mur.haut(),haut);
}
