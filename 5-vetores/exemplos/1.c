#include <stdio.h>

int main(){
    float notas[5];
    float maiorNota = 0;
    for(int i = 1; i <= 5; i++){
        printf("Digit a nota da prova %d: ", i);
        scanf("%f", &notas[i]);

        if(notas[i] > maiorNota){
            maiorNota = notas[i];
        }
    }

    printf("Maior nota %.2f\n", maiorNota);


}