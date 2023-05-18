//exemplo usando ponteiro
#include <stdio.h>

typedef struct {
    int pecas;
    float preco;
 } Venda;

 void imprimeTotal(Venda *v1, Venda *v2)
 {
    Venda total = {0, 0.0};
    total.pecas = v1->pecas + v2->pecas; //v1->pecas ou (*v1).pecas
    total.preco = v1->preco + v2->preco;
    printf("Nro peças: %d\n", total.pecas);
    printf("Preço total: %.2f\n", total.preco);
 }

 int main()
 {
    Venda v1 = {1, 20}, v2 = {3, 10};
    imprimeTotal(&v1, &v2);
 return 0;
 }