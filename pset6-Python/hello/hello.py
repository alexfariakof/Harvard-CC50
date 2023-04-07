# check50 cs50/problems/2023/x/sentimental/hello
# style50 hello.py
# submit50 cs50/problems/2023/x/sentimental/hello

# importando biblioteca
from cs50 import get_string

# imprimindo texto e armazenando valor na variavel nome
nome = get_string('What is your name ?')

# imprimindo hello e o nome contido na variavel
print('hello, ' + nome)
