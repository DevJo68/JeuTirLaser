#include "casemiroir.h"
#include "doctest.h"


TEST_CASE("Une case miroir est créée correctement ")
{
    geom::point p1{40,60};
    geom::point p2{80,100} ;
    geom::point p3{20,30};
    geom::point p4{40,50} ;
    miroir m{p3,p4};
    miroir* miroir2;
    miroir2 = &m;
    caseMiroir Casemiroir1{p1,p2,miroir2};
    REQUIRE_EQ(Casemiroir1.coinSupG(),p1 );
    REQUIRE_EQ(Casemiroir1.coinInfD(),p2 );
    REQUIRE_EQ(m.depart(),p3);
    REQUIRE_EQ(m.arrivee(),p4);

}

