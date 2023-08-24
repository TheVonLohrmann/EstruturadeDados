#include <stdio.h>
#include <stdlib.h>

struct pessoa // Defineção do struct pessoa
{
    char nome[30];
    int idade;
    float altura;
};

int main(){

    struct pessoa individuo; //variável do tipo Pessoa
    
    // Declarando os valores 
    printf("|--------------------------------------------|\n");
    printf("|           Declaracao de individuo          |\n");
    printf("|--------------------------------------------|\n");
    printf("| Escreva o nome:");
    scanf(" %s", individuo.nome); // caracteres não sao valores únicos por isso não precisam do &
    printf("| Escreva a idade:");
    scanf(" %d", &individuo.idade);
    printf("| Escreva a altura:");
    scanf(" %f", &individuo.altura);

    // Imprimindo os valores declarados
    printf("|--------------------------------------------|\n");
    printf("|             dados do individuo             |\n");
    printf("|--------------------------------------------|\n");
    printf("| Nome : %s\n", individuo.nome);
    printf("| Idade : %d\n", individuo.idade);
    printf("| Altura : %f\n", individuo.altura);
    printf("|--------------------------------------------|\n");

    return 0;
}
