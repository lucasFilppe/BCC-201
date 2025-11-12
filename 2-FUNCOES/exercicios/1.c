#include <stdio.h>
#define Limite_Percentual 0.25
#define NOTA_MINIMA 6.0

//função que rtorna se aluno foi aprovado ou nao
int aprovado(int numTotalAulas, int numFaltas, double nota) {
    double faltas_maximas = (double)numTotalAulas * Limite_Percentual;

    // Condição de REPROVAÇÃO por FALTA
    if (numFaltas > faltas_maximas) {
        return 0; // Reprovado por falta
    }
    
    // Condição de REPROVAÇÃO por NOTA
    if (nota < NOTA_MINIMA) {
        return 0; // Reprovado por nota
    }
    
    // Se não reprovou por nenhum dos motivos, está APROVADO
    return 1;
}

int main(){

  int numTotalAulas, numFaltasAluno;
  double nota;

  printf("Digite o taltal de aula o numero de faltas e a nota: ");
  scanf("%d %d %lf", &numTotalAulas, &numFaltasAluno, &nota);

  if(aprovado(numTotalAulas, numFaltasAluno, nota) == 1){
    printf("aluno aprovado\n");
  }
  else
    printf("aluno reprovado\n");

  return 0;
}