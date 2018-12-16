#ifndef CASEMIROIR_H
#define CASEMIROIR_H


#include "miroir.h"
#include "case.h"
#include "dessinateur.h"


class caseMiroir : public Case {

    public:
        caseMiroir(geom::point p1, geom::point p2, miroir *m);
        virtual void print() const override;
        miroir* getMiroir() const;

    private:
        miroir *d_miroir;
};

#endif // CASEMIROIR_H
