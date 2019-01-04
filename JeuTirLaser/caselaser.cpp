#include "caselaser.h"

caseLaser::caseLaser(const geom::point& p1, const  geom::point& p2, laser *l):
    Case{p1,p2}, d_laser{l}
{
  d_contientLaser = true;
}

void caseLaser::print() const{
  d_dessinateur.dessinateurCaseLaser(coinSupG().x(),coinSupG().y(),coinInfD().x(),coinInfD().y());
}

geom::point caseLaser::coinHGLaser(){
 return d_laser->pHautGauche();
}

geom::point caseLaser::coinBDLaser(){
 return d_laser->pBasDroit();
}

void caseLaser::deplaceLaserEnHautG(double x, double y){
  d_laser->pHautGauche().moveTo(x,y);
}

void caseLaser::deplaceLaserEnInfD(double x, double y){
  d_laser->pBasDroit().moveTo(x,y);
}

void caseLaser::deplaceLaser(){

       if(GetAsyncKeyState(VK_UP)){
         /* if(d_laser->isHorizontal()){
                std::cout << "Attention on va changer de sens  VK_UP" << std::endl;
            deplaceEnSupG(coinInfD().x(),coinSupG().y());
            deplaceDeSupG(0,-100);
            d_laser->setVertical();
          }*/

           deplaceDe(0,-10);
           cleardevice();

      }
      if(GetAsyncKeyState(VK_DOWN)){
        /*if(d_laser->isHorizontal()){
                std::cout << "Attention on va changer de sens  VK_DOWN" << std::endl;
            deplaceEnInfD(coinSupG().x(),coinInfD().y());
            deplaceDeSupG(0,100);
            d_laser->setVertical();
          }*/
            deplaceDe(0,10);
            cleardevice();
      }
      if(GetAsyncKeyState(VK_LEFT)){
        /*if(!d_laser->isHorizontal()){
                std::cout << "Attention on va changer de sens  VK_LEFT" << std::endl;
            deplaceEn(coinInfD().x(),coinInfD().y());
            deplaceDeInfD(100,0);
            d_laser->setHorizontal();
          }*/
            deplaceDe(-10,0);
            cleardevice();
      }
      if(GetAsyncKeyState(VK_RIGHT)){
          /*if(!d_laser->isHorizontal()){
             d_laser->setHorizontal();
             deplaceEn(coinInfD().x(),coinInfD().y());
             deplaceDeInfD(100,0);
          }*/

          deplaceDe(10,0);
          cleardevice();

       }

     }





