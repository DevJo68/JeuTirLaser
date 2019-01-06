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

              creerCaseVide(c);
              creerCaseMiroir();
              creerCaseCible();
              creerCaseLaser();

   }

    void terrain::creerCaseVide(Case*c){

            for(int i = 0; i < d_terrain.size(); i++){

                  for(int j = 0 ; j < d_terrain[i].size() ; j++){
                          geom::point p1{(c->coinSupG().x()*j)+c->coinSupG().x() ,(c->coinSupG().y()*i)+ c->coinSupG().y()};
                          geom::point p2{p1.x() + c->largeur() ,p1.y() + c->longeur()};
                          caseVide*caux = new caseVide{p1,p2};
                          ajouteCase(i,j,caux);
                  }

              }
    }

    void terrain::creerCaseMiroir(){

       for(int k = 0; k < nbMiroir(); k++){
                     int indiceLigneAleatoire = rand() % d_terrain.size();
                     int indiceColonneAleatoire = rand() % d_terrain[indiceLigneAleatoire].size();


                     miroir *pm = new miroir{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD()}  ;
                        if(k%2 == 0)
                        pm->inclineG();
                     else
                        pm->inclineD();

                      std::cout << " Valeurs des points" << pm->arrivee() << pm->depart() << pm->inclinaison() << std::endl;
                     caseMiroir *cm = new caseMiroir{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),pm};
                     remplaceCase(indiceLigneAleatoire,indiceColonneAleatoire,cm);
                     d_miroirs.push_back(cm);
               }
    }

    void terrain::creerCaseCible(){

      for(int l = 0; l < nbCible(); l++){
                     int indiceLigneAleatoire = rand() % (d_terrain.size()-1);
                     int indiceColonneAleatoire = rand() % (d_terrain[indiceLigneAleatoire].size()-1);
                     cible *pc = new cible{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG().x() + recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG().x()/2,
                     recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD().y()-(recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD().y()- recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG().y())/2 ,
                    (recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD().x() - recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG().x())/3/2};

                     caseCible *cib = new caseCible{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),pc};
                     remplaceCase(indiceLigneAleatoire,indiceColonneAleatoire,cib);
               }

    }

    void terrain::creerCaseLaser(){

               for(int m = 0; m < nbLaser(); m++){
                     int indiceLigneAleatoire = rand() % (d_terrain.size()-1);
                     int indiceColonneAleatoire = rand() % (d_terrain[indiceLigneAleatoire].size()-1);

                     laser *pl = new laser{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(), recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),false};
                     std::cout  << " Coordonnée de la case laser "<< pl->pHautGauche() << pl->pBasDroit() << std::endl;
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

}

