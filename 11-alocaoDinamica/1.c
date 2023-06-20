#include <stdio.h>
#include <stdlib.h>

int main(){

    //aloca memoria dinamicamente
    double *num = malloc(sizeof(double));

    //altera o conteudo da memoria apontado por num para 3.5
    *num = 3.5;

    printf("Endereço de menmoria: %p\n", num);
    printf("Valor da memoria: %lf\n", *num);
    return 0;
}