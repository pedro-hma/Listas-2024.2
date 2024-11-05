# include <stdio.h>
# include <time.h>
# include <stdlib.h>

void bubbleSort(int *arry, int a);
void insertionSort(int *arry, int a);
void selectionSort(int *arry, int a);

int main(){
    int tamanhos[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000,};
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    FILE *arq = fopen("tempos.xlsx", "w");

    fprintf(arq, "Tamanho,Condicao,BubbleSort,InsertionSort,SelectionSort\n");

    for(int i = 0; i < numTamanhos; i++){
        int n = tamanhos[i];
        int *arr = (int *)malloc(n * sizeof(int));
        if(arr == NULL){
            printf("Falha na alocação de memória para tamanho %d\n", n);
            break;
        }
        preencherVetorDesordenado(arr, n);
        double tempoBubble = calcularTempo(bubbleSort, arr, n);
        preencherVetorOrdenado(arr, n);
        double tempoInsertion = calcularTempo(insertionSort, arr, n);
        preencherVetorDecrescente(arr, n);
        double tempoSelection = calcularTempo(selectionSort, arr, n);

        fprintf(arq, "%d,Desordenado,%lf,%lf,%lf\n", n, tempoBubble, tempoInsertion, tempoSelection);

        free(arr);

        if (tempoBubble > 300000 || tempoInsertion > 300000 || tempoSelection > 300000) {
            tamanhos[i] = tamanhos[i] / 2;
        }
    }
    fclose(arq);
    return 0;
}

void bubbleSort(int *arry, int a){
     for(int i =0; i < a; i++){
        for(int j = 0 ; j < a - i; j++){
            if (arry[j] > arry[j + 1]) {
                int temp = arry[j];
                arry[j] = arry[j + 1];
                arry[j + 1] = temp;
             }
        }
    }
}

void insertionSort(int *arry, int a){
    for (int i = 1; i < a; i++){
        int chave = arry[i];
        int j = i - 1;

        while (j >= 0 && arry[j] > chave){
            arry [j+1] = arry[j];
             j = j - 1;
        }
        arry [j+1] = chave;
    } 
}

void selectionSort(int *arry, int a){
    for (int i = 0; i < a - 1; i++){
        int minIdx = i;
        for (int j = i+1 ; i < a; j++){
            if (arry < arry[minIdx]) {
                minIdx = j;
            } 
        }
        int temp = arry[minIdx];
        arry[minIdx] = arry[i];
        arry[i] = temp;
    }
}