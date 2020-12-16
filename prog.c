#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <stdarg.h>

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

void test_calcul_valeur(double x,Poly p1)
{
    printf("\n~~~~ %s(%g)~~~~\n", __func__,x);

    double result= calcul_valeur(x,p1);

    printf("\nrésultat :%g\n",result);
}

/*void test_open_from_file(void)
{
    printf("\n~~~~ %s~~~~\n", __func__);
    char poly[150];

    bool result=open_from_file("TEST.txt", *poly);

    printf("\nrésultat :%d\n",result);
    printf("\nrésultat :%s\n",*poly);
}*/

int main(void)
{
    int POLY_DEG_MAX = 10;

    //printf("Hello world \n");
    int tailleP1=5;
    Poly p1=create_empty(tailleP1);
    p1.coef[0] = 2;
    p1.coef[1] = 0;
    p1.coef[2] = 4;
    //p1.coef[3] = 6;
    p1.coef[4] = 5;   

    int taileP2=3;
    Poly p2=create_empty(taileP2);;
    p2.coef[0] = 6;
    p2.coef[1] = 7;
    p2.coef[2] = 5;

    //printPoly(p1);
    //printPoly(p2);


    //printPoly(p1);
    //printPoly(p2);

    //test_printPoly(p1);

    //test_addition_poly(p1,p2);

    //test_soustraction_poly(p1,p2);

    //test_multiplication_poly(p1, p2);

    test_calcul_valeur(4,p2);

    //test_open_from_file();

    //printf("%g", powf(3.5,2.5));

    //char text="2x^2+3x+3";

    //create_poly(1, 2, 3, 4, 5, 6, 7);
    /*Poly p4;
    p4=create_poly(3, 14.5, 18.0, 17.5);
    printPoly(p4);*/

    return 0;
}