#include <stdio.h>
#include <stdbool.h>
#include "polynome.h"

void printPoly(Poly poly)
{
    printf("Fonction : %s", __func__);
    printf("\n");
    for (int i=poly.taille; i > poly.taille; i--)
    {
        printf("%d",i);
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

            if (i != 1)
            {
                printf("+");
            }
        }
    }
    printf("\n");
}