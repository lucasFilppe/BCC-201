#include <stdio.h>


//função que retora 1 se valores sao validos e 0 se nao
int ehValido(int x , int y){
   
    if((x < y)  && (x % 2 == 0 && y % 2 == 0 )){
       return 1;
    }
    return 0;
}


//função que imprime asteristico de retangulo
void imprimeAsteristicos(int x, int y){
    for(int i = x; i <= y; i++) {
        printf("\t");
        for(int j = 1; j <= i ; j++){
            printf("*");
        }
       printf("\n");
    }
}


int main(){


    int x, y;


    do {
    printf("Digite os valores de x e y: ");
    scanf("%d %d", &x, &y);


   
    if(x > y){
            printf("x deve ser menor que y\n");
        }


    else if(x % 2 == 1 || y % 2 == 1 ){
            printf("Apenas numeros pares sao aceitos\n");
    }


    else{
        imprimeAsteristicos(x, y);
        break;
    }


    }while(ehValido(x, y) != 1);


   
    return 0;
}
