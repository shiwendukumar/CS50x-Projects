#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for valid key
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key");
                return 1;
            }
        }
    }

    // Take correct key value
    int key = atoi(argv[1]);
    if (key >= 26)
    {
        key = key % 26;
    }

    // Get user text input
    string text = get_string("plaintext: ");

    // Cipher the code
    for (int j = 0; j < strlen(text); j++)
    {
        if (isalpha(text[j]))
        {
            if (isupper(text[j]))
            {
                char x = (((text[j] - 65 + key) % 26) + 65);
                text[j] = x;
            }
            else if (islower(text[j]))
            {
                char x = (((text[j] - 97 + key) % 26) + 97);
                text[j] = x;
            }
        }
    }

    // Print output
    printf("ciphertext: %s\n", text);

    return 0;
}
