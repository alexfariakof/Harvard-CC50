// make scrabble
// check50 cs50/labs/2022/x/scrabble
// style50 scrabble.c


#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Points assinged Alpha Chacters with vector POINTS
string alphaPoints = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    //word1 = "COMPUTER";
    //word2 = "science";

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!");

    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}

int compute_score(string word)
{

    int score = 0;
    int n = strlen(word);
    string out = "";
    string outS = "";
    for (int i = 0; i < n; i++)
    {
        // You can use Points or alphaPoints is the same index
        for (int j = 0; j < strlen(alphaPoints); j++)
        {
            if  (isalpha((char)word[i]) && toupper((char)word[i]) == (char)alphaPoints[j])
            {
                //printf("%c\n", (char)alphaPoints[j]);
                //out += (char)POINTS[j];
                //outS += (char)alphaPoints[j];

                score = score + (int)POINTS[j];
            }
        }
    }
    //printf("%s\n", out);
    //printf("%s\n", outS);
    return score;
}