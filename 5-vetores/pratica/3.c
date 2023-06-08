#include <stdio.h>
#include <stdlib.h>

//função para imprimir numero de vezes de ocoorencia de numero
void imprimiOcorrencia(int A[]; int num){

  int cont1 = 0;
  int cont2 = 0;
  int cont3 = 0;
  int cont4 = 0;
  int cont5 = 0;
  int cont6 = 0;
  int cont7 = 0;
  int cont8 = 0;
  int cont9 = 9;
  int cont10 = 0;

  for (int i = 0; i < num; i++)
  {
    if[A[i] == 1]{
      cont1++;
    }
    if[A[i] == 2]{
      cont2++;
    }
    if[A[i] == 3]{
      cont3++;
    }
    if[A[i] == 4]{
      cont4++;
    }

    if[A[i] == 5]{
      cont5++;
    }
  
    if[A[i] == 6]{
      cont6++;
    }
    if[A[i] == 7]{
      cont7++;
    }
    if[A[i] == 8]{
      cont8++;
    }
    if[A[i] == 9]{
      cont9++;
    }
    if[A[i] == 10]{
      cont10++;
    }
  }
  printf("Ocorencias de 1: %d\n", cont1);
  printf("Ocorencias de 2: %d\n", cont2);
  printf("Ocorencias de 3: %d\n", cont3);
  printf("Ocorencias de 4: %d\n", cont4);
  printf("Ocorencias de 5: %d\n", cont5);
  printf("Ocorencias de 6: %d\n", cont6);
  printf("Ocorencias de 7: %d\n", cont7);
  printf("Ocorencias de 8: %d\n", cont8);
  printf("Ocorencias de 9: %d\n", cont9);
  printf("Ocorencias de 10: %d\n", cont10);
}

int main(){

  int n;

  //le um numero inteiro
  printf("Digite um numero inteiro que seja menor ou igual a 10: ");
  scanf("%d", &n);

  int numeroAleatorio[10];//declarando vetor de numeros aleatorios

  //se numero for menor ou igaual a 500, entao:
  if (n <= 10)
  {
    //enquanto i for menor que 20
    printf("Numero gerado: ");
    for(int i = 0; i < 20; i++){
      
      numeroAleatorio[i] = 1 + (rand() % n);//gera numero aleatorio de 1 a 10
      printf("%d ", numeroAleatorio[i]);
    }
     printf("\n");
     imprimiOcorrencia(numeroAleatorio, n);
  }

  else
  {
    printf("Numero inavlido\n");
  }
  
  
  return 0;
}