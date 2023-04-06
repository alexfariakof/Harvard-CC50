// make caesar.c
// check50 cs50/problems/2022/x/caesar
// style50 caesar.c

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string encriptar(string, int);

int main(int argc, char *argv[])
{

    if (argc == 2)
    {
        int key = 0;
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: Erro ./caesar key\n");
                return 1;
            }
        }

        key = atoi(argv[1]);
        string plainText = get_string("plaintext: ");
        printf("ciphertext: %s\n", encriptar(plainText, key));

        return 0;
    }

    printf("Usage: ./caesar key\n");
    return 1;
}

string encriptar(string plaintText, int key)
{
    int valor = 65;
    int scecretKey;
    for (int i = 0, n = strlen(plaintText); i < n; i++)
    {
        scecretKey = 256;

        if (!isalpha(plaintText[i]))
        {
            continue;
        }

        if (isupper(plaintText[i]))
        {
            scecretKey = 'A';
        }
        else
        {
            scecretKey = 'a';
        }
        plaintText[i] = (plaintText[i] + key - scecretKey) % 26 + scecretKey;
    }
    return plaintText;
}