#ifndef MODULE_POLYNOME
#define MODULE_PoLYNOME

typedef struct Poly
{
    int taille;
    double coef[10];
} Poly;

void printPoly(Poly);

Poly addition_poly(Poly, Poly);

Poly soustraction_poly(Poly, Poly);

Poly create_poly(int, double, ...);

Poly multiplication_poly(Poly, Poly);

Poly create_empty(int);


#endif