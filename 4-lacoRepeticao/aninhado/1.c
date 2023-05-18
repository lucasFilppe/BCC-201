//tabuada da multiplicação
#include <stdio.h>

int main(){
    int x, y;

    printf("Ddigite os valores de x e y: ");
    scanf("%d %d", &x, &y);

    printf("\nTabuada da multiplicação\n\n");
    printf("   |");
    for (int i = x; i <=  y; i++)
    {
        printf("%3d ", i);
    }
    printf("\n------");

    for (int i = x; i <=  y; i++)
    {
        printf("------");
    }
    printf("\n");

    //calculando e imprimeindo a tabuada
    for (int i = x; i <= y; i++)
    {
        printf("%2d | ", i);
        for (int j = 1; j <= y; j++)
        {
            printf("%2d  ", i * j);
        }
        printf("\n");
    }
    


    
    return 0;
}