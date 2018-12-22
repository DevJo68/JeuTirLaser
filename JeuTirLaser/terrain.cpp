#include "terrain.h"


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

                          caseVide*caux = new caseVide{p1,p2};
                          ajouteCase(i,j,caux);
                  }


              }


              for(int k = 0; k < nbMiroir(); k++){
                     int indiceLigneAleatoire = rand() % d_terrain.size();
                     int indiceColonneAleatoire = rand() % d_terrain[indiceLigneAleatoire].size();


                     miroir m{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD()};
                     miroir *pm = &m;
                     caseMiroir *cm = new caseMiroir{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),pm};
                     remplaceCase(indiceLigneAleatoire,indiceColonneAleatoire,cm);
               }

              for(int l = 0; l < nbCible(); l++){
                     int indiceLigneAleatoire = rand() % (d_terrain.size()-1);
                     int indiceColonneAleatoire = rand() % (d_terrain[indiceLigneAleatoire].size()-1);

                     std::cout << indiceLigneAleatoire << " et " << indiceColonneAleatoire << std::endl;
                     std::cout << "Voila les coordonnées du point à modifier /n"<< recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG() << recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD() << std::endl;

                     cible c{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG().x() + recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG().x()/2,
                     recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD().y()-(recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD().y()- recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG().y())/2 ,
                    (recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD().x() - recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG().x())/3/2};

                     cible *pc = &c;
                     caseCible *cib = new caseCible{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),pc};
                     remplaceCase(indiceLigneAleatoire,indiceColonneAleatoire,cib);
               }

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
           std::cout <<  "Terrain afficher:" << std::endl;
           for(int i = 0; i < d_terrain.size(); i++){
                  for(int j = 0 ; j < d_terrain[i].size() ; j++){
                       std::cout << " x1 " <<d_terrain[i][j]->coinSupG().x() << " y1 \n "<<  d_terrain[i][j]->coinSupG().y() << std::endl;
                        std::cout << " x2 "<<  d_terrain[i][j]->coinInfD().x() << " x2 \n" << d_terrain[i][j]->coinInfD().y() << std::endl;
                         std::cout << " x1 " << &d_terrain[i][j] << std::endl;

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

void terrain::remplaceCase(int i, int j,Case *c){
   d_terrain[i][j] = c;

}

void terrain::detruireCase(int i , int j){
   d_terrain[i][j] = nullptr;
}


int terrain::nbMiroir() const{
  return d_nbmiroir;
}

int terrain::nbMur() const{
  return d_nbmur;
}


int terrain::nbLaser() const{
  return d_nblaser;
}

int terrain::nbCible() const{
  return d_nbcible;
}

void terrain::setNbMiroir(int nbmiroir){
  d_nbmiroir = nbmiroir;
}

void terrain::setNbMur(int nbmur){
   d_nbmur = nbmur;
}

void terrain::setNbLaser(int nblaser){
   d_nblaser = nblaser;
}

void terrain::setNbCible(int nbcible){
   d_nbcible = nbcible;
}

terrain::~terrain()
{
    //dtor
}
