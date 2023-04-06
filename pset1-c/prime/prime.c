
/*
Números primos são definidos como números inteiros maiores que 1, cujos únicos fatores são 1 e ele mesmo.
Portanto, 3 é primo porque seus únicos fatores são 1 e 3, enquanto 4 é composto e não primo, porque é o produto de 2 × 2.
Neste laboratório, você escreverá um algoritmo para gerar todos os números primos em um intervalo especificado pelo do utilizador.
*/
// check50 cs50/labs/2023/x/prime
// style50 prime.c

#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}


bool prime(int number)
{
    if (number < 2)
    {
        return false;
    }
    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

/*
:) Input of 1 and 10 yields all prime numbers between 1 and 10, inclusive
:( Input of 10 and 25 yields all prime numbers between 10 and 25, inclusive
    expected "11\n13\n17\n19...", not "11\n13\n15\n17..."
:( Input of 50 and 60 yields all prime numbers between 50 and 60, inclusive
    expected "53\n59", not "51\n53\n55\n57..."
*/
