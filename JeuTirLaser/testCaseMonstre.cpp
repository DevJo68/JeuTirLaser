#include "doctest.h"
#include "casemonstre.h"

TEST_CASE("Une case monstre  se cree correctement et son type est 6")
{
     geom::point p1{50,60};
      geom::point p2{80,100};
      geom::point p3{76,60};
       geom::point p4{80,98} ;
      monstre mon{p3,p4,3};
      monstre* monstre;
      monstre=&mon;
      caseMonstre casemonstr{p1,p2,monstre};
      int type=casemonstr.typeCase();
      REQUIRE_EQ(casemonstr.coinSupG(),p1);
      REQUIRE_EQ(casemonstr.coinInfD(),p2);
      REQUIRE_EQ(monstre->monstreX(),78);
      REQUIRE_EQ(monstre->monstreY(),79);
      REQUIRE_EQ(monstre->monstreRayon(),3);
      REQUIRE_EQ(type,6);


}
