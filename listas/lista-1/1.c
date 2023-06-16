#include <stdio.h>

// ler tamanho  do vetor
void lerVetor(int *v, int n){
  for (int i = 0; i < n; i++)
  {
    printf("V[%d] = ", i);
    scanf("%d", &v[i]);
  }
  printf("\n\n");
}

//retorna menor numero de um array
int menor(int *v, int n){
  int menorNum = v[0];

  //veorifica menor
  for (int i = 1; i < n; i++)
  {
    if(v[i] < menorNum){
      menorNum =  v[i];
    }
  }
  return menorNum;
}

int main(){

  int n, menorNumero;

  printf("Digite a quantidade de numeros para verificar o menor: ");
  scanf("%d", &n);

  int vetor[n];

  lerVetor(vetor, n);

  menorNumero = menor(vetor, n);

  printf("O menor eh: %d\n\n", menorNumero);
  return 0;
}