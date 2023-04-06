// make cash.c
// check50 cs50/problems/2022/x/cash
// style50 cash.c

#include <stdio.h>
#include <cs50.h>
#include <math.h>

float getCentavos (void);

int main(void)
{
  int qtdeMoedas = 0;
  float cent = getCentavos();

  while (cent >= 25)
  {
    qtdeMoedas++;
    cent = cent - 25;
  }

  // while we can use dimes, add a dime
  while (cent >= 10)
  {
    qtdeMoedas++;
    cent = cent - 10;
  }

  // while we can use pennies, add a penny
  while (cent >= 5)
  {
    qtdeMoedas++;
    cent = cent - 5;
  }

  // while we can use pennies, add a penny
  while (cent >= 1)
  {
    qtdeMoedas++;
    cent = cent - 1;
  }


  printf("%i\n", qtdeMoedas);
}

float getCentavos(void)
{
  float cents;
  do
  {
    cents = get_float("Troca devida: ");
  } while (cents < 0);
  return (int)round(cents*100);
}

int calcModedaVinteCinco(float cents)
{
  int vinteCinco = 0;
  while (cents >= 25)
  {
    cents = cents - 25;
    vinteCinco++;
  }
  return vinteCinco;
}

int calcModedaDez(float cents)
{
  int dez = 0;
  while (cents >= 10)
  {
    cents = cents - 10;
    dez++;
  }
  return dez;
}

int calcModedaCinco(float cents)
{
  int cinco = 0;
  while (cents >= 5)
  {
    cents = cents - 5;
    cinco++;
  }
  return cinco;
}

int calcModedaUm(float cents)
{
  int um = 0;
  while (cents >= 1)
  {
    cents = cents - 1;
    um++;
  }
  return um;
}