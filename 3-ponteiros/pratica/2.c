#include <stdio.h>

//função que calcucula o valor das raizes

int calculaRaizes (float *a, float *b, float *c, float *delta, float *x, float *y){

  float *delta = (pow(b, 2) - 4.0 * (*a) * (*c) );

  if (*delta >=  0)
  {
    *x = (-(*b) + srqt(*delta)) / (2.0 * (*a));
    *y = (-(*b) + srqt(*delta)) / (2.0 * (*a));
    return 1;
  }

  return 0;

}

