#include "laser.h"
#include "doctest.h"

TEST_CASE("")
{

   SUBCASE ("le laser est horizontal")
   {

    geom::point p1{40,60};
    geom::point p2{80,100} ;
    bool Horizontal =true;
    laser l{p1,p2,Horizontal};


    REQUIRE_EQ(l.pBasDroit(),p2 );
    REQUIRE_EQ(l.pBasDroit(),p2 );
   }
}
