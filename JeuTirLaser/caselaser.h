#ifndef CASELASER_H
#define CASELASER_H

#include <windows.h>
#include "point.h"
#include "laser.h"
#include "case.h"

class caseLaser : public Case{

    public:
        caseLaser(const geom::point& p1, const geom::point& p2, laser *l);
        virtual void print() const override;
        geom::point coinHGLaser();
        geom::point coinBDLaser();
        void deplaceLaserEnHautG(double x, double y);
        void deplaceLaserEnInfD(double x, double y);
        void deplaceLaser();
        //laser* getLaser() const;

    protected:

    private:
        laser *d_laser;
};

#endif // CASELASER_H
