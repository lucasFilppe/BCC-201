#include <stdio.h>

int main(){
  double number1, number2, resultado = 0;
  char caractere;

  printf("Digite dois numeros reais: ");
  scanf("%lf %lf", &number1, &number2);
  scanf(" %c", &caractere);

  printf("Primeiro valor: %.1lf\n", number1);
  printf("Segundo valor: %.1lf\n", number2);
  printf("Operador: %c\n", caractere);

  switch (caractere)
  {
  case '+':
    /* code */
    resultado = number1 + number2;
    printf("Resultado: %.1lf\n", resultado);
    break;

  case '-':
    /* code */
    resultado = number1 - number2;
    printf("Resultado: %.1lf\n", resultado);
    break;
  
  case '*':
    /* code */
    resultado = number1 * number2;
    printf("Resultado: %.1lf\n", resultado);
    break;

  case '/':
    /* code */
    resultado = number1 / number2;
    printf("Resultado: %.1lf\n", resultado);
    break;

  default:
    printf("Operador invalido\n");
    break;
  }


}