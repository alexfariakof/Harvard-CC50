//check50 cs50/problems/2023/x/bulbs
//style50 bulbs.c
//submit50 cs50/problems/2023/x/bulbs


#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    char message[100];
    printf("Digite uma mensagem: ");
    fgets(message, 100, stdin);

    for (int i = 0; message[i] != '\0'; i++)
    {
        char c = message[i];
        for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
        {
            int bit = (c >> j) & 1;
            print_bulb(bit);
        }
        printf("\n");
    }

    return 0;
}

void print_bulb(int bit)
{

    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB"); // emoji de lâmpada apagada
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1"); // emoji de lâmpada acesa
    }
}
