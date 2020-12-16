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
Poly multiplication_poly(Poly p1, Poly p2)
{
    Poly multiplication;
    // Coeff de plus haut degré cphd
    int cphd = p1.coef[p1.taille - 1] + p2.coef[p2.taille - 2];

    if (cphd > POLY_DEG_MAX)
    {
        printf("#Error 404 Polynome NOT FOUND");
        Poly error;
        // Si le polynome est de trop haut degré on renvoit un polynome d'erreur de taille négative
        error.taille = -1;
        return error
    }
    for (int a1 = 0; a1 < p1.coeff[p1.taille - 1]; a1++)
    {
        for (int a2 = 0; a2 < p2.coef[p2.taille - 1]; a2++)
        {
            // On fait une double boucle pour la double distributivitée
            //On classe les valeurs obtenues par d, degré soit par l'addition de leur rang dans leur liste respective
            d = a1[i] + a2[i];
            multiplication.coeff[d] = p1.coeff[a1] * p2.coeff[a2] + multiplication.coeff[d];
        }
    }
    return multiplication;
}

bool open_from_file(const char *filename, char **poly[150])
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        return false;
    }

    char poly[150];
    if (f != NOT NULL)
    {
        fscanf(f, "%s", poly[0]);
    }

    fclose(f);
    return true;
}

/*void create_poly(double count, ...)
{

}*/

/*Poly parsseur(char *)
{
}*/
char get_string_from_file(const char *Filename)
{
    FILE *f = NULL;
    FILE *f = fopen(fileName, "r");
    if (!f)
    {
        return NULL;
    }

    char contenu[210] = ""; // Chaîne vide de taille 210

    if (f != NULL)
    {
        fgets(contenu, 200, f); // On lit maximum 200 caractères du fichier, on stocke le tout dans la str contenu
        printf("%s", contenu);        // On affiche la chaîne

        fclose(fichier);
    }
}
