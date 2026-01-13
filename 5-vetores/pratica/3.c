#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Necessário para usar o tempo como semente

#define TAM_VETOR 20 // Tamanho real do vetor de números
#define MAX_VALOR 10 // Valor máximo que o número pode ter

void imprimiOcorrencia(int A[], int tamanhoVetor) {
    // Usamos um vetor de 11 posições para contar de 1 a 10
    // O [0] será ignorado para facilitar a lógica
    int contadores[11] = {0}; 

    for (int i = 0; i < tamanhoVetor; i++) {
        if (A[i] >= 1 && A[i] <= 10) {
            contadores[A[i]]++;
        }
    }

    for (int i = 1; i <= 10; i++) {
        printf("Ocorrencias de %d: %d\n", i, contadores[i]);
    }
}

int main() {
    int n;
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    printf("Digite o limite superior para o sorteio (ate 10): ");
    scanf("%d", &n);

    if (n >= 1 && n <= 10) {
        int numeroAleatorio[TAM_VETOR];

        printf("Numeros gerados: ");
        for (int i = 0; i < TAM_VETOR; i++) {
            numeroAleatorio[i] = 1 + (rand() % n);
            printf("%d ", numeroAleatorio[i]);
        }
        printf("\n\n");

        imprimiOcorrencia(numeroAleatorio, TAM_VETOR);
    } else {
        printf("Numero invalido! Digite entre 1 e 10.\n");
    }

    return 0;
}