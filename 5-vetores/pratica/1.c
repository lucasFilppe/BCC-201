#include <stdio.h>

void imprimeVetor(int *v, int n){
  for (int i = 0; i < n; i++)
  {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int main(){

  int vetor[10];//declara vetor de 10 posições

  //atribuindo 1 a v[0] e v[1]
  vetor[0] = 1;
  vetor[1] = 1;

  vetor[2] = vetor[0] + vetor[1];//vetor na posição 2 recebi o valor dos dois primeiros indices
  for (int i = 3; i < 10; i++)
  {
    vetor[i] = vetor[i - 1] + vetor[i - 2]; //calacula valor dos indices restantes a partir da soma dos dois termos anteriores
  }

  imprimeVetor(vetor, 10);//imprime vetor

  printf("\n");
  
  return 0;
}