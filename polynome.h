#ifndef MODULE_POLYNOME
#define MODULE_PoLYNOME

typedef struct Poly
{
    int taille;
    double coef[10];
} Poly;

void printPoly(Poly);

#endif