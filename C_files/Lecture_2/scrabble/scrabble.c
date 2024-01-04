#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main()
{
    // Create score array
    int score[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");

    // Initialize scores
    int score_p1 = 0, score_p2 = 0;

    // Calculate score of player 1
    for (int i = 0; i < strlen(p1); i++)
    {
        if (isalpha(p1[i]))
        {
            p1[i] = tolower(p1[i]);
            int x = p1[i] - 97;
            score_p1 += score[x];
        }
    }

    // Calculate score of player 2
    for (int j = 0; j < strlen(p2); j++)
    {
        if (isalpha(p2[j]))
        {
            p2[j] = tolower(p2[j]);
            int y = p2[j] - 97;
            score_p2 += score[y];
        }
    }

    // Compare the scores and print the result
    if (score_p1 > score_p2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score_p1 < score_p2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}
