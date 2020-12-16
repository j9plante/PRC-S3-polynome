#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

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

Poly multiplication_poly(Poly p1, Poly p2)
{
    Poly multiplication;
    // Coeff de plus haut degré du résultat cphd
    int cphd = (p1.taille - 1) + (p2.taille - 1);
    int d;
    if (cphd > 10)
    {
        printf("\n#Error 404 Polynome NOT FOUND\n");
        Poly error;
        // Si le polynome est de trop haut degré on renvoit un polynome d'erreur de taille négative
        error.taille = -1;
        return error;
    }
    multiplication = create_empty(cphd + 1);
    multiplication.taille = cphd + 1;
    for (int a1 = 0; a1 < p1.taille; a1++)
    {
        for (int a2 = 0; a2 < p2.taille; a2++)
        {
            // On fait une double boucle pour la double distributivitée
            //On classe les valeurs obtenues par d, degré soit par l'addition de leur rang dans leur liste respective
            d = a1 + a2;
            multiplication.coef[d] = p1.coef[a1] * p2.coef[a2] + multiplication.coef[d];
        }
    }
    return multiplication;
}

Poly create_empty(int taille)
{
    Poly poly;
    poly.taille = taille;
    for (int i = 0; i < 10; i++)
    {
        poly.coef[i] = 0.0;
    }
    return poly;
}

Poly get_poly_from_str(char str[])
{
    //char str[] = "10x^(3)+5x^(2)+7x^(1)+6x^(0)";
    char delim[] = "+";

    double poly[10] = {0};
    int rang;
    double coef;

    int max=0;
    
    char *ptr = strtok(str, delim);
    while (ptr != NULL)
    {
        //printf("%s\n", ptr);
        sscanf(ptr, "%lf x^(%d)", &coef, &rang);
        if (rang>max)
        {
            max=rang;
        }
        poly[rang] = coef;
        ptr = strtok(NULL, delim);
    }

    Poly p1=create_empty(10);

    p1.taille=max+1;
    for(int i=0;i<p1.taille;i++)
    {
        p1.coef[i]=poly[i];
    }

    return p1;
}

/*bool open_from_file(const char *filename, char poly[])
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        return false;
    }

    //char poly[150];
    if (f != NULL)
    {
        fscanf(f, "%s", poly[0]);
    }

    fclose(f);
    return true;
}*/

double calcul_valeur(double x, Poly poly)
{
    //Nécéssite l'ajout de -lm (librairie math) dans le makefile pour l'édition des liens (BINFLAGS+=-g -O0 -lm) (pow())
    double value;

    for (int i = 0; i < poly.taille; i++)
    {
        value += poly.coef[i] * pow(x, i);
    }

    return value;
}

/*void create_poly(double count, ...)
{

}*/

/*Poly parsseur(char *)
{
}*/