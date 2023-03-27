/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

//funçaõ que converte um valor em Celsius para Farenheit e kelvin
void converteCelsius(float celsius, float *farenheit, float *kelvin){
    *farenheit =  (celsius * (9.0/5.0));
    *kelvin = celsius + 273.15;
}

int main(){
    float c, farenheit, kelvin;
    
    printf("Digite a temperatura atual em celsius: ");
    scanf("%f", &c);
    
    converteCelsius(c, &farenheit, &kelvin);
    
    printf("Temperatura farenheit: %.2f\n", farenheit);
    printf("Temperatura kelvin: %.2f\n", kelvin);
    return 0;
}