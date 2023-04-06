// make mario.c
// check50 cs50/problems/2022/x/mario/less
// style50 mario.c

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Altura: ");
    }
    while (n > 8 || 1 > n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            printf(" ");
        }

        //Hashes a esquerda
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}