// make readability
// check50 cs50/problems/2022/x/readability
// style50 readability.c


// Niveis de Leitura 'índice  Coleman-Liau '
// índice = 0,0588 * L - 0,296 * S - 15,8
// make readability.c
// check50 cs50/problems/2022/x/readability
// style50 readability.c

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int letras = 0;
    int palavras = 0;
    int countIsPalavra = 1;
    int frases = 0;

    float L = 0;
    float S = 0;
    float indiceColemanLiau = 0;

    string texto = get_string("Digite o texto a ser Analisado:");

    //texto = "Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, and what is the use of a book, thought Alice without pictures or conversation?";
     //texto = "When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.";
    int tamanhoTexto = strlen(texto);

    for (int i = 0; i < tamanhoTexto; i++)
    {
        if (isalnum(texto[i]))
        {
            letras++;
        }

        if ((isalpha(texto[i - 1]) && texto[i] == ' ')
        || (isalpha(texto[i - 1]) && texto[i] == ' ' && texto[i + 1] == ' ')
        || (isalpha(texto[i - 1]) && texto[i] == '.')
        || (isalpha(texto[i - 1]) && texto[i] == '.' && texto[i + 1] == ' ')
        || (isalpha(texto[i - 1]) && texto[i] == '!')
        || (isalpha(texto[i - 1]) && texto[i] == '!' && texto[i + 1] == ' ')
        || (isalpha(texto[i - 1]) && texto[i] == '?')
        || (isalpha(texto[i - 1]) && texto[i] == '?' && texto[i + 1] == ' ')
        || (isalpha(texto[i - 1]) && texto[i] == ':')
        || (isalpha(texto[i - 1]) && texto[i] == ':' && texto[i + 1] == ' ')
        || (isalpha(texto[i - 1]) && texto[i] == ',')
        || (isalpha(texto[i - 1]) && texto[i] == ',' && texto[i + 1] == ' ')
        || (isalpha(texto[i - 1]) && texto[i] == ';')
        || (isalpha(texto[i - 1]) && texto[i] == ';' && texto[i + 1] == ' ')
        || (isalpha(texto[i - 1]) && texto[i] == '-')
        || (isalpha(texto[i - 1]) && texto[i] == '-' && (isalpha(texto[i + 1]))))
        {
            palavras++;
        }

        if (texto[i] == '.' || texto[i] == '!' || texto[i] == '?')
        {
            frases++;
        }
    }

    L = (float)letras / (float)palavras * 100;
    S = (float)frases / (float)palavras * 100;

    //printf("Letras: %d\n", letras);
    //printf("Palavras: %d\n", palavras);
    //printf("frases: %d\n", frases);
    //printf("L: %f\n", L);
    //printf("S: %f\n", S);
    //printf("calcdeL: %f\n", (0.0588 * L));
    //printf("calcdeS: %f\n", 0.296 * S);
    //printf("Result: %f\n", (0.0588 * L) - (0.296 * S));
    //printf("Result Arred: %f\n", (0.0588 * L) - (0.296 * S));
    //printf("Result Arred: %f\n", (0.0588 * L) - (0.296 * S) - 15.8);

    indiceColemanLiau = 0.0588 * L - 0.296 * S - 15.8;

    if (indiceColemanLiau >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (indiceColemanLiau <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(indiceColemanLiau));
    }
}