// make credit.c
// check50 cs50/problems/2021/x/credit
// style50 credit.c

#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>

long getNumeroCartaoCredito(void);
bool isDigitosValido(string);
bool isCartaoValido(long);

int main(void)
{
    long cartao = getNumeroCartaoCredito();

    if (isCartaoValido (cartao) && cartao != 0)
    {
        // Get starting digits
        long start = (long)cartao;
        do
        {
            start = start / 10;
        } while (start > 100);

        // Next check starting digits for card type
        if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
        {
            printf("MASTERCARD\n");
        }
        else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
        {
            printf("AMEX\n");
        }
        else if (start / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

long getNumeroCartaoCredito(void)
{
    // Get card number
    long cardNumber = get_long("Entre com um cartão Válido :");
    // Count length
    int i = 0;
    long cc = cardNumber;
    while (cc > 0)
    {
        cc = cc / 10;
        i++;
    }

    // Check if length is valid
    if (i != 13 && i != 15 && i != 16)
    {
        return 0;
    }
    return cardNumber;
}

bool isDigitosValido(string cartao)
{
    int digitosCartao = strlen(cartao);
    if (digitosCartao != 13 && digitosCartao != 15 && digitosCartao != 16)
    {
        return false;
    }
    return true;
}

bool isCartaoValido(long cartao)
{
    // Calculate checksum
    int sum1 = 0;
    int sum2 = 0;
    long x = cartao;
    int total = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;
    do
    {
        // Remove last digit and add to sum1
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;
        // Remove second last digit
        mod2 = x % 10;
        x = x / 10;
        // Double second last digit and add digits to sum2
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    } while (x > 0);
    total = sum1 + sum2;

    // Next check Luhn Algorithm
    if (total % 10 != 0)
    {
        //printf("INVALID\n");
        return false;
    }
    return true;
}