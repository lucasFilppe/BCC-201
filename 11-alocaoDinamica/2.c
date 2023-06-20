#include <stdlib.h>
#include <stdio.h>

void leVetor(int *v, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
}

int *maior(int *v, int n)
{
    int *maior = v;
    for (int i = 1; i < n; i++)
        if (v[i] > *maior)
            maior = v + i;
    return maior;
}

int main()
{
    int n, *v;
    scanf("%d", &n);
    v = malloc(n * sizeof(int));
    leVetor(v, n);
    int *valor = maior(v, n);
    printf("Maior = %d\n", *valor);
    free(v);
    return 0;
}