#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <stdarg.h>
#include "polynome.h"

void printPoly(Poly poly)
{
    printf("Fonction : %s", __func__);
    printf("\n");
    for (int i = poly.taille - 1; i >= 0; i--)
    {
        //printf("%d",i);
        if (poly.coef[i] != 0)
        {
            if (i == 0)
            {
                printf("%g", poly.coef[i]);
            }
            else
            {
                printf("%gx^(%d)", poly.coef[i], i);
            }

            if (i != 0 && poly.coef[i] > 0)
            {
                printf("+");
            }
        }
    }
    printf("\n");
}

Poly addition_poly(Poly p1, Poly p2)
{
    Poly result;

    result.taille = p1.taille > p2.taille ? p1.taille : p2.taille;

    for (int i = 0; i < result.taille; i++)
    {
        result.coef[i] = p1.coef[i] + p2.coef[i];
    }
    return result;
}

Poly soustraction_poly(Poly p1, Poly p2)
{
    Poly result;

    result.taille = p1.taille > p2.taille ? p1.taille : p2.taille;

    for (int i = 0; i < result.taille; i++)
    {
        result.coef[i] = p1.coef[i] - p2.coef[i];
    }
    return result;
}

Poly create_poly(int nb_valeurs, double valeur1, ...)
{
    Poly poly;

    poly.taille = nb_valeurs;
    poly.coef[0] = valeur1;

    va_list params;
    va_start(params, valeur1);
    for (int i = 1; i < nb_valeurs; ++i)
    {
        double valeur_suiv = va_arg(params, double);
        poly.coef[i] = valeur_suiv;
    }
    va_end(params);

    return poly;
}

/*void create_poly(double count, ...)
{

}*/

/*Poly parsseur(char *)
{
}*/