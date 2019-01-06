#include "doctest.h"
#include "cible.h"


TEST_CASE("Une cible s'affiche correctement ")
{
    cible cib{6,4.7,7};
    REQUIRE_EQ(cib.cibleX(),6);
    REQUIRE_EQ(cib.cibleY() ,4.7);
    REQUIRE_EQ(cib.cibleRayon(),7);
}
