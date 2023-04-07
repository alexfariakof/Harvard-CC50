// make recover
// check50 cs50/problems/2023/x/recover
// style50 recover.c
// submit50 cs50/problems/2023/x/recover


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    else
    {

        char *fileName = argv[1];
        FILE *inputFile = fopen(fileName, "r");
        if (inputFile == NULL)
        {
            fprintf(stderr, "Erro: Arquivo não pode ser aberto %s.\n", fileName);
            return 1;
        }

        BYTE buffer[512];
        int count = 0;
        FILE *outputFile = NULL;
        char imgFileName[8];

        // repetição para leitura do arquivo.raw
        while (fread(&buffer, 512, 1, inputFile) == 1)
        {
            // Testando do 1ª, 2ª, 3ª buffer e a os s primeiros quatro bits == 1110 do 4ª buffer
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                if (!(count == 0))
                {
                    fclose(outputFile);
                }

                sprintf(imgFileName, "%03i.jpg", count);
                outputFile = fopen(imgFileName, "w");
                count++;
            }

            if (!(count == 0))
            {
                fwrite(&buffer, 512, 1, outputFile);
            }
        }
        fclose(inputFile);
        fclose(outputFile);
        return 0;
    }
}