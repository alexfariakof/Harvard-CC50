// make substitution
// check50 cs50/problems/2022/x/substitution
// style50 substitution.c


#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

const int N = 26;
const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, string argv[])
{
    // Verifica o número correto de argumentos recebidos;
    if (argc != 2)
    {
        printf("Entre com apenas uma linha.\n");
        return 1;
    }

    // Verifica se tem a quantidade de caracteres = 26
    if (strlen(argv[1]) < N)
    {
        printf("Quantidade de caracteres inválida.\n");
        return 1;
    }

    // Check validity of key content
    int letras[N];
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        // verificando se apenas letras do alfabeto são utilizadas
        if (!((argv[1][i] >= 'a' && argv[1][i] <= 'z') ||
              (argv[1][i] >= 'A' && argv[1][i] <= 'Z')))
        {
            printf("Key deve conter apenas letras.\n");
            return 1;
        }
        else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
        {
            argv[1][i] = toupper(argv[1][i]);
        }

        // Verificando letras repetidas
        for (int j = 0; j < N; j++)
        {
            if (argv[1][i] == letras[j])
            {
                printf("Key não poder ter letras repetidas.\n");
                return 1;
            }
        }

        letras[i] = argv[1][i];
    }

    // Entrada do  plaintext
    string plaintext = get_string("plaintext: ");
    int l = strlen(plaintext);
    char ciphertext[l + 1];

    // Convert to ciphertext
    for (int i = 0; i < l; i++)
    {
        if (isupper(plaintext[i]) != 0) // Check if uppercase and if so use standard  alphabet/key
        {
            for (int j = 0; j < N; j++)
            {
                if (plaintext[i] == alphabet[j])
                {
                    ciphertext[i] = argv[1][j];
                    break;
                }
            }
        }
        else if (islower(plaintext[i]) != 0) // If lowercase use lowercase alphabet and key
        {
            for (int j = 0; j < strlen(alphabet); j++)
            {
                if (plaintext[i] == tolower(alphabet[j]))
                {
                    ciphertext[i] = tolower(argv[1][j]);
                    break;
                }
            }
        }
        else // Finally replace non letters
        {
            ciphertext[i] = plaintext[i];
        }
    }
    // Add null char to make it a string
    ciphertext[l] = '\0';
    // Print result and exit
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
