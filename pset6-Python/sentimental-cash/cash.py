# python cash.py
# check50 cs50/problems/2023/x/sentimental/cash
# style50 cash.py
# submit50 cs50/problems/2023/x/sentimental/cash

from cs50 import get_float

qtdeMoedas = 0

while True:
    centavosReceber = get_float("Entre com o valor a receber: ")
    if (centavosReceber > 0):
        break
centavosReceber = round(int(centavosReceber * 100))

while centavosReceber > 0:
    while centavosReceber >= 25:
        qtdeMoedas += 1
        centavosReceber -= 25

    while centavosReceber >= 10:
        qtdeMoedas += 1
        centavosReceber -= 10

    while centavosReceber >= 5:
        qtdeMoedas += 1
        centavosReceber -= 5

    while centavosReceber >= 1:
        qtdeMoedas += 1
        centavosReceber -= 1
print(qtdeMoedas)
