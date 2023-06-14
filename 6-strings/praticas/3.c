#include <stdio.h>
#include <string.h>

int isPalindrome(char word[]) {
   int length = strlen(word);
   int i, j;

   for (i = 0, j = length - 1; i < j; i++, j--) {
      if (word[i] != word[j]) {
         return 0; // não é um palíndromo
      }
   }

   return 1; // é um palíndromo
}

int main() {
   char word[100];

   while (1) {
      printf("Digite uma palavra (ou FIM para encerrar): ");
      scanf("%s", word);

      if (strcmp(word, "FIM") == 0) {
         break; // encerra o programa
      }

      if (isPalindrome(word)) {
         printf("A palavra '%s' é um palíndromo.\n", word);
      } else {
         printf("A palavra '%s' não é um palíndromo.\n", word);
      }
   }

   return 0;
}