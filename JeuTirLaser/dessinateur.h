#ifndef DESSINATEUR_H
#define DESSINATEURE_H

#include "graphics.h"
#include "case.h"
#include "terrain.h"
#include "miroir.h"
#include "cible.h"

class dessinateur{

     public:
       void dessinateurCase(const Case *c) const;
       void dessinateurLigne(const Case *c);
       void dessinateurCaseMiroir(const Case *c, const miroir *m ) const;
       void dessinateurCaseCible(const Case *c, const cible *cib ) const;


};

#endif
