//função que cria uma matriz
#include <stdio.h>
#include <stdlib.h>

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

  int **matriz = criaMatriz(4, 4);

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      matriz[i][j] = 0;
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
  
  for (int i = 0; i < 4; i++)
  {
    free(matriz[i]);
  }
  
  free(matriz);

  return 0;
}