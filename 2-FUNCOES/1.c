#include <stdio.h>


//funço de conversao de graus para radianos
double converteGrausRadianos(){
    double pi = 3.14;

    double graus, radianos;

    printf("Digite o valor em Graus: ");
    scanf("%lf", &graus);

    double radianos = (graus * (pi / 180))
}

//função para exibir menu de conversor de angulos
void converteAngulos(){
    int opcao;
    printf("\n");
    printf("Qual a unidade de origem:\n");
    printf("\n");

    printf("1) Graus\n");
    printf("2) Radianos\n");

    printf("Selecione uma opção: ");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        converteAngulos
    }
    

}

//função para exibir menu conversor de unidades
void converteUnidades(){
    int opcao;
    printf("1) Angulo\n");
    printf("2) Temperatura\n");
    printf("\n");
    printf("Digite uma opçao: ");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        converteAngulos();
    }

    /*else if (opcao == 2)
    {
        converteTemperatura();
    }*/

    else
    {
        printf("Opção invalida\n");
    }
    
    printf("\n");
}
int main(){

    converteUnidades();



    return 0;
}