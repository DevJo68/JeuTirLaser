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

                  for(int j = 0 ; j < d_terrain[i].size() ; j++){
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
                     cible *pc = new cible{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG().x() + recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG().x()/2,
                     recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD().y()-(recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD().y()- recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG().y())/2 ,
                    (recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD().x() - recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG().x())/3/2};

                     caseCible *cib = new caseCible{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),pc};
                     remplaceCase(indiceLigneAleatoire,indiceColonneAleatoire,cib);
               }

               for(int m = 0; m < nbLaser(); m++){
                     int indiceLigneAleatoire = rand() % (d_terrain.size()-1);
                     int indiceColonneAleatoire = rand() % (d_terrain[indiceLigneAleatoire].size()-1);

                     laser *pl = new laser{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(), recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),false};
                     std::cout  << "Coordonnée de la case laser "<< pl->pHautGauche() << pl->pBasDroit() << std::endl;
                     caseLaser*cl = new caseLaser{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),pl};
                     remplaceCase(indiceLigneAleatoire,indiceColonneAleatoire,cl);
                     d_laser = cl;
               }

   }



  std::vector< std::vector<Case*>>& terrain::getTerrain(){
     return d_terrain ;
  }

   int terrain::size(){
      return d_terrain.size() ;
   }

   void terrain::afficheTerrain(){
           for(int i = 0; i < d_terrain.size(); i++){
                  for(int j = 0 ; j < d_terrain[i].size() ; j++){
                      /* std::cout << " x1 " <<d_terrain[i][j]->coinSupG().x() << " y1 \n "<<  d_terrain[i][j]->coinSupG().y() << std::endl;
                       std::cout << " x2 "<<  d_terrain[i][j]->coinInfD().x() << " x2 \n" << d_terrain[i][j]->coinInfD().y() << std::endl;
                       std::cout << " x1 " << &d_terrain[i][j] << std::endl;*/

                        d_terrain[i][j]->print();
                  }
            }
   }


void terrain::ajouteCase(int i, int j ,Case *c){
   d_terrain[i][j] = c;
}

 Case* terrain::recupereCase(int i, int j) const{
   return d_terrain[i][j];
}

caseLaser* terrain::recupereLaser() const{
  return d_laser;
}

void terrain::remplaceCase(int i, int j,Case *c){
   d_terrain[i][j] = c;

}

void terrain::detruireCase(int i , int j){
  delete  d_terrain[i][j];
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

void terrain::deplaceLaserSurTerrain(){
       //std::cout << d_laser->coinHGLaser() << d_laser->coinBDLaser() << std::endl;
       if(GetAsyncKeyState(VK_UP)){
         /* if(d_laser->isHorizontal()){
                std::cout << "Attention on va changer de sens  VK_UP" << std::endl;
            deplaceEnSupG(coinInfD().x(),coinSupG().y());
            deplaceDeSupG(0,-100);
            d_laser->setVertical();
          }*/
          if(d_laser->coinSupG().y() >= limiteTerrainHaut()){
             d_laser->deplaceDe(0,-5);
          }else{
            d_laser->deplaceDe(0,0);
          }
           cleardevice();

      }
      if(GetAsyncKeyState(VK_DOWN)){
        /*if(d_laser->isHorizontal()){
                std::cout << "Attention on va changer de sens  VK_DOWN" << std::endl;
            deplaceEnInfD(coinSupG().x(),coinInfD().y());
            deplaceDeSupG(0,100);
            d_laser->setVertical();
          }*/

           if(d_laser->coinInfD().y() <= limiteTerrainBas()){
           d_laser->deplaceDe(0,5);
          }else{
            d_laser->deplaceDe(0,0);
          }


          cleardevice();
      }
      if(GetAsyncKeyState(VK_LEFT)){
        /*if(!d_laser->isHorizontal()){
                std::cout << "Attention on va changer de sens  VK_LEFT" << std::endl;
            deplaceEn(coinInfD().x(),coinInfD().y());
            deplaceDeInfD(100,0);
            d_laser->setHorizontal();
          }*/

          if(d_laser->coinSupG().x() >= limiteTerrainGauche()){
            d_laser->deplaceDe(-5,0);
          }else{
            d_laser->deplaceDe(0,0);
          }
            cleardevice();
      }
      if(GetAsyncKeyState(VK_RIGHT)){
          /*if(!d_laser->isHorizontal()){
             d_laser->setHorizontal();
             deplaceEn(coinInfD().x(),coinInfD().y());
             deplaceDeInfD(100,0);
          }*/
          if(d_laser->coinSupG().x() <= limiteTerrainDroite()-20){
             d_laser->deplaceDe(5,0);
          }else{
             d_laser->deplaceDe(0,0);
          }

          cleardevice();
      }
   //d_laser->deplaceLaser();

}

double terrain::limiteTerrainHaut(){
  return recupereCase(0,0)->coinSupG().y()*2.1;
}

double terrain::limiteTerrainBas(){
  return recupereCase(size()- 1,size()- 1)->coinInfD().y()*2 ;
}

double terrain::limiteTerrainGauche(){
  return recupereCase(0,0)->coinSupG().x()-5;
}

double terrain::limiteTerrainDroite(){
  return recupereCase(0,size()- 1)->coinInfD().x();
}
