#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float vermelho = image[i][j].rgbtRed;
            float verde = image[i][j].rgbtGreen;
            float azul = image[i][j].rgbtBlue;

            // calculo da media entre os pixels
            int media = round((vermelho + azul + verde) / 3);

            // Convertendo em 0 e 1 os pixels
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = media;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float vermelho = image[i][j].rgbtRed;
            float verde = image[i][j].rgbtGreen;
            float azul = image[i][j].rgbtBlue;

            // Determina um novo valor de Sepia para cada cor RGB;
            int sepiaRed = round(0.393 * vermelho + 0.769 * verde + 0.189 * azul);
            int sepiaGreen = round(0.349 * vermelho + 0.686 * verde + 0.168 * azul);
            int sepiaBlue = round(0.272 * vermelho + 0.534 * verde + 0.131 * azul);

            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // Percorre somente a metade da largura da imagem e realiza um swap
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++) // coluna
    {

        for (int j = 0; j < width; j++) // linha
        {
            float somaVermelho;
            float somaVerde;
            float somaAzul;
            float denominador;

            somaVermelho = somaVerde = somaAzul = denominador = 0;

            // Média dos valores de todos os pixels que estão dentro de 1 linha e coluna do pixel original (formando uma caixa 3x3).

            for (int coluna = -1; coluna < 2; coluna++)
            {
                for (int linha = -1; linha < 2; linha++)
                {
                    // Verificar se está fora ou dentro ods limites da coluna ou da linha

                    if (i + coluna < 0 || i + coluna >= height)
                    {
                        continue;
                    }

                    if (j + linha < 0 || j + linha >= width)
                    {
                        continue;
                    }

                    // Adicionar as somas
                    somaVermelho += temp[i + coluna][j + linha].rgbtRed;
                    somaVerde += temp[i + coluna][j + linha].rgbtGreen;
                    somaAzul += temp[i + coluna][j + linha].rgbtBlue;
                    denominador++;
                }
            }

            image[i][j].rgbtRed = round(somaVermelho / denominador);
            image[i][j].rgbtGreen = round(somaVerde / denominador);
            image[i][j].rgbtBlue = round(somaAzul / denominador);
        }
    }
    return;
}

// Detect edges ou Arestas
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Operador Sobel
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++) // coluna
    {

        for (int j = 0; j < width; j++) // linha
        {
            float gxVermelho;
            float gxVerde;
            float gxAzul;
            float gyVermelho;
            float gyVerde;
            float gyAzul;

            gxVermelho = gxVerde = gxAzul = gyVermelho = gyVerde = gyAzul = 0;

            // Média dos valores de todos os pixels que estão dentro de 1 linha e coluna do pixel original (formando uma caixa 3x3).
            for (int coluna = -1; coluna < 2; coluna++)
            {
                for (int linha = -1; linha < 2; linha++)
                {
                    // Verificar se está fora ou dentro ods limites da coluna ou da linha

                    if (i + coluna < 0 || i + coluna >= height)
                    {
                        continue;
                    }

                    if (j + linha < 0 || j + linha >= width)
                    {
                        continue;
                    }

                    gxVermelho += temp[i + coluna][j + linha].rgbtRed * Gx[coluna + 1][linha + 1];
                    gxVerde += temp[i + coluna][j + linha].rgbtGreen * Gx[coluna + 1][linha + 1];
                    gxAzul += temp[i + coluna][j + linha].rgbtBlue * Gx[coluna + 1][linha + 1];

                    gyVermelho += temp[i + coluna][j + linha].rgbtRed * Gy[coluna + 1][linha + 1];
                    gyVerde += temp[i + coluna][j + linha].rgbtGreen * Gy[coluna + 1][linha + 1];
                    gyAzul += temp[i + coluna][j + linha].rgbtBlue * Gy[coluna + 1][linha + 1];
                }
            }

            // Calcular operador Sobel
            int vermelho = round(sqrt(pow(gxVermelho, 2) + pow(gyVermelho, 2)));
            int verde = round(sqrt(pow(gxVerde, 2) + pow(gyVerde, 2)));
            int azul = round(sqrt(pow(gxAzul, 2) + pow(gyAzul, 2)));

            if (vermelho > 255)
            {
                vermelho = 255;
            }

            if (verde > 255)
            {
                verde = 255;
            }

            if (azul > 255)
            {
                azul = 255;
            }

            image[i][j].rgbtRed = vermelho;
            image[i][j].rgbtGreen = verde;
            image[i][j].rgbtBlue = azul;
        }
    }
    return;
}
