//função que cria uma matriz
#include <stdio.h>

int ** criaMatriz(int n, int m){
  int **matriz;
  matriz = malloc (n * sizeof(int *));

  for (int i = 0; i < n; i++)
  {
    matriz[i] = malloc(m * sizeof(int));
  }
  return matriz;
}


int main(){

  return 0;
}