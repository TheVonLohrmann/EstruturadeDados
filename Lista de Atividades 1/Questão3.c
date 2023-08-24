#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto
{
    float X;
    float Y;
};

// Função para calcular a distância entre dois pontos
float calculardist(struct ponto P1, struct ponto P2){
    float Dx = P2.X - P1.X;
    float Dy = P2.Y - P1.Y;
    return sqrt(Dx * Dx + Dy * Dy);
}

// Função para calcular a inclinação da reta que conecta dois pontos
float calcularincli(struct ponto P1, struct ponto P2){
    float Dx = P2.X - P1.X;
    float Dy = P2.Y - P1.Y;

    if (Dx == 0)
    {
        // Evitar divisão por zero
        return INFINITY;
    } else {
        return Dy / Dx;
    }
}

int main(){

    struct ponto P1 = {2.0, 4.0};
    struct ponto P2 = {6.0, 8.0};

    // Calculando e imprimindo a distância entre os pontos
    float distancia = calculardist(P1,P2);
    printf("|--------------------------------------------|\n");
    printf("| Distancia entre os pontos: %.2f\n", distancia);

    // Calculando e imprimindo a inclinação da reta que conecta os ponto
    float inclinacao = calcularincli(P1,P2);
    if (isinf(inclinacao)) {
        printf("| Inclinacao: Vertical\n");
        printf("|--------------------------------------------|\n");
    } else {
        printf("| Inclinacao: %.2f\n", inclinacao);
        printf("|--------------------------------------------|\n");
    }

    return 0;
}