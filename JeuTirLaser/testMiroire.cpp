#include "doctest.h"
#include "miroir.h"


TEST_CASE("Une miroire se cree et s'incline correctement ")
{
       geom::point depart{40,80};
       geom::point arrive{100,150} ;

       SUBCASE("une miroire se cree correctement ")
    {

    miroir m{depart,arrive};
    REQUIRE_EQ(m.depart(),depart);
    REQUIRE_EQ(m.arrivee(),arrive);
    REQUIRE_EQ(m. inclinaison(),'g');

    }

         SUBCASE("une miroire s'incline a gauche correctement ")
      {
          miroir m{depart,arrive};
           geom::point nouveauDepart{100,80};
          geom::point nouvelleArrive{40,150};
          m.inclineG();

           REQUIRE_EQ(m.depart(),nouveauDepart);
           REQUIRE_EQ(m.arrivee(),nouvelleArrive);
           REQUIRE_EQ(m. inclinaison(),'g');
      }
            SUBCASE("une miroire s'incline a droite correctement ")
      {
          miroir m{depart,arrive};
           geom::point nouveauDepart{120,80};
           geom::point nouvelleArrive{60,150};
           m.inclineD();
           REQUIRE_EQ(m.depart(),nouveauDepart);
           REQUIRE_EQ(m.arrivee(),nouvelleArrive);
           REQUIRE_EQ(m.inclinaison(),'d');
      }
}
