#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

int main(void)
{
    char buffer[10];

    int tamanhoPiramide = get_int("Entre como tamanho da piramide:");
    while (true)
    {
        if (tamanhoPiramide >= 1 && tamanhoPiramide <= 8)
        {
            break;
        }
        else
        {
            tamanhoPiramide = get_int("Entre como tamanho da piramide valido :");
        }
    }

    strcpy(buffer, "#");
    printf("%s\n", buffer);
    for (int i = 0; i < tamanhoPiramide; i++)
    {
        strcpy(buffer, "#");
        for (int j = -1; j < i; j++)
        {
            strcat(buffer, "#");
        }
        printf("%s\n", buffer);
    }
}