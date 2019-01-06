#include "doctest.h"
#include "casemonstre.h"

TEST_CASE("Une case monstre  se cree correctement et son type est 6")
{
     geom::point p1{50,60};
      geom::point p2{80,100};
      monstre mon{4.8,8.9,3};
      monstre* monstre;
      monstre=&mon;
      casemonstre casemonstre{p1,p2,monstre};
      int type=casemonstre.typeCase();
      REQUIRE_EQ(casemonstre.coinSupG(),p1);
      REQUIRE_EQ(casemonstre.coinInfD(),p2);
      REQUIRE_EQ(monstre->monstreX(),4.8);
      REQUIRE_EQ(monstre->monstreY(),8.9);
      REQUIRE_EQ(monstre->monstreRayon(),3);
      REQUIRE_EQ(type,6);


}
