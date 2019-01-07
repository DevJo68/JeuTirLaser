
#include "casevide.h"
#include "doctest.h"


TEST_CASE("Une case vide est créée correctement ")
{
    geom::point p1{40,60};
    geom::point p2{80,100} ;
    caseVide Casevide1{p1,p2};
    REQUIRE_EQ(Casevide1.coinSupG(),p1 );
    REQUIRE_EQ(Casevide1.coinInfD(),p2 );



}

