#include <stdio.h>

int main() {
    int x, y;
    int entradaValida = 0;

    // Lógica de validação
    while (!entradaValida) {
        printf("Digite os valores de x e y: ");
        scanf("%d %d", &x, &y);

        if (x % 2 != 0 || y % 2 != 0) {
            printf("Apenas numeros pares sao aceitos.\n\n");
        } 
        else if (x >= y) {
            printf("Erro: x deve ser menor que y.\n\n");
        } 
        else {
            entradaValida = 1; // Sai do loop
        }
    }

    printf("\n");

    // Lógica para desenhar o trapézio
    // Começamos com x asteriscos e aumentamos de 2 em 2 até atingir y
    for (int i = x; i <= y; i += 2) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}