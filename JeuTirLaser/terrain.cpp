#include "terrain.h"


    terrain::terrain(int ligne, int colonne)
    {
       std::vector< std::vector<Case *> > terrain(ligne);
       d_terrain = terrain;

        for(int i = 0;i < d_terrain.size(); i++){
            d_terrain[i] = std::vector<Case*>(colonne);
        }
    }


     void terrain::initialize(Case *c,int nbMiroir,int nbMur, int nbCible, int nbLaser){


            for(int i = 0; i < d_terrain.size(); i++){

                  std::cout << " indice i" << i <<  std::endl;

                  for(int j = 0 ; j < d_terrain[i].size() ; j++){
                          std::cout << " indice j" << j <<  std::endl;

                          geom::point p1{(c->coinSupG().x()*j)+c->coinSupG().x() ,(c->coinSupG().y()*i)+ c->coinSupG().y()};
                          geom::point p2{p1.x() + c->largeur() ,p1.y() + c->longeur()};

                          caseVide*caux = new caseVide{p1,p2};
                          ajouteCase(i,j,caux);
                  }


              }

              for(int k =0; k < nbMiroir;k++){
                 int indiceLigneAleatoire = rand() % d_terrain.size();
                 int indiceColonneAleatoire = rand() % d_terrain[indiceLigneAleatoire].size();

                /*  std::cout << indiceLigneAleatoire << " et " << indiceColonneAleatoire << std::endl;
                std::cout << "Voila les coordonnées du point récupérer"<< recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG() << recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD() << std::endl;*/

                 miroir m{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD()};
                 miroir *pm = &m;
                 caseMiroir cm{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),pm};
                 caseMiroir * pcm = &cm;
                 std::cout << "Le point que nous allons rajouter" << pcm->coinSupG() << " et " << pcm->coinInfD() << std::endl;
                // d_terrain[indiceLigneAleatoire][indiceColonneAleatoire] = pcm;
                // ajouteCase(indiceLigneAleatoire,indiceColonneAleatoire,pcm);

              }




           /* std::cout << " Valeur qui sont contenue dans notre tableau " << std::endl;
            for(int i = 0; i < d_terrain.size(); i++){

                   std::cout<< " indice i " << i << " \n" <<std::endl;

              for(int j = 0 ; j < d_terrain[i].size() ; j++){

                     std::cout<< " indice j " << " " << j << std::endl;
                    std::cout << " x1 " << d_terrain[i][j]->coinSupG().x() << " y1 "<<  d_terrain[i][j]->coinSupG().y() << std::endl;
                    std::cout << " x2 "<<  d_terrain[i][j]->coinInfD().x() << " x2 " << d_terrain[i][j]->coinInfD().y() << std::endl;

              }*/


   }



  std::vector< std::vector<Case*>>& terrain::getTerrain(){
     return d_terrain ;
  }

   int terrain::size(){
      return d_terrain.size() ;
   }

   void terrain::afficheTerrain() const{
        opengraphsize(1500,1500);
        setcolor(WHITE);
           for(int i = 0; i < d_terrain.size(); i++){
                  for(int j = 0 ; j < d_terrain[i].size() ; j++){

                       std::cout << " x1 " <<d_terrain[i][j]->coinSupG().x() << " y1 "<<  d_terrain[i][j]->coinSupG().y() << std::endl;
                        std::cout << " x2 "<<  d_terrain[i][j]->coinInfD().x() << " x2 " << d_terrain[i][j]->coinInfD().y() << std::endl;
                        d_terrain[i][j]->print();
                  }
            }
          getch();
          closegraph();

   }


void terrain::ajouteCase(int i, int j ,Case *c){
   d_terrain[i][j] = c;
}

 Case* terrain::recupereCase(int i, int j) const{
   return d_terrain[i][j];
}


terrain::~terrain()
{
    //dtor
}
