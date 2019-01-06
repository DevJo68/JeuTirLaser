#include "doctest.h"
#include "laser.h"

TEST_CASE("Une laser se cree et se modifie correctement  ")
{   geom::point p1{50,60};
    geom::point p2{80,100} ;

    SUBCASE("laser horisontal")
    {          bool isHorizontal=true;
                laser l{p1,p2,isHorizontal} ;

         SUBCASE("laser horisontal se cree correctement ")
                {
                 REQUIRE_EQ(l.pHautGauche(),p1);
                 REQUIRE_EQ(l.pBasDroit() ,p2);
                 REQUIRE_EQ(l.isHorizontal(),isHorizontal);
               }
           SUBCASE("laser horisontal se change en verticale correctement ")
                {
                  l.setVertical();
                 REQUIRE_EQ(l.isHorizontal(),false);
                }

    }
    SUBCASE("laser verticale")
    {
                bool isHorizontal=false;
                laser l{p1,p2,isHorizontal} ;

         SUBCASE("laser verticale se cree correctement ")
                {
                 REQUIRE_EQ(l.pHautGauche(),p1);
                 REQUIRE_EQ(l.pBasDroit() ,p2);
                 REQUIRE_EQ(l.isHorizontal(),isHorizontal);
               }
           SUBCASE("laser verticale se change en horizontale correctement ")
                {
                  l.setHorizontal();
                 REQUIRE_EQ(l.isHorizontal(),true);
                }

    }
}
