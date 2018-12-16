#include <iostream>

#include "casevide.h"
#include "terrain.h"
#include "miroir.h"


using namespace std;

int main()
{


    terrain t{20,20};
    caseVide c{};
    caseVide *p = &c;
    t.initialize(p);
    opengraphsize(1500,1500);
    setcolor(WHITE);
    std::cout  << " Taille du terrain que nous avons construit "<< t.size() << std::endl ;
    t.afficheTerrain();
    getch();
    closegraph();


    return 0;
}
