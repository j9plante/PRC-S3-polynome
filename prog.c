#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <stdarg.h>

#include <stdlib.h>

#include <math.h>

#include "polynome.h"

void test_printPoly(Poly p1)
{
    printf("\n~~~~ %s~~~~\n", __func__);
    printPoly(p1);
}

void test_addition_poly(Poly p1, Poly p2)
{
    printf("\n~~~~ %s~~~~\n", __func__);

    Poly p3 = addition_poly(p1, p2);

    printPoly(p3);
}

void test_soustraction_poly(Poly p1, Poly p2)
{
    printf("\n~~~~ %s~~~~\n", __func__);

    Poly p3 = soustraction_poly(p1, p2);

    printPoly(p3);
}

void test_multiplication_poly(Poly p1, Poly p2)
{
    printf("\n~~~~ %s~~~~\n", __func__);

    Poly p3 = multiplication_poly(p1, p2);

    printPoly(p3);
}

void test_calcul_valeur(double x, Poly p1)
{
    printf("\n~~~~ %s(%g)~~~~\n", __func__, x);

    printPoly(p1);

    double result = calcul_valeur(x, p1);

    printf("\nrésultat :%g\n", result);
}

void test_create_poly(void)
{
    printf("\n~~~~ %s~~~~\n", __func__);
    Poly p1 = create_poly(6, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1);
    printPoly(p1);
}

void test_get_poly_from_str(void)
{
    printf("\n~~~~ %s~~~~\n", __func__);
    char str[] = "10x^3+5x^2+7x^1+6x^0";
    Poly result = get_poly_from_str(str);

    printPoly(result);
}

void test_poly_to_file(Poly p1)
{
    printf("\n~~~~ %s~~~~\n", __func__);
    poly_to_file("test1.txt", p1);
    //printPoly(p1);
}

void test_get_str_from_file(void)
{
    get_string_from_file("input.txt");
}

int main(int argc, char **argv)
{
    //On définit les polynomes utilisé pour les tests :
    int tailleP1 = 5;
    Poly p1 = create_empty(tailleP1);
    p1.coef[0] = 2;
    p1.coef[1] = 0;
    p1.coef[2] = 4;
    //p1.coef[3] = 6;
    p1.coef[4] = 5;

    int taileP2 = 3;
    Poly p2 = create_empty(taileP2);
    p2.coef[0] = 6;
    p2.coef[1] = 7;
    p2.coef[2] = 5;

    //Notice d'utilisation :
    if (argc == 1)
    {
        printf("\nPour effectuer tout les tests : all");
        printf("\n-Pour saisir un polynome : poly poly1");
        printf("\n-Pour additionner 2 polynomes : poly1 add poly2");
        printf("\n-Pour soustraire 2 polynomes : poly1 sous poly2");
        printf("\n-Pour multiplier 2 polynomes : poly1 multi poly2");
        printf("\n-Pour calculer la valeur d'un polynome en un point : calc x poly1");
        printf("\n-Formatage des polynomes ax^n+bx^n-1+...+c\n");
        printf("\nATENTION : degré max=10\n");
    }
    // Si le seul argument reçu est "all" : on lance toutes les fonctions de test
    if (argc == 2 && strcmp(argv[1], "all") == 0)
    {
        printf("On fait touts les tests !!");

        test_printPoly(p1);
        test_addition_poly(p1, p2);
        test_soustraction_poly(p1, p2);
        test_multiplication_poly(p1, p2);
        test_create_poly();
        test_get_poly_from_str();
        test_calcul_valeur(4, p2);
        test_poly_to_file(p1);
        test_get_str_from_file();
    }
    //Si on saisit poly, on extrait le polynome saisit :
    if (argc == 3 && strcmp(argv[1], "poly") == 0)
    {
        Poly p3 = get_poly_from_str(argv[2]);
        printPoly(p3);
    }
    //On additonne les polynomes saisits:
    if (argc == 4 && strcmp(argv[2], "add") == 0)
    {
        printf("Add command line");
        Poly p4 = get_poly_from_str(argv[1]);
        Poly p5 = get_poly_from_str(argv[3]);

        printPoly(addition_poly(p4, p5));
    }

    if (argc == 4 && strcmp(argv[2], "sous") == 0)
    {
        printf("Sous command line");
        Poly p4 = get_poly_from_str(argv[1]);
        Poly p5 = get_poly_from_str(argv[3]);

        printPoly(soustraction_poly(p4, p5));
    }

    if (argc == 4 && strcmp(argv[2], "multi") == 0)
    {
        printf("Multi command line");
        Poly p4 = get_poly_from_str(argv[1]);
        Poly p5 = get_poly_from_str(argv[3]);

        printPoly(multiplication_poly(p4, p5));
    }

    if (argc == 4 && strcmp(argv[1], "calc") == 0)
    {
        printf("Calc command line");
        double x;
        sscanf(argv[2],"%lf",&x);
        printf("\n%g\n",x);
        Poly p5 = get_poly_from_str(argv[3]);

        printf("\nRésultat : %g\n",calcul_valeur(x,p5));
    }

    return 0;
}