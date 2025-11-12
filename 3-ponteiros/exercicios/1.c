#include <stdio.h>

int main(){
  int valor;
  scanf("%d", &valor);

  int *p = &valor;

  *p = *p * *p;

  printf("valor ao quadrado = %d\n", valor);
  return 0;
}