double terrain::limiteTerrainHaut(){
  return recupereCase(0,0)->coinSupG().y();
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

void terrain::collisionLaser(){

    for(int i = 0; i < d_terrain.size(); i++){
                  for(int j = 0 ; j < d_terrain[i].size() ; j++){

                      //On test si la case contient un laser ou pas
                      if(d_laser->coinSupG().x() >= d_terrain[i][j]->coinSupG().x() && d_laser->coinInfD().x() <= d_terrain[i][j]->coinInfD().x() &&
                         d_laser->coinSupG().y() >= d_terrain[i][j]->coinSupG().y() &&  d_laser->coinInfD().y() <= d_terrain[i][j]->coinInfD().y() ){

                          //Modification de la case qui contient à présent le laser
                          d_terrain[i][j]->changeEtatCase();

                          //Modification de l'état de l'ancienne case laser  qui ne contient plus le laser
                          ChangeEtatCaseTerrain(d_laser->coinSupG(), d_laser->coinInfD());

                          //  L'attribut d_laser prend les coordonées de la nouvelle case laser
                          d_laser->deplaceEnSupG(d_terrain[i][j]->coinSupG().x(),d_terrain[i][j]->coinSupG().y());
                          d_laser->deplaceEnInfD(d_terrain[i][j]->coinInfD().x(), d_terrain[i][j]->coinInfD().y());

                          // Le laser prend les coordonées de la nouvelle case
                          d_laser->deplaceLaserEnHautG(d_laser->coinSupG().x(), d_laser->coinSupG().y());
                          d_laser->deplaceLaserEnInfD(d_laser->coinInfD().x(), d_laser->coinInfD().y());


                         //Si c'est une case miroir
                         if(d_terrain[i][j]->typeCase() ==  2){
                            devierTir(d_terrain[i][j]);
                         }

                         //Si c'est une case cible
                         if(d_terrain[i][j]->typeCase() ==  3){
                            //On détruit la cible et on arrête le jeu
                            caseVide* newCase = new caseVide{d_terrain[i][j]->coinSupG(),d_terrain[i][j]->coinInfD()};
                            d_terrain[i][j] = newCase;
                            int nbcible = nbCible() - 1;
                            setNbCible(nbcible);
                         }

                         //Si c'est une case mur
                         //if(d_terrain[i][j]->typeCase() == )
                  }
            }
   }
}

void terrain::devierTir(Case *c){

     for(int i = 0; i < d_miroirs.size(); i++ ){

                                if(d_miroirs[i] == c){
                                    std::cout << "Je suis rentrer youpi !!" << std::endl;

                                      if(d_miroirs[i]->inclinaisonMiroir() == 'g'){

                                          if(GetAsyncKeyState(VK_UP)){

                                              d_laser->deplaceDeSupG(-d_miroirs[i]->longeur(),0);
                                              d_laser->deplaceDeInfD(-d_miroirs[i]->longeur(),0);
                                           }

                                          if(GetAsyncKeyState(VK_DOWN)){
                                              d_laser->deplaceDeSupG(d_miroirs[i]->longeur(),0);
                                              d_laser->deplaceDeInfD(d_miroirs[i]->longeur(),0);
                                           }
                                           if(GetAsyncKeyState(VK_LEFT)){
                                              d_laser->deplaceDeSupG(0,-d_miroirs[i]->longeur());
                                              d_laser->deplaceDeInfD(0,-d_miroirs[i]->longeur());
                                           }

                                           if(GetAsyncKeyState(VK_RIGHT)){

                                              d_laser->deplaceDeSupG(0,d_miroirs[i]->longeur());
                                              d_laser->deplaceDeInfD(0,d_miroirs[i]->longeur());
                                          }

                                        }else{

                                          if(GetAsyncKeyState(VK_UP)){
                                              d_laser->deplaceDeSupG(d_miroirs[i]->longeur(),0);
                                              d_laser->deplaceDeInfD(d_miroirs[i]->longeur(),0);
                                          }

                                          if(GetAsyncKeyState(VK_DOWN)){
                                              d_laser->deplaceDeSupG(-d_miroirs[i]->longeur(),0);
                                              d_laser->deplaceDeInfD(-d_miroirs[i]->longeur(),0);
                                          }

                                          if(GetAsyncKeyState(VK_LEFT)){
                                              d_laser->deplaceDeSupG(0,d_miroirs[i]->longeur());
                                              d_laser->deplaceDeInfD(0,d_miroirs[i]->longeur());
                                           }

                                           if(GetAsyncKeyState(VK_RIGHT)){

                                              d_laser->deplaceDeSupG(0,-d_miroirs[i]->longeur());
                                              d_laser->deplaceDeInfD(0,-d_miroirs[i]->longeur());
                                          }

                                        }
                                }

                            }

}

void terrain::ChangeEtatCaseTerrain(const geom::point& p1, const geom::point& p2){
      for(int i = 0; i < d_terrain.size(); i++){
                  for(int j = 0 ; j < d_terrain[i].size() ; j++){
                      if(d_terrain[i][j]->coinSupG() == p1 && d_terrain[i][j]->coinInfD() == p2)
                         d_terrain[i][j]->changeEtatCase();
                  }
            }
}
