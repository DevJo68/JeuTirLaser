#include "doctest.h"
#include "monstre.h"

TEST_CASE("Un monstre se cree correctement  ")
{
    monstre monstre{4.8,8.9,3};
     REQUIRE_EQ(monstre.monstreX(),4.8);
     REQUIRE_EQ(monstre.monstreY(),8.9);
     REQUIRE_EQ(monstre.monstreRayon(),3);
}
