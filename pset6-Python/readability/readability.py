# python readability.c
# check50 cs50/problems/2023/x/sentimental/readability
# style50 readability.py
# submit50 cs50/problems/2023/x/sentimental/readability

from cs50 import get_string


def main():
    texto = get_string("Digite o texto a ser Analisado: ")
    countVariables(texto)


def countVariables(texto):
    letras = 0
    frases = 0
    # initialize palavras as 1 to account for first word
    palavras = 1
    # loop through each character and count variables
    for i in range(len(texto)):
        if texto[i].isalnum():
            letras += 1
        elif texto[i].isspace() and texto[i + 1]:
            palavras += 1
        elif texto[i] == '.' or texto[i] == '?' or texto[i] == '!':
            frases += 1
    # pass variables to func to calculate grade
    calcGrade(letras, palavras, frases)


def calcGrade(letras, palavras, frases):
    # calculate grade
    avgletras = float(letras / palavras * 100)
    avgfrases = float(frases / palavras * 100)
    grade = round(float(0.0588 * avgletras - 0.296 * avgfrases - 15.8))

    # print results
    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print("Grade", grade)


if __name__ == "__main__":
    main()