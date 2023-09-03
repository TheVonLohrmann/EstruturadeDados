#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int vet[5], i, n;
    srand(time(NULL));
    printf("|--------------------------------------------------|\n");
    for ( i = 0; i < 5; i++)
        vet[i] = rand() % 1001;
        printf("|vetor gerado:\n");
    
    for(i=0;i<5;i++){
        printf("|> %d\n", vet[i]);
    }
    printf("| Qual e o valor que deseja buscar:");
    scanf("%d", &n);

    for(i=0;i<5;i++)
    if (vet[i]==n)
    {
        printf("| %d ocorre na posicao %d do vetor.\n", n,i);
        printf("|--------------------------------------------------|");
        return 0;
    }
}