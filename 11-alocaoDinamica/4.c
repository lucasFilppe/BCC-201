//transposta

#include <stdio.h>
#include <stdlib.h>


int **tranposta(int **m, int l, int c){
  int **t = malloc(c * sizeof(int*));

  //alocando a memoria necessaria
  for (int i = 0; i < c; i++)
  {
    t[i] = malloc(l * sizeof(int));
  }

  //preenchendo a matiz t com os valores traspostos
  for (int i = 0; i < c; i++)
  {
    for (int j = 0; j < l; j++)
    {
      t[i][j] = m[j][i];
    }
    
  }

  return t;
  
}

int main(){
  int **m = malloc(sizeof(int *) * 2);
  
  for (int i = 0; i < 2; i++)
  {
    m[i] = malloc(sizeof(int) * 2);
  }
  
  m[0][0] = 0;
  m[0][1] = 1;
  m[1][0] = 2;
  m[1][1] = 3;

  int **t = tranposta(m, 2, 2);

  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      printf("%d ", t[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}