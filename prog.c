#include <stdio.h>
#include <stdbool.h>
#include "polynome.h"

void test_printPoly(Poly p1)
{
    printf("\n~~~~ %s~~~~\n", __func__);
    printPoly(p1);
}

void test_addition_poly(Poly p1,Poly p2)
{
    printf("\n~~~~ %s~~~~\n", __func__);    

    Poly p3=addition_poly(p1,p2);

    printPoly(p3);
}

void test_soustraction_poly(Poly p1,Poly p2)
{
    printf("\n~~~~ %s~~~~\n", __func__);    

    Poly p3=soustraction_poly(p1,p2);

    printPoly(p3);
}

int main(void)
{
    int POLY_DEG_MAX = 10;

    //printf("Hello world \n");

    Poly p1;
    p1.taille = 3;
    p1.coef[0] = 2;
    p1.coef[1] = 0;
    p1.coef[2] = 4;

    Poly p2;
    p2.taille = 3;
    p2.coef[0] = 6;
    p2.coef[1] = 7.5;
    p2.coef[2] = 5.2;

    //printPoly(p1);
    //printPoly(p2);

    //test_printPoly(p1);

    test_addition_poly(p1,p2);

    test_soustraction_poly(p1,p2);   

    return 0;
}