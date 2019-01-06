#ifndef CIBLE_H
#define CIBLE_H


class cible
{
    public:

        cible(double x, double y, int rayon);
        double cibleX() const;
        double cibleY() const;
        int cibleRayon() const;

    private:
        double d_x;
        double d_y;
        int d_rayon;
};

#endif // CIBLE_H
