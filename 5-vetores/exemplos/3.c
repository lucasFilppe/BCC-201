#include <stdio.h>

//ifunção que retorna maior numero inteiro de um vetot
int maior(int *vetor, int tamanho){
    int maior = vetor[0];
    for (int i = 1; i < tamanho; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
        
    }

    return maior;
    
}

int main(){
    
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int v[n];

    printf("Valores do vetor: ");
    //ler valores do vetor
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    printf("\n");
   
    printf("Maior %d\n",  maior(v, n));
    return 0;
}