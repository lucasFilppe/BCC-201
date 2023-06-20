/* Crie uma função que:
1 recebe um vetor v e seu tamanho n por parâmetro;
2 cria um novo vetor por alocação dinâmica, preenchendo-o com o
conteúdo de v em ordem inversa;
3 retorna este novo vetor.
Dica: utilize o protótipo a seguir:
1 int *inverso(int *v, int n);
Crie um exemplo de utilização desta função no método main().
Não se esqueça de liberar memória!
*/
#include <stdio.h>
#include <stdlib.h>

int* inverso( int *v, int n){
  int *vinv = malloc(n * sizeof(int));
  for(int i = 0; i < n; i++){
    vinv[i] = v[n-1-i];
  }

  return vinv;
}

int main(){
  int v[5] = {1, 2 , 3 , 4, 5};
  int *invertido = inverso(v, 5);

  for (int i = 0; i < 5; i++)
  {
    printf("%d ", invertido[i]);
  }

  printf("\n");
  free(invertido);
  return 0;
  
}