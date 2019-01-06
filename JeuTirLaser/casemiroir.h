#ifndef CASEMIROIR_H
#define CASEMIROIR_H


#include "miroir.h"
#include "case.h"


class caseMiroir : public Case {

    public:

        caseMiroir(const geom::point& p1, const geom::point& p2, miroir *m);
        geom::point pointHGMiroir() const;
        geom::point pointBDMiroir() const;
        virtual void print() const override;
        virtual int typeCase() override;
        char inclinaisonMiroir() const;
        void changeInclinaison();
    private:
        miroir *d_miroir;
};

#endif // CASEMIROIR_H
