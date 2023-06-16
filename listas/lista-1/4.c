#include <stdio.h>

int main() {
    float valorProduto, valorVenda;
    
    printf("Digite o valor do produto: ");
    scanf("%f", &valorProduto);
    
    if (valorProduto < 20.00) {
        valorVenda = valorProduto + (valorProduto * 0.45); // Lucro de 45%
    } else {
        valorVenda = valorProduto + (valorProduto * 0.30); // Lucro de 30%
    }
    
    printf("O valor de venda do produto é: R$ %.2f\n", valorVenda);
    
    return 0;
}