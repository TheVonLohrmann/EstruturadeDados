/*
Questão 6 -
Escreva uma função em C que realize uma busca sequencial em uma matriz bidimensional de inteiros para
encontrar um valor específico fornecido pelo usuário. A função deve retornar a posição da primeira ocorrência do valor
ou informar que o valor não foi encontrado.
*/
#include <stdio.h>


int buscaSequencial(int matriz[][3], int rows, int cols, int valor, int *row, int *col) {
    for (*row = 0; *row < rows; (*row)++) {
        for (*col = 0; *col < cols; (*col)++) {
            if (matriz[*row][*col] == valor) {
                return 1;  
            }
        }
    }
    return 0;  
}

int main() {
    int matriz[][3] = {{3, 1, 5}, {2, 4, 6}, {5, 8, 2}, {7, 0, 1}};
    int linhas = sizeof(matriz) / sizeof(matriz[0]);
    int colunas = sizeof(matriz[0]) / sizeof(matriz[0][0]);

    printf("Matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    int valorProcurado;
    printf("\nDigite o valor que deseja procurar na matriz: ");
    scanf("%d", &valorProcurado);

    int row, col;
    if (buscaSequencial(matriz, linhas, colunas, valorProcurado, &row, &col)) {
        printf("Valor encontrado na posição (%d, %d)\n", row, col);
    } else {
        printf("Valor não encontrado na matriz.\n");
    }

    return 0;
}
