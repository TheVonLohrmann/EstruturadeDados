/*
Questão 3 - 
Implemente uma versão do algoritmo de ordenação por inserção que ordene em ordem decrescente em
vez de crescente.
*/

#include <stdio.h>


void insertionSortDescending(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("| Array original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    insertionSortDescending(arr, n);

    printf("\n| Array ordenado em ordem decrescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
