#include <stdio.h>

void trocar(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    float num1, num2, num3;

    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    printf("Digite o terceiro número: ");
    scanf("%f", &num3);

    // Ordenando os números em ordem crescente
    if (num1 > num2)
        trocar(&num1, &num2);
    if (num2 > num3)
        trocar(&num2, &num3);
    if (num1 > num2)
        trocar(&num1, &num2);

    printf("Os números em ordem crescente: %.2f, %.2f, %.2f\n", num1, num2, num3);

    return 0;
}
