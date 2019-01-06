#include "doctest.h"
#include "casecible.h"


TEST_CASE("Une case cible se cree correctement et son type est 3  ")
{

geom::point p1{50,60};
geom::point p2{80,100} ;
cible cib{5.6,6.2,3};
cible* cib2;
cib2 = &cib;
caseCible Casecibl{p1,p2,cib2};
  int type =Casecibl.typeCase();

    REQUIRE_EQ(Casecibl.coinSupG(),p1);
    REQUIRE_EQ(Casecibl.coinInfD(),p2);
    REQUIRE_EQ(cib.cibleX(),5.6);
    REQUIRE_EQ(cib.cibleY() ,6.2);
    REQUIRE_EQ(cib.cibleRayon(),3);
     REQUIRE_EQ(type,3);


}
