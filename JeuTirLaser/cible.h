#ifndef CIBLE_H
#define CIBLE_H


class cible
{
    public:
        cible(int x, int y, int rayon);
        int cibleX() const;
        int cibleY() const;
        int cibleRayon() const;
        void print() const;
        virtual ~cible();

    private:
        int d_x;
        int d_y;
        int d_rayon;
};

#endif // CIBLE_H
