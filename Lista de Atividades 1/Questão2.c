#include <stdio.h>
#include <stdlib.h>

struct tipo
{
    int valorint;
    float valorflut;
    char letra;
};

int main(){

    struct tipo valores;

    valores.valorint = 50;
    valores.valorflut = 1.50;
    valores.letra = 'A';

    printf("|--------------------------------------------|\n");
    printf("|             dados dos valores              |\n");
    printf("|--------------------------------------------|\n");
    printf("| valor inteiro : %d\n", valores.valorint);
    printf("| valor ponto flutuante : %f\n", valores.valorflut);
    printf("| valor letra : %c\n", valores.letra);
    printf("|--------------------------------------------|\n");

    return 0;
}