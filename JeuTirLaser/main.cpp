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
    cible cib{p->coinSupG().x()+p->coinSupG().x()/2,p->coinInfD().x()-p->coinInfD().x()/2,p->largeur()};
    cible *pcib = &cib;

    terrain t{30,30};


    t.initialize(p);

    opengraphsize(1500,1500);
    setcolor(WHITE);
    std::cout  << " Taille du terrain que nous avons construit "<< t.size() << std::endl ;
   // t.print();
    //std::cout << "Ce miroir à une inclinaison "<< pm->inclinaison() << std::endl;
   // pm->inclineG();
    //d.dessinateurCaseMiroir(p,pm);
    //std::cout << "A présent ce miroir à une inclinaison "<< pm->inclinaison() << std::endl;
    d.dessinateurCaseCible(p,pcib);
    getch();
    closegraph();


    return 0;
}
