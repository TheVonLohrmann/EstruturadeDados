/*
Questão 2 - 
Compare o desempenho do algoritmo de ordenação por bolha com algoritmo de ordenação o quicksort e
o mergesort, usando arrays de tamanhos diferentes. Meça o tempo de execução e compare os resultado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Implementação do Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Implementação do QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Implementação do MergeSort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    srand(time(NULL));  // Inicializar semente de números aleatórios

    int sizes[] = {1000, 5000, 10000, 50000, 100000};
    clock_t start, end;
    double cpu_time_used;

    for (int i = 0; i < 5; i++) {
        int n = sizes[i];
        int arr[n];

        // Preencher o array com números aleatórios
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 1000000;
        }

        // Medir o tempo para o Bubble Sort
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Bubble Sort para %d elementos: %f segundos\n", n, cpu_time_used);

        // Refazer o array com números aleatórios
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 1000000;
        }

        // Medir o tempo para o QuickSort
        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("QuickSort para %d elementos: %f segundos\n", n, cpu_time_used);

        // Refazer o array com números aleatórios
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 1000000;
        }

        // Medir o tempo para o MergeSort
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("MergeSort para %d elementos: %f segundos\n", n, cpu_time_used);
    }

    return 0;
}
