#include <stdio.h>

int main() {

  int num1, num2, num3, maior, menor, intermediario;

  printf("Digite os valores: ");
  scanf("%d %d %d", &num1, &num2, &num3);

  // maior
  if (num1 > num2 && num1 > num3) {
    maior = num1;
  } else if (num2 > num1 && num2 > num3) {
    maior = num2;
  } else {
    maior = num3;
  }

  // menor
  if (num1 < num2 && num1 < num3) {
    menor = num1;
  } else if (num2 < num1 && num2 < num3) {
    menor = num2;
  } else {
    menor = num3;
  }

  // intermediário
  if ((num1 != maior) && (num1 != menor)) {
    intermediario = num1;
  } else if ((num2 != maior) && (num2 != menor)) {
    intermediario = num2;
  } else {
    intermediario = num3;
  }

  printf("Menor: %d\n", menor);
  printf("Intermediário: %d\n", intermediario);
  printf("Maior: %d\n", maior);

  return 0;
}
