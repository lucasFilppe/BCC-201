#include<stdio.h>

typedef struct {
    int pecas;
    float preco;
 } Venda;

//Função que cria e retorna uma nova venda (usando scanf):
Venda novaVenda()
{
    Venda v;
    printf("Digite a quantidade e o valor da venda:\n");
    scanf("%d %f", &v.pecas, &v.preco);
    return v;
}

//função que calcula varias vendas
void imprimeTotal(Venda v[], int n)
{
    Venda total = {0, 0.0};
    for (int i = 0; i < n; i++) {
        total.pecas += v[i].pecas;
        total.preco += v[i].preco;
    }

    printf("Nro peças: %d\n", total.pecas);
    printf("Preço total: %f\n", total.preco);
 }

int main() {
    Venda vendas[50]; // cria um array de estruturas
     int n = 0, opcao; // inicialmente não temos nenhuma venda
    
    do {
        printf("Digite 1 para entrar uma venda\n");
        printf(" 2 para imprimir o total\n");
        printf(" 0 para terminar\n");    
        scanf("%d", &opcao);
 
        switch (opcao) {
            case 1:
            vendas[n] = novaVenda();
            n++;
            break;
 
        case 2:
        imprimeTotal(vendas, n);
        break;
    }
 
    } while (opcao != 0);
    return 0;
}