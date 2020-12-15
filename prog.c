#include <stdio.h>
#include <stdbool.h>
#include "polynome.h"

int main(void)
{
    //TEST COMMIT !!!!
    //TEST COMMIT 2 !!!!
    //TEST COMMIT 2 !!
    
    int POLY_DEG_MAX=10;
    
    //printf("Hello world \n");    

    Poly test;
    test.taille=3;
    test.coef[0]=2;
    test.coef[1]=0;
    test.coef[2]=4;

    printPoly(test);

    return 0;
}