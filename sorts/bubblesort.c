#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int array[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void testar_tamanhos() {
    int tamanhos[] = {1000, 5000, 10000, 20000, 40000, 80000};
    int num_testes = sizeof(tamanhos) / sizeof(tamanhos[0]);
    
    for (int i = 0; i < num_testes; i++) {
        int tamanho = tamanhos[i];
        int *array = (int*)malloc(tamanho * sizeof(int));
        
        // Preenche com números aleatórios
        for (int j = 0; j < tamanho; j++) {
            array[j] = rand() % 10000;
        }
        
        clock_t inicio = clock();
        bubblesort(array, tamanho);
        clock_t fim = clock();
        
        double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        
        printf("Tamanho: %d elementos | Tempo: %f segundos\n", tamanho, tempo);
        
        free(array);
    }
}

int main() {
    srand(time(NULL));
    printf("Testando Bubble Sort com diferentes tamanhos:\n");
    testar_tamanhos();
    return 0;
}