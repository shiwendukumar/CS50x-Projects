#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    /*Check Validity of the key:
      1. Key should not contain any alphabet more than once
      2. Case-insensitive
      3. Contain 26 letters
      4. All should be alphabets only
    */

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }

            for (int j = 0; j < 26; j++)
            {
                if (i == j)
                {
                    continue;
                }
                else
                {
                    if (argv[1][i] == argv[1][j])
                    {
                        printf("Usage: ./substitution key\n");
                        return 1;
                    }
                }
            }
        }
    }

    // After Key verified for correctness
    // Get plaintext input from user
    string input = get_string("plaintext: ");

    // Cipher the text
    for (int k = 0; k < strlen(input); k++)
    {
        if (islower(input[k]))
        {
            input[k] = tolower(argv[1][input[k] - 97]);
        }
        else if (isupper(input[k]))
        {
            input[k] = toupper(argv[1][input[k] - 65]);
        }
    }

    // Print results
    printf("ciphertext: %s\n", input);

    return 0;
}
