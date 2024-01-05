#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int number_of_letters(string input);
int number_of_words(string input);
int number_of_sentences(string input);

int main()
{
    string input = get_string("Text :");
    int letter = number_of_letters(input);
    int words = number_of_words(input);
    int sentences = number_of_sentences(input);

    float L = ((float) letter / (float) words) * 100.0;
    float S = ((float) sentences / (float) words) * 100.0;
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

    return 0;
}

int number_of_letters(string input)
{
    int count = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (isalpha(input[i]))
        {
            count++;
        }
    }
    return count;
}

int number_of_words(string input)
{
    int count = 1;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

int number_of_sentences(string input)
{
    int count = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!')
        {
            count++;
        }
    }
    return count;
}
