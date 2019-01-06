#include <iostream>
#include <vector>
#include "game.h"
#include "casevide.h"
#include "casemiroir.h"
using namespace std;

int main()
{

    /* game g{};
     g.run();*/


     geom::point p1{25,25};
     geom::point p2{50,50};
     miroir* m = new miroir{p1,p2};
     caseMiroir c{p1,p2,m};
     caseVide cv{p1,p2};
     opengraphsize(500,500);
     setcolor(RED);
     cv.print();

     circle(37,30,3);
     circle(37.5,37.5,7);
     line(30,30,45,45);
     line(45,30,30,45);


     getch();
     closegraph();


    return 0;
}
