#include <stdio.h>


void imprimeVetor(int v[], int n){
  printf("Vetor rotacionado: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", v[i]);
  }

  printf("\n\n");
  
}

void rotacioneEsquerda(int arr[], int size, int n) {
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    
    for (int i = 0; i < size - n; i++) {
        arr[i] = arr[i + n];
    }
    
    for (int i = 0; i < n; i++) {
        arr[size - n + i] = temp[i];
    }
    
}

int main(){
  int n, valor;

  //ler tamanho do vetor
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);

  int vetor[n];

  //lendo vetor
  printf("Digite os valores do vetor: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &vetor[i]);
  }
  printf("\n");

  printf("Digite o valor para rotacionar o vetor a esquerda: ");
  scanf("%d", &valor);

  rotacioneEsquerda(vetor, n, valor);

  imprimeVetor(vetor, n);
  return 0;


}