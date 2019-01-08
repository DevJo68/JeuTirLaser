#include "terrain.h"


    terrain::terrain(int ligne, int colonne):
         d_nbmiroir{0}
    {
       std::vector< std::vector<Case *> > terrain(ligne);
       d_terrain = terrain;

        for(int i = 0;i < d_terrain.size(); i++){
            d_terrain[i] = std::vector<Case*>(colonne);
        }
    }


     void terrain::initialize(Case *c){
              srand(time(NULL));
              creerCaseVide(c);
              creerCaseCible();
              creerCaseMonstre();
              creerCaseMur();
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
                     int indiceLigneAleatoire = rand() % (d_terrain.size()-1);
                     int indiceColonneAleatoire = rand() % (d_terrain.size()-1);
                    // std::cout << indiceLigneAleatoire << " " << indiceColonneAleatoire << std::endl;
                    // std::cout << "Voici les coordonnées du point récupérer " << recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG() << recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD() << std::endl;
                     miroir *pm = new miroir{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD()};

                     if(recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->typeCase() != 1) {
                              while(recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->typeCase() != 1){
                                     srand(3);
                                     int indiceLigneAleatoire = rand() % (d_terrain.size()-1);
                         int indiceColonneAleatoire = rand() % (d_terrain[indiceLigneAleatoire].size()-1);
                              }
                       }

                    if(k%2 == 0)
                        pm->inclineG();
                     else
                        pm->inclineD();

                     //std::cout << " Valeurs des points" << pm->arrivee() << pm->depart() << pm->inclinaison() << std::endl;
                     caseMiroir *cm = new caseMiroir{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),pm};
                    // std::cout << " les indices " << indiceLigneAleatoire << indiceColonneAleatoire << std::endl;
                    // std::cout << " Les coordonnées des cases " << cm->coinSupG() << " " << cm->coinInfD() << std::endl;
                     remplaceCase(indiceLigneAleatoire,indiceColonneAleatoire,cm);
               }
    }

    void terrain::creerCaseCible(){

      for(int l = 0; l < nbCible(); l++){
                     int indiceLigneAleatoire = rand() % (d_terrain.size()-1);
                     int indiceColonneAleatoire = rand() % (d_terrain[indiceLigneAleatoire].size()-1);

                     //std::cout << " Type des cases tirés" << recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->typeCase()  << std::endl;
                       if(recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->typeCase() == 1) {

                     cible *pc = new cible{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),8};


                     caseCible *cib = new caseCible{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),pc};
                       std::cout << indiceLigneAleatoire << " " << indiceColonneAleatoire << std::endl;
                     remplaceCase(indiceLigneAleatoire,indiceColonneAleatoire,cib);

                       }
               }

    }

    void terrain::creerCaseLaser(){

               for(int i = 0; i < nbLaser(); i++){
                     int indiceLigneAleatoire = rand() % (d_terrain.size()-1);
                     int indiceColonneAleatoire = rand() % (d_terrain[indiceLigneAleatoire].size()-1);

                     if(recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->typeCase() == 2 || recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->typeCase() == 3 ||
                        recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->typeCase() == 6 || recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->typeCase() == 4){
                         srand(3);
                         int indiceLigneAleatoire = rand() % (d_terrain.size()-1);
                         int indiceColonneAleatoire = rand() % (d_terrain[indiceLigneAleatoire].size()-1);
                       }

                     laser *pl = new laser{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(), recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),false};
                     std::cout  << " Coordonnée de la case laser "<< pl->pHautGauche() << pl->pBasDroit() << std::endl;
                     caseLaser*cl = new caseLaser{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),pl};
                     remplaceCase(indiceLigneAleatoire,indiceColonneAleatoire,cl);
                     d_laser = cl;
               }
    }

    void terrain::creerCaseMonstre(){

      for(int m = 0; m < nbMonstre(); m++){
                     int indiceLigneAleatoire = rand() % (d_terrain.size()-1);
                     int indiceColonneAleatoire = rand() % (d_terrain[indiceLigneAleatoire].size()-1);

                      if(recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->typeCase() == 1) {

                      monstre *pmons = new monstre{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),8};


                     caseMonstre *cmons = new caseMonstre{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),pmons};

                     remplaceCase(indiceLigneAleatoire,indiceColonneAleatoire,cmons);
                       }

               }

    }

    void terrain::creerCaseMur(){

        for(int n = 0; n < nbMur() ; n++){
                     int indiceLigneAleatoire = rand() % (d_terrain.size()-1);
                     int indiceColonneAleatoire = rand() % (d_terrain[indiceLigneAleatoire].size()-1);

                      if(recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->typeCase() == 1) {
                              geom::point x3{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG().x()+recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->longeur(), recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG().y()};
                    geom::point x4{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD().x()-recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->longeur(), recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD().y()};

                     mur *pmur = new mur{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),x3,x4};


                    caseMur *cmur = new caseMur{recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinSupG(),recupereCase(indiceLigneAleatoire,indiceColonneAleatoire)->coinInfD(),pmur};

                     remplaceCase(indiceLigneAleatoire,indiceColonneAleatoire,cmur);
                       }
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

                     //  std::cout <<  "indices des cases " << i << " " << j << std::endl;
                     //  std::cout << " Coordonées des points du terrain "<< d_terrain[i][j]->coinSupG() << d_terrain[i][j]->coinInfD() << std::endl;
                     //  std::cout << "Type des cases " << d_terrain[i][j]->typeCase() << std::endl;
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

void terrain::verifGagner(){
  if(nbCible() == 0){
     int x = 300 , y = 200;
     char* Score =  reinterpret_cast<char*>(nbScore());
    settextjustify(RIGHT_TEXT,CENTER_TEXT);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
    outtextxy(x, y, "Gagné !");
    outtextxy(x, y+100," Votre score ");
    outtextxy(x, y+200,Score);
    getch();
    closegraph();
  }

}



int terrain::nbMiroir() const{
  return d_nbmiroir;
}

int terrain::nbMur() const{
  return d_nbmur;
}

int terrain::nbMonstre() const{
  return d_nbmonstre;
}


int terrain::nbLaser() const{
  return d_nblaser;
}

int terrain::nbCible() const{
  return d_nbcible;
}

int terrain::nbScore() const {
 return d_score;
}


void terrain::setNbMiroir(int nbmiroir){
  d_nbmiroir = d_nbmiroir + nbmiroir ;
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

void terrain::setNbMonstre(int nbmonstre){
   d_nbmonstre = nbmonstre;
}

void terrain::setScore(int score){
   d_score = d_score + score;
}

void terrain::deplaceLaserSurTerrain(){



       if(GetAsyncKeyState(VK_UP)){
         if(d_laser->isHorizontal()){
            d_laser->setVertical();
          }


          if(d_laser->coinSupG().y() >= limiteTerrainHaut()){
             d_laser->deplaceDe(0,-5);
          }else{
             d_laser->deplaceDe(0,0);
          }
           cleardevice();
           afficheTerrain();

      }
      if(GetAsyncKeyState(VK_DOWN)){
        if(d_laser->isHorizontal()){
            d_laser->setVertical();
          }

           if(d_laser->coinInfD().y() <= limiteTerrainBas()){
            d_laser->deplaceDe(0,5);
          }else{
            d_laser->deplaceDe(0,0);
          }


          cleardevice();
          afficheTerrain();
      }
      if(GetAsyncKeyState(VK_LEFT)){
        if(!d_laser->isHorizontal()){
            d_laser->setHorizontal();
          }

          if(d_laser->coinSupG().x() >= limiteTerrainGauche()){
            d_laser->deplaceDe(-5,0);
          }else{
            d_laser->deplaceDe(0,0);
          }
            cleardevice();
            afficheTerrain();
      }
      if(GetAsyncKeyState(VK_RIGHT)){
          if(!d_laser->isHorizontal()){
             d_laser->setHorizontal();
          }
          if(d_laser->coinSupG().x() <= limiteTerrainDroite()-20){
             d_laser->deplaceDe(5,0);
          }else{
             d_laser->deplaceDe(0,0);
          }

          cleardevice();
          afficheTerrain();
      }

}

double terrain::limiteTerrainHaut(){
  return recupereCase(0,0)->coinSupG().y()-5;
}

double terrain::limiteTerrainBas(){
  return recupereCase(size()- 1,size()- 1)->coinInfD().y()-5;
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
                         d_laser->coinSupG().y()>= d_terrain[i][j]->coinSupG().y() &&  d_laser->coinInfD().y() <= d_terrain[i][j]->coinInfD().y()){

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
                            setScore(20);
                         }

                            //Si c'est une case monstre
                         if(d_terrain[i][j]->typeCase() == 6){
                            //On détruit la monstre et on arrête le jeu
                            caseVide* newCase = new caseVide{d_terrain[i][j]->coinSupG(),d_terrain[i][j]->coinInfD()};
                            d_terrain[i][j] = newCase;
                            int nbmonstre = nbMonstre() - 1;
                            setNbMonstre(nbmonstre);
                            setScore(10);
                         }


                         //Si c'est une case mur
                         if(d_terrain[i][j]->typeCase() == 4){
                             toucheMur();
                         }
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


void terrain::toucheMur(){

    int x = 200 , y = 200;
    settextjustify(RIGHT_TEXT,CENTER_TEXT);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
    outtextxy(x, y, "Perdu !");
    getch();
    closegraph();

}



void terrain::ChangeEtatCaseTerrain(const geom::point& p1, const geom::point& p2){
      for(int i = 0; i < d_terrain.size(); i++){
                  for(int j = 0 ; j < d_terrain[i].size() ; j++){
                      if(d_terrain[i][j]->coinSupG() == p1 && d_terrain[i][j]->coinInfD() == p2)
                         d_terrain[i][j]->changeEtatCase();
                  }
            }
}

 void terrain::placeMiroir(){

       if(GetAsyncKeyState(VK_LBUTTON)){

            int x,y;
            getmouse(x,y);

              for(int i = 0; i < d_terrain.size(); i++){
                            for(int j = 0 ; j < d_terrain[i].size() ; j++){

             if(x >= d_terrain[i][j]->coinSupG().x() && x <= d_terrain[i][j]->coinInfD().x() &&
                y >= d_terrain[i][j]->coinSupG().y() && y <= d_terrain[i][j]->coinInfD().y() ){

                               if(recupereCase(i,j)->typeCase() == 1) {
                                      miroir *pm = new miroir{recupereCase(i,j)->coinSupG(),recupereCase(i,j)->coinInfD()};
                                      if(j%2 == 0)
                                       pm->inclineG();
                                    else
                                       pm->inclineD();

                               caseMiroir *cm = new caseMiroir{recupereCase(i,j)->coinSupG(),recupereCase(i,j)->coinInfD(),pm};
                               d_terrain[i][j] = nullptr;
                               remplaceCase(i,j,cm);
                               d_miroirs.push_back(cm);
                               setNbMiroir(1);

                                 }else{
                                   caseVide* newCase = new caseVide{d_terrain[i][j]->coinSupG(),d_terrain[i][j]->coinInfD()};
                                   d_terrain[i][j] = nullptr;
                                   d_terrain[i][j] = newCase;
                                 }


                            }
              }


        }


   }
 }
