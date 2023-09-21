/*
Questão 4 -
Escreva um programa em C que ordene uma matriz bidimensional 
(uma matriz de inteiros, por exemplo)
usando o algoritmo de quicksor.
*/

#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[][3], int low, int high) {
    int pivot = arr[high][0];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j][0] > pivot) {  
            i++;
            swap(&arr[i][0], &arr[j][0]);
            swap(&arr[i][1], &arr[j][1]);
            swap(&arr[i][2], &arr[j][2]);
        }
    }
    swap(&arr[i + 1][0], &arr[high][0]);
    swap(&arr[i + 1][1], &arr[high][1]);
    swap(&arr[i + 1][2], &arr[high][2]);
    return (i + 1);
}


void quickSort(int arr[][3], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int matriz[][3] = {{3, 1, 5}, {2, 4, 6}, {5, 8, 2}, {7, 0, 1}};
    int linhas = sizeof(matriz) / sizeof(matriz[0]);
    int colunas = sizeof(matriz[0]) / sizeof(matriz[0][0]);

    printf("Matriz original:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    quickSort(matriz, 0, linhas - 1);

    printf("\nMatriz ordenada em ordem decrescente:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
