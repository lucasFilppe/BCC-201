#include <stdio.h>
#include <math.h>

//função que retorna maior
double maior(double x, double y){
  double numMaior = x;

  if (y > x)
  {
    numMaior = y; 
  }
  
  return numMaior;
}

//função que retorna maior
double menor(double x, double y){
  double numMenor = x;

  if (y > x)
  {

    numMenor = y; 
  }
  
  return numMenor;
}

int main(){

  double num1 , num2, menorNumero, maiorNumero;

  printf("Digite dois numeros");
  scanf("%lf %lf", &num1, &num2);

  maiorNumero = maior(num1, num2);
  menorNumero = menor(num1, num2);

  printf("Quadrado do maior numero %lf\n\n", pow(maiorNumero, 2));
  printf("Raiz quadrada do menor numero: %lf\n\n", sqrt(menorNumero));
  return 0;
}