#include <iostream>
#include <vector>
#include "game.h"
#include "casevide.h"
using namespace std;

int main()
{

     game g{};
     g.run();

   /*   opengraphsize(1000,1000);
      setcolor(RED);
      int x1 = 100,y1 = 200, x2 = 200,y2 = 200, speed = 5;
      terrain t{10,10};
      caseVide c{};
      caseVide * pc = &c;
      t.initialize(pc);

      bool isHorizontal = false;
      std::cout << isHorizontal << std::endl;



      while(1){
        if(GetAsyncKeyState(VK_UP)){

          if(isHorizontal){
            std::cout << isHorizontal << std::endl;
            x1 = x2;
           y1 -= 100;
           isHorizontal = false;
          }
          y1 -= speed;
          y2 -= speed;
      }
      if(GetAsyncKeyState(VK_DOWN)){
        if(isHorizontal){
            x2 = x1;
            y1 +=100;
            isHorizontal = false;
            std::cout << isHorizontal << std::endl;
          }
          y1 += speed;
          y2 += speed;
      }
      if(GetAsyncKeyState(VK_LEFT)){

        if(!isHorizontal){
            x1 = x2;
            y1 = y2;
            x2 += 100;
            isHorizontal = true;
            std::cout << isHorizontal << std::endl;
          }

          x1 -= speed;
          x2 -= speed;
      }
      if(GetAsyncKeyState(VK_RIGHT)){
          if(!isHorizontal){
            x1 = x2;
            y1 = y2;
            x2 += 100;
            isHorizontal = true;
          }
          x1 += speed;
          x2 += speed;

       }
        cleardevice();
        line(x1,y1,x2,y2);
        t.afficheTerrain();

       delay(0.001);

      }*/

    return 0;
}
