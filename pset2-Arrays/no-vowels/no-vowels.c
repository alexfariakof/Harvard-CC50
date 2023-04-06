// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

// check50 cs50/labs/2023/x/no-vowels
// style50 no-vowels.c

#include <cs50.h>
#include <stdio.h>

char *replace(char *input)
{
    char *output = (char *)malloc(strlen(input) + 1);
    int i;
    for (i = 0; i < strlen(input); i++)
    {
        switch (input[i])
        {
            case 'a':
            case 'A':
                output[i] = '6';
                break;
            case 'e':
            case 'E':
                output[i] = '3';
                break;
            case 'i':
            case 'I':
                output[i] = '1';
                break;
            case 'o':
            case 'O':
                output[i] = '0';
                break;
            default:
                output[i] = input[i];
                break;
        }
    }
    output[i] = '\0';
    return output;
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s word\n", argv[0]);
        return 1;
    }
    char *result = replace(argv[1]);
    printf("%s\n", result);
    free(result);
    return 0;
}
