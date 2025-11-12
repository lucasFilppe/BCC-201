#include <stdio.h>

// Função que calcula a duração do jogo em minutos usando ponteiros
int duracaoEmMinutos(int *horaInicio, int *minutoInicio, int *horaFim, int *minutoFim) {
    int inicio = (*horaInicio) * 60 + (*minutoInicio);
    int fim = (*horaFim) * 60 + (*minutoFim);
    int duracao;

    // Caso o jogo termine no outro dia
    if (fim < inicio) {
        fim += 24 * 60;
    }

    duracao = fim - inicio;
    return duracao;
}

int main() {
    int horaInicio, minutoInicio, horaFim, minutoFim;

    printf("Digite a hora e o minuto de inicio do jogo: ");
    scanf("%d %d", &horaInicio, &minutoInicio);

    printf("Digite a hora e o minuto de termino do jogo: ");
    scanf("%d %d", &horaFim, &minutoFim);

    // Passando os endereços das variáveis (&) para a função
    int duracao = duracaoEmMinutos(&horaInicio, &minutoInicio, &horaFim, &minutoFim);

    printf("A duracao total do jogo foi de %d minutos.\n", duracao);

    return 0;
}
