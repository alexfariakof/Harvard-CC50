#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

   char aspa = atoi("39");
   char aspaD = atoi("34");


    char* cPonteiro = "abc";
    char c = (int)'a';
    string cvet = "abc";
    float real = 4.2578784;
    int convertForcado = real*10000;
    printf("%c\n", aspa);
    printf("%c\n", aspaD);

    printf("%f\n", real);
    printf("%i\n", convertForcado);
    printf("%f\n", (float)convertForcado/10000);
    printf("%c\n", (char)c);
    printf("%c %C %C \n", (char)cPonteiro[0], (char)cPonteiro[1], (char)cPonteiro[2]);
    printf("%c %c %c \n", (char)cvet[0], (char)cvet[1], (char)cvet[2]);


}