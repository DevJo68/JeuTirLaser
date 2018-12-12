#include "terrain.h"
#include "graphics.h"
#include "dessinateur.h"


    terrain::terrain(int ligne, int colonne)
    {
       std::vector< std::vector<Case *> > terrain(ligne);
       d_terrain = terrain;

        for(int i = 0;i < d_terrain.size(); i++){
            d_terrain[i] = std::vector<Case*>(colonne);
        }
    }


     void terrain::initialize(Case *c){


        for(int i = 0; i < d_terrain.size(); i++){

              std::cout << " indice i" << i <<  std::endl;

              for(int j = 0 ; j < d_terrain[i].size() ; j++){
                      std::cout << " indice j" << j <<  std::endl;

                      geom::point p1{(c->coinSupG().x()*j)+c->coinSupG().x() ,(c->coinSupG().y()*i)+ c->coinSupG().y()};
                      geom::point p2{p1.x() + c->largeur() ,p1.y() + c->longeur()};

                      Case *caux = new Case{p1,p2};
                      ajouteCase(i,j,caux);
              }


        }
            std::cout << " Valeur qui sont contenue dans notre tableau " << std::endl;
            for(int i = 0; i < d_terrain.size(); i++){

                   std::cout<< " indice i " << i << " \n" <<std::endl;

              for(int j = 0 ; j < d_terrain[i].size() ; j++){

                     std::cout<< " indice j " << " " << j << std::endl;
                    std::cout << " x1 " << d_terrain[i][j]->coinSupG().x() << " y1 "<<  d_terrain[i][j]->coinSupG().y() << std::endl;
                    std::cout << " x2 "<<  d_terrain[i][j]->coinInfD().x() << " x2 " << d_terrain[i][j]->coinInfD().y() << std::endl;

              }
   }



     }

  std::vector< std::vector<Case*>>& terrain::getTerrain(){
     return d_terrain ;
  }

   int terrain::size(){
      return d_terrain.size() ;
   }

   void terrain::print() const{
       dessinateur d{};
       for(int i = 0; i < d_terrain.size(); i++){
              for(int j = 0 ; j < d_terrain[i].size() ; j++){

                   std::cout << " x1 " <<d_terrain[i][j]->coinSupG().x() << " y1 "<<  d_terrain[i][j]->coinSupG().y() << std::endl;
                    std::cout << " x2 "<<  d_terrain[i][j]->coinInfD().x() << " x2 " << d_terrain[i][j]->coinInfD().y() << std::endl;
                  d.dessinateurCase(d_terrain[i][j]);

              }
   }

   }




void terrain::ajouteCase(int i, int j ,Case *c){
   d_terrain[i][j] = c;
}



terrain::~terrain()
{
    //dtor
}
