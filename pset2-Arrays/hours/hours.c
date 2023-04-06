/*
Suponha que você esteja fazendo o CS50 (se estiver lendo isso, provavelmente está!) e gastando tempo todas as semanas em cada conjunto de problemas.
Você pode estar se perguntando quantas horas você gastou aprendendo ciência da computação, em média ou no total! Neste programa,
você completará uma função que calcula, com base na entrada do usuário, um número total de horas ou um número médio de horas em um determinado número de dias.
A mainfunção solicita ao usuário o número de semanas que um usuário está tomando CS50 e, em seguida, cria uma matriz com tantos elementos. Observe que,
após recuperar alguns dados, o programa solicita que o usuário digite “T” ou “A” — “T” deve (mas ainda não!) imprimir o número total de horas que o usuário inseriu,
enquanto “A ” deve (mas ainda não!) imprimir as horas médias que o usuário inseriu. Observe que o do whileloop usa toupperpara colocar em maiúscula a letra
inserida antes de ser salva na variável output. Em seguida, a printffunção chama calc_hours. Observe a sintaxe envolvida ao passar um array para uma função.
Para completar calc_hours, primeiro totalize as horas salvas na matriz em uma nova variável. Em seguida, dependendo do valor de output,
retorne essa soma ou o número médio de horas.
*/

//check50 cs50/labs/2023/x/hours
//style50 hours.c


#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    float total_hours = 0;
    for (int i = 0; i < weeks; i++)
    {
        total_hours += hours[i];
    }
    if (output == 'T')
    {
        return total_hours;
    }
    else if (output == 'A')
    {
        return total_hours / weeks;
    }
    else
    {
        return -1;
    }
}