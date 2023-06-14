#include <stdio.h>

void leMatriz(int x[][10], int m, int n){
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("Matriz[%d][%d]: ", i, j);
      scanf("%d", &x[i][j]);   
    }
     printf("\n");
  }
  printf("\n");

}

void imprimeMatriz(int x[][10], int m, int n){
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", x[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

void calculaProduto (int x[][10], int y[][10], int a, int b){

  int produto[10][10];

  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < b; j++)
    {
      produto[i][j] = x[i][j] * y[i][j];
    }
    
  }
  imprimeMatriz(produto, a, b);
}

int main(){

  int m, n, p, q;
  int a[10][10], b[10][10];
  printf("Digite as dimendoes: ");
  scanf("%d %d %d %d", &m, &n, &p, &q);

  if ((m <= 10) && (n <= 10) && (p <= 10) && (q <= 10))
  {
    if (p == q)
    {
      printf("Digite a primeira matriz:\n");
      leMatriz(a, m, p);

      printf("\n\n");

      printf("Digite a segunda matriz:\n");
      leMatriz(b, q, n);

      imprimeMatriz(a, m, p);
      imprimeMatriz(b, q, n);

      calculaProduto(a, b, m, q);
      
    }
    
  }
  

  return 0;
}