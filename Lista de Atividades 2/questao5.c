/*
Questão 5 - 
Escreva um programa em C que ordene uma matriz bidimensional (uma matriz de inteiros, por exemplo)
usando o algoritmo de ordenação por inserção.
*/
#include <stdio.h>


void printMatrix(int arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


void insertionSort(int arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            int currentElement = arr[i][j];
            int k = j - 1;
            
            while (k >= 0 && arr[i][k] < currentElement) {
                arr[i][k + 1] = arr[i][k];
                k--;
            }
            
            arr[i][k + 1] = currentElement;
        }
    }
}

int main() {
    int matriz[][3] = {{3, 1, 5}, {2, 4, 6}, {5, 8, 2}, {7, 0, 1}};
    int linhas = sizeof(matriz) / sizeof(matriz[0]);
    int colunas = sizeof(matriz[0]) / sizeof(matriz[0][0]);

    printf("Matriz original:\n");
    printMatrix(matriz, linhas, colunas);

    insertionSort(matriz, linhas, colunas);

    printf("\nMatriz ordenada em ordem decrescente:\n");
    printMatrix(matriz, linhas, colunas);

    return 0;
}
