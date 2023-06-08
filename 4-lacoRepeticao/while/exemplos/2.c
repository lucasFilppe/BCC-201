//calculo media harmonica

#include <stdio.h>

int main(){
    float soma = 0, num;
    int n;

    //entrad
    printf("Calculo da Media Harmonica\n");
    printf("Quantos numoros voce quer digitar: ");
    scanf("%d", &n);
    printf("\n");
    
    int i = 1;
    while(i <= n){
        printf("Numero %d: ", i);
        scanf("%f", &num);
        
        soma = (soma + (1 / num));//calcula soma
        i++;
    }
     printf("\n");
    
    float h = (n / soma);//calcula media harmonica
    printf("Media harmonica: %.2f\n", h);
    
    return 0;
}