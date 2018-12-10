#ifndef DESSINATEUR_H
#define DESSINATEURE_H

#include "graphics.h"
#include "case.h"
#include "terrain.h"
#include "miroir.h"

class dessinateur{

     public:
       void  dessinateurCase(const Case *c) const;
       void dessinateurCaseMiroir(const Case *c, const miroir *m )const;



};

#endif
