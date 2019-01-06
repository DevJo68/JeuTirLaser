#ifndef MONSTRE_H
#define MONSTRE_H


class monstre
{
    public:
        monstre(double x, double y, int rayon);
        double monstreX() const;
        double monstreY() const;
        int monstreRayon() const;

    private:
        double d_x;
        double d_y;
        int d_rayon;
};

#endif // MONSTRE_H
