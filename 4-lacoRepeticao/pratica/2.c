#include <stdio.h>

int ehPrimo(int n){
  if (n <= 1) return 0; // Números menores ou iguais a 1 não são primos

    // Testa se n é divisível por qualquer número de 2 até n-1
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0; // Se encontrar um divisor, não é primo
        }
    }

    return 1; // Se sair do laço sem encontrar divisores, é primo
}

int main(){

  int n;

  printf("Digite um número: ");
  scanf("%d", &n);

  if(ehPrimo(n)== 1){
    printf("%d eh um numero primo!\n", n);
  }
  else
    printf("%d nao eh um numero primo!\n", n);
  return 0;
}