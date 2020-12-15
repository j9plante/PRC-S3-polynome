#include <stdio.h>
#include <stdbool.h>
#include "polynome.h"

void printPoly(Poly poly)
{
    printf("Fonction : %s", __func__);
    printf("\n");
    for (int i = poly.taille; i >= 0; i--)
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

            if (i != 0)
            {
                printf("+");
            }
        }
    }
    printf("\n");
}

addition_poly(Poly p1, Poly p2)
{
    Poly result;

    /*if (taille  = NULL)
    {
        add = p2;
        return add
    }

    if (p2 = NULL)
    {
        add = p1;
        return add
    }*/

    result.taille = p1.taille > p2.taille ? p1.taille : p2.taille;

    for (int i; i > result.taille; i++)
    {
        result.coef[i] = p1.coef[i] + p2.coef[i];
    }
    return result;
}