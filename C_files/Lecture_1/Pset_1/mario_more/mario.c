#include <stdio.h>

int main()
{
    int height;

    // Get correct input from user
    do
    {
        printf("Height: ");
        scanf("%d", &height);
    }
    while (height < 1);

    // Print the pattern
    for (int i = 0; i < height; i++)
    {
        // Print spaces
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        // Print #
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        printf(" ");
        //Print #
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
