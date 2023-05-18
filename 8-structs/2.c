//Estruturas aninhadas
#include <stdio.h>

typedef struct {
    int dia;
    char mes[10];
    int ano;
 } Data;

 typedef struct {
    int pecas;
    float preco;
    Data diaVenda;
 } Venda;

 int main()
 {
 // exemplo de declaração
 Venda v = {20, 110.0, {7, "Novembro", 2015} };

 // exemplo de uso:
 printf("Ano da venda: %d\n", v.diaVenda.ano);

 return 0;
 }