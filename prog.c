#include <stdio.h>
#include <stdbool.h>
#include "polynome.h"

int main(void)
{    
    int POLY_DEG_MAX=10;
    
    //printf("Hello world \n");    

    Poly p1;
    p1.taille=3;
    p1.coef[0]=2;
    p1.coef[1]=0;
    p1.coef[2]=4;

    Poly p2;
    p1.taille=3;
    p1.coef[0]=6;
    p1.coef[1]=7.5;
    p1.coef[2]=5.2;

    printPoly(p1);


    void test_printPloy(p1)
    {
        printf("\n~~~~ %s~~~~\n", __func__);
        printPoly(p1);
    }

    return 0;
}