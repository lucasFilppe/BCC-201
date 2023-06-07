#include <stdio.h>
#include <math.h>

//função que calcucula o valor das raizesle
int calculaRaizes (double *a, double *b, double *c, double *x, double *y){

  double delta = pow((*b), 2) - 4.0  * (*c);

  if (delta >=  0)
  {
    *x = (-(*b) + sqrt(delta) / 2.0 * (*a));
    *y = (-(*b) -sqrt(delta) / 2.0 * (*a));
    return 1;
  }

  return 0;
}

int main(){
  double a, b ,c , x, y;

  scanf("%lf %lf %lf", &a, &b, &c);

  if(calculaRaizes(&a, &b, &c, &x, &y) == 1)
  {
    printf("x1 = %.2lf\n", x);
    printf("x2 = %.2lf\n", y);
  }
  
  return 0;
}

