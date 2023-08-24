#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //em um programa C é necessária para usar o tipo de dado booleano e seus dois valores possíveis: true e false
#include <string.h>
#define N_Diciplinas 3 

struct estudante
{
    char nome[50];
    int matricula;
    float notas[N_Diciplinas];
};

float calcularmedia(struct estudante aluno){

    float somarnota = 0;
    for (int i = 0; i < N_Diciplinas; i++)
    {
        somarnota += aluno.notas[i];
    }
    return somarnota / N_Diciplinas;
}

bool aprovado(struct estudante aluno){ // O uso de valores booleanos (true ou false) torna o código mais legível e compreensível
    float media = calcularmedia(aluno);
    return media >= 7.0;
}

int main(){

    struct estudante alunos;

    printf("|----------------------------------------------------|\n");
    printf("|                Calculadora de media                |\n");
    printf("|----------------------------------------------------|\n");
    printf("| Informe o nome do estudante: ");
    scanf(" %s", alunos.nome);

    printf("| Informe a matricula: ");
    scanf(" %d", &alunos.matricula);

    printf("|----------------------------------------------------|\n");
    printf("| Informe as notas do estudante em %d disiplinas     |\n", N_Diciplinas);
    printf("|----------------------------------------------------|\n");
    for (int i = 0; i < N_Diciplinas; i++)
    {
        printf("| Nota da disciplina %d: ", i + 1);
        scanf("%f", &alunos.notas[i]);
    }
    printf("|----------------------------------------------------|\n");
    printf("| Media do estudante: %.2f\n", calcularmedia(alunos));
    if (aprovado(alunos))
    {
        printf("| O estudante esta aprovado!\n");
        printf("|----------------------------------------------------|\n");
    } else {
        printf("| O estudante esta reprovado!\n");
        printf("|----------------------------------------------------|\n");
    }

    return 0;
}