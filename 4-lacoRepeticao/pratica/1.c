/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

//funçaõ que retorna um fatorial de um numero passado por parametro
long long fat(int n){
    int i = n;
    long long fatorial = 1;
    while(i >= 1){
        fatorial *= i;
        i--;
    }
    return fatorial;
}

int main(){
    int num;
    
    printf("Digte um numero: ");
    scanf("%d", &num);
    
    printf("%d! = %lld\n", num, fat(num));
}