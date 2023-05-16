
//jogo adivinha com mais funcionalidades

#include <stdio.h>
#include <stdlib.h>


int main(){
    int resp, tentativas, adivinha, novamente;
    
    do{
        tentativas = 0;
        adivinha = rand() % 10 + 1;
        do{
            printf("Digite um numero: ");
            scanf("%d", &resp);
        
            if(resp != adivinha){
            printf("%d eh incorreto, tente novamente\n\n", resp);
            }
        tentativas++;
    }while(resp != adivinha);
    
    printf("%d eh o numro correto\n", resp);
    printf("Numero de tentativas %d\n", tentativas);
    printf("Dseja jogar novamente?:(0 = nao, 1 = sim)\n");
    scanf("%d", &novamente);
        
    }while(novamente == 1);
    return 0;
}