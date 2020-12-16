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

double calcul_valeur(double,Poly);

bool open_from_file(const char *, char *[]);

Poly get_poly_from_str(char[]);

char get_string_from_file(const char *Filename);

#endif