//aritmetica de vetor
#include <stdio.h>

double media(double vetor[], int tamanho){
    double resultado = 0;

    for (int i = 0; i < tamanho; i++)
    {
        resultado += *(vetor + 1);
    }
    return resultado/ tamanho;
}

int main(){
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    double v[n];

    printf("Valores do vetor: ");
    //ler valores do vetor
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &v[i]);
    }
    double valor = media(v, n);
    printf("Media = %lf\n", valor);
    return 0;
}