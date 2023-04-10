# python mario.py
# check50 cs50/problems/2023/x/sentimental/mario/more
# style50 mario.py
# submit50 cs50/problems/2023/x/sentimental/mario/more

from cs50 import get_int

while True:
    n = get_int('Altura: ')
    if n < 1 or n > 8:
        n = get_int('Altura: ')
    if n >= 1 or n <= 8:
        break
for i in range(n):
    print((n - 1 - i) * " ", end="")
    print((i + 1) * "#" + "  " + (i + 1) * "#")