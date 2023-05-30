/*Escrever um programa que leia uma matriz, seus elementos e sua
dimensão (m, n ≤ 100). Em seguida, o programa deve:
1 solicitar ao usuário o índice de uma linha (`) e um valor constante (c);
2 multiplicar todos elementos da linha ` por c;
3 imprimir a matriz resultante;*/
#include <stdio.h>

int main()
{
    int matriz[100][100];

    int m, n;
    // lendo as dimensões da matriz
    printf("Digite as dimensões m e n da matriz: ");
    scanf("%d %d", &m, &n);

    // lendo os elementos da matriz
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Digite o valor de matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    int linha, constante;
    printf("Digite o índice da linha a alterar: ");
    scanf("%d", &linha);
    printf("Digite o valor da constante: ");
    scanf("%d", &constante);
    // multiplicando valores da linha *linha* por *constante*
    for (int j = 0; j < n; j++)
        matriz[linha][j] = matriz[linha][j] * constante;
    // imprimindo a matriz resultante
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
    return 0;
}
