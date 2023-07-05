/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

//celsius
double calculaKelvin(double celsius){
    return celsius + 273.15;
}
double calculaFarenheit(double celsius){
    return (celsius * (9/5)) + 32;     
}

//fução do menu para conversao de Celsius para Fareheit e Kelvin
void menuConversaoCelsis(){
    double celsius;
    
    printf("Digite o valor em Celsius: ");
    scanf("%lf", &celsius);
    
    printf("Valor em Farenheit: %.2lf\n", calculaFarenheit(celsius));
    printf("Valor em Kelvin: %.2lf\n", calculaKelvin(celsius));
    
}

//função que calcula graus para radianos
double calculaGrausRadianos(double graus){
    double pi = 3.14;
    return (graus * (pi / 180));
}

//funçao de menu conversao de graus para radianos
void menuConverteGrausRadianos(){

    double graus;

    printf("Digite o valor em Graus: ");
    scanf("%lf", &graus);

    printf("Valor em radianos: %.2lf\n", calculaGrausRadianos(graus));
}

//função que calcula conversao de radianos em graus

double calculaRadianosGraus(double radianos){
    double pi = 3.14;
    return (radianos * (180 / pi));
}

//fução de conversão de radianos em graus
void menuConversaoRadianosGraus(){
    double radianos;

    printf("Digite o valor em radianos: ");
    scanf("%lf", &radianos);

    printf("Valor em graus: %.2lf\n", calculaRadianosGraus(radianos));
}


//função para exibir menu de conversor de angulos
void converteAngulos(){
    int opcao;
    printf("\n");
    printf("Qual a unidade de origem:\n");
    printf("\n");

    printf("1) Graus\n");
    printf("2) Radianos\n");
    printf("\n");
    
    printf("Selecione uma opção: ");
    scanf("%d", &opcao);
    printf("\n");
    
    if (opcao == 1)
    {
        menuConverteGrausRadianos();
    }
    
    else if(opcao == 2){
        menuConversaoRadianosGraus();  
    }

    else{
        printf("Opção invalida\n");
    }

}

void converteTemperatura(){
    int opcao;
    printf("\n");
    printf("Qual a unidade de origem:\n");
    printf("\n");

    printf("1) Celsius\n");
    printf("2) Fareheit\n");
    printf("3) Kelvin\n");
    printf("\n");
    
    printf("Selecione uma opção: ");
    scanf("%d", &opcao);
    printf("\n");
    
    if(opcao == 1){
        menuConversaoCelsis();
    }
    else{
        printf("Entrada invalida\n");
    }
}

//função para exibir menu conversor de unidades
void converteUnidades(){
    int opcao;
    printf("### COVERSOR DE UNIDADES ###\n\n");
    printf("1) Angulo\n");
    printf("2) Temperatura\n");
    printf("\n");
    printf("Digite uma opçao: ");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        converteAngulos();
    }

    else if (opcao == 2)
    {
        converteTemperatura();
    }

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