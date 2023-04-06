/*
Digamos que temos uma população de nlhamas. A cada ano, n / 3novas lhamas nascem e n / 4morrem.
Por exemplo, se começássemos com n = 1200lhamas, então no primeiro ano, 1200 / 3 = 400novas lhamas nasceriam e 1200 / 4 = 300lhamas morreriam.
No final daquele ano, teríamos 1200 + 400 - 300 = 1300lhamas.
Para tentar outro exemplo, se começássemos com n = 1000lhamas, no final do ano teríamos 1000 / 3 = 333.33novas lhamas.
Não podemos ter uma porção decimal de uma lhama, então vamos truncar o decimal para que 333novas lhamas nasçam. 1000 / 4 = 250as lhamas vão morrer,
então vamos acabar com um total de 1000 + 333 - 250 = 1083lhamas no final do ano.
*/
// check50 cs50/labs/2023/x/population
// style50 population.c
// submit50 cs50/labs/2023/x/population

#include <cs50.h>
#include <stdio.h>
int main(void)
{
    // TODO: Prompt for start size
    int start_size;
    int end_size;
    int new_size;
    int n = 0;
    do
    {
        start_size = get_int("Start size: ");
    } while (start_size < 9);
    // TODO: Prompt for end size
    do
    {
        end_size = get_int("End size: ");
    } while (end_size < start_size);
    // TODO: Calculate number of years until we reach threshold
    if (start_size != end_size)
    {
        do
        {
            if (n == 0)
            {
                new_size = start_size + (start_size / 3) - (start_size / 4);
            }
            else
            {
                new_size = new_size + (new_size / 3) - (new_size / 4);
            }
            n++;
        } while (new_size < end_size);
    }
    // TODO: Print number of years
    printf("Years: %i\n", n);
}