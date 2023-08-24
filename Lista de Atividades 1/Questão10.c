#include <stdio.h>
#include <stdbool.h>

struct Moeda {
    float dolar;
    float euro;
};

float dolarparaeuro(float valor, struct Moeda moedas){
    return valor * (moedas.euro / moedas.dolar);
}

float europaradolar(float valor, struct Moeda moedas){
    return valor * (moedas.dolar / moedas.euro);
}

int main() {
    struct Moeda cambio;
    cambio.dolar = 1.0; // Taxa de câmbio atual: 1 dólar = 1 dólar
    cambio.euro = 0.9; // Taxa de câmbio atual: 1 dólar = 0.9 euro

    int escolha;
    float valor;

    printf("|----------------------------------------|\n");
    printf("|             Loja de Cambio             |\n");
    printf("|----------------------------------------|\n");
    printf("| [1] Dolar para Euro\n");
    printf("| [2] Euro para Dolar \n");
    printf("| Digite o numero da opcao: ");
    scanf(" %d", &escolha);

    printf("| Digite o valor: ");
    scanf("%f", &valor);

    float valornovo;

    if (escolha == 1) {
        valornovo = dolarparaeuro(valor, cambio);
        printf("|----------------------------------------|\n");
        printf("| %.2f dolares e igual a %.2f euros      \n", valor, valornovo);
        printf("|----------------------------------------|\n");
    } else if (escolha == 2) {
        valornovo = europaradolar(valor, cambio);
        printf("|----------------------------------------|\n");
        printf("| %.2f euros e igual a %.2f dolares      \n", valor, valornovo);
        printf("|----------------------------------------|\n");
    } else {
        printf("|----------------------------------------|\n");
        printf("|             Opcao invalida             |\n");
        printf("|----------------------------------------|\n");
    }

    return 0;
}