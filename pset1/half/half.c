/*
Sua função deve usar os parâmetros de entrada, bill, taxe tip, para calcular o valor final. No entanto, como esses valores são porcentagens,
 você terá que fazer algum trabalho para convertê-los em formatos mais apropriados para usar em seu cálculo.

O imposto deve ser adicionado ao valor da conta antes de calcular a gorjeta. Por fim, você devolverá exatamente a metade do valor total,
 incluindo o valor da conta, o imposto e a gorjeta.

*/
//check50 cs50/labs/2023/x/half
//style50 half.c

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float bill = get_float("Bill before tax and tip: ");
    float tax  = bill * get_float("Sale Tax Percent: ") / 100;
    float total_bill = bill + tax;
    float tip = total_bill * get_float("Tip percent: ") / 100;
    float result = (total_bill + tip) / 2;
    printf("$%.2f", result);
}