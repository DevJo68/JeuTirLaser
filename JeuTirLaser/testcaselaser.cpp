#include "caselaser.h"
#include "doctest.h"


TEST_CASE("Une case laser  est créée correctement ")
{

    geom::point p1{40,60};
    geom::point p2{80,100} ;
    bool Horizontal =true;
    laser l{p1,p2,Horizontal};
    laser * laser2;
    laser2 = &l;
    caseLaser caseLaser1{p1,p2,laser2};
    REQUIRE_EQ(caseLaser1.coinSupG(),p1 );
    REQUIRE_EQ(caseLaser1.coinInfD(),p2 );
    REQUIRE_EQ(l.pBasDroit(),p2 );
    REQUIRE_EQ(l.pBasDroit(),p2 );

}

