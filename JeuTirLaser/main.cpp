#include <iostream>
#include "graphics.h"
#include "case.h"
#include "terrain.h"
#include "miroir.h"
#include "dessinateur.h"

using namespace std;

int main()
{
    Case c{};
    Case *p;
    dessinateur d{};
    miroir m{c.coinSupG(),c.coinInfD()};
    miroir *pm = &m;
    p = &c; //On  met l'adresse d'une case
    terrain t{20,20};


    t.initialize(p);

    opengraphsize(1500,1500);
    setcolor(WHITE);
    std::cout  << " Taille du terrain que nous avons construit "<< t.size() << std::endl ;
    //t.print();
    std::cout << "Ce miroir à une inclinaison "<< pm->inclinaison() << std::endl;
    pm->inclineG();
    d.dessinateurCaseMiroir(p,pm);
    std::cout << "A présent ce miroir à une inclinaison "<< pm->inclinaison() << std::endl;
    getch();
    closegraph();


    return 0;
}
