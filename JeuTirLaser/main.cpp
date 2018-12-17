#include <iostream>


#include "game.h"

using namespace std;

int main()
{

   /*
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
    */
    game g{};
    g.run();


    return 0;
}
