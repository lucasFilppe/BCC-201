#include <stdio.h>

//declarando novo tipo
 struct Tempo {
    int horas;
    int minutos;
    int segundos;
 };

 int main()
 {
    struct Tempo tempo;
    int segundos;

    printf("\nDigite o tempo em segundos: ");
    scanf("%d", &segundos);

    tempo.horas = segundos / 3600;
    tempo.minutos = (segundos % 3600) / 60;
    tempo.segundos = (segundos % 3600) % 60;

    printf("\nTempo em horas, minutos e segundos:");
    printf(" %d:%d:%d\n\n", tempo.horas, tempo.minutos, tempo.segundos);

 return 0;
 }