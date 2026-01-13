#include <stdio.h>

void calculaTemperatura(int v[], int n){
  int soma = 0;
  int diaTemperaturaAcimaDaMedia = 0;
  int diaTemperaturaAbaixoDaMedia = 0;

  for (int i = 0; i < n; i++)
  {
    soma += v[i];//soma temperaturas
  }

  //calcula media
  int media = soma / n;


  //verifa se tenmperatura eh maior ou menor que a media
  for (int i = 0; i < n; i++)
  {
    if(v[i] > media){
      diaTemperaturaAcimaDaMedia++;
    }
    if (v[i] < media)
    {
      diaTemperaturaAbaixoDaMedia++;
    }
    
  }
  
  //imprime temperatura acima e abaixo da media
  printf("Temperaturas acima da media: %d\n", diaTemperaturaAcimaDaMedia);
  printf("Temperaturas abaixo da media: %d\n", diaTemperaturaAbaixoDaMedia);
  
}
int main(){

  int n;

  //ler quantidade de temperatura a serem lidas
  printf("Digite a quantidade de temperaturas : ");
  scanf("%d", &n);

  int v[n];//declara vetor de temperaturas

  //le temperaturas
  printf("Digite as temperaturas desses %d dias: ", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &v[i]);
  }
  printf("\n");

  //imprime temperaturas
  for (int i = 0; i < n; i++)
  {
    printf("Dia %d : %d Celsius\n",  i + 1, v[i]);
  }

  printf("\n\n");

  calculaTemperatura(v,n);//chama função que calcula temperaturas acima e abaixo da media

  return 0;
}