#ifndef CASEMIROIR_H
#define CASEMIROIR_H


#include "miroir.h"
#include "case.h"


class caseMiroir : public Case {

    public:
        caseMiroir(const geom::point& p1, const geom::point& p2, miroir *m);
        virtual void print() const override;
        miroir* getMiroir() const;

    private:
        miroir *d_miroir;
};

#endif // CASEMIROIR_H
