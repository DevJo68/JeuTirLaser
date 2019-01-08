#include "doctest.h"
#include "monstre.h"

TEST_CASE("Un monstre se cree correctement  ")
{
      geom::point p1{40,80};
       geom::point p2{100,150} ;
    monstre monstre{p1,p2,3};
     REQUIRE_EQ(monstre.monstreX(),70);
     REQUIRE_EQ(monstre.monstreY(),115);
     REQUIRE_EQ(monstre.monstreRayon(),3);
}
