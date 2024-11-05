#include <stdio.h>      // Para printf, fprintf, FILE, fopen, fclose
#include <stdlib.h>     // Para malloc, free, rand
#include <time.h>       // Para clock, CLOCKS_PER_SEC

// Declarações das funções
void bubbleSort(int *arr, int n);
void insertionSort(int *arr, int n);
void selectionSort(int *arr, int n);
double calcularTempo(void (*sortFunction)(int*, int), int *arr, int n);
void preencherVetorDesordenado(int *arr, int n);
void preencherVetorOrdenado(int *arr, int n);
void preencherVetorDecrescente(int *arr, int n);

// Implementação dos algoritmos de ordenação
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

// Função para calcular o tempo de execução
double calcularTempo(void (*sortFunction)(int*, int), int *arr, int n) {
    clock_t inicio = clock();
    sortFunction(arr, n);
    clock_t fim = clock();
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;  // Tempo em milissegundos
}

// Funções para preencher vetores em diferentes condições
void preencherVetorDesordenado(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
}

void preencherVetorOrdenado(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

void preencherVetorDecrescente(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

int main() {
    int tamanhos[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    FILE *arquivo = fopen("tempos.xlsx", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    fprintf(arquivo, "Tamanho,Condicao,BubbleSort,InsertionSort,SelectionSort\n");

    for (int i = 0; i < numTamanhos; i++) {
        int n = tamanhos[i];
        int *arr = (int *)malloc(n * sizeof(int));
        
        if (arr == NULL) {
            printf("Falha na alocação de memória para tamanho %d\n", n);
            break;
        }

        // Teste com vetor desordenado
        preencherVetorDesordenado(arr, n);
        double tempoBubble = calcularTempo(bubbleSort, arr, n);

        preencherVetorOrdenado(arr, n);
        double tempoInsertion = calcularTempo(insertionSort, arr, n);

        preencherVetorDecrescente(arr, n);
        double tempoSelection = calcularTempo(selectionSort, arr, n);

        fprintf(arquivo, "%d,Desordenado,%lf,%lf,%lf\n", n, tempoBubble, tempoInsertion, tempoSelection);

        free(arr);

        if (tempoBubble > 300000 || tempoInsertion > 300000 || tempoSelection > 300000) {
            tamanhos[i] = tamanhos[i] / 2;
        }
    }

    fclose(arquivo);
    return 0;
}
