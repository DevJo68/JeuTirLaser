#include "doctest.h"
#include "cible.h"


TEST_CASE("Une cible s'affiche correctement ")
{
      geom::point p1{40,80};
       geom::point p2{100,150} ;
    cible cib{p1,p2,7};
    REQUIRE_EQ(cib.cibleX(),70);
    REQUIRE_EQ(cib.cibleY() ,115);
    REQUIRE_EQ(cib.cibleRayon(),7);
}
