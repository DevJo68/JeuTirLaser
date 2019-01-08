#include "doctest.h"
#include "casecible.h"


TEST_CASE("Une case cible se cree correctement et son type est 3  ")
{

geom::point p1{50,60};
geom::point p2{80,100} ;
geom::point p3{76,60};
geom::point p4{80,98} ;
cible cib{p3,p4,3};
cible* cib2;
cib2 = &cib;
caseCible Casecibl{p1,p2,cib2};
  int type =Casecibl.typeCase();

    REQUIRE_EQ(Casecibl.coinSupG(),p1);
    REQUIRE_EQ(Casecibl.coinInfD(),p2);
    REQUIRE_EQ(cib2->cibleX(),78);
    REQUIRE_EQ(cib2->cibleY() ,79);
    REQUIRE_EQ(cib2->cibleRayon(),3);
     REQUIRE_EQ(type,3);


}
