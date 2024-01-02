#include <stdio.h>

int main()
{
    int change;

    // Get correct input from user
    do
    {
        printf("Change owed: ");
        scanf("%d", &change);
    }
    while (change <= 0);

    // Calculate number of quarters
    int quarters = 0;
    while (change >= 25)
    {
        change = change - 25;
        quarters++;
    }

    // Calculate number of dimes
    int dimes = 0;
    while (change >= 10)
    {
        change = change - 10;
        dimes++;
    }

    // Calculate number of nickels
    int nickels = 0;
    while (change >= 5)
    {
        change = change - 5;
        nickels++;
    }

    // Calculate number of pennies
    int pennies = 0;
    while (change >= 1)
    {
        change = change - 1;
        pennies++;
    }

    // Calculate total number of coins and print
    int count = quarters + dimes + nickels + pennies;
    printf("%d\n", count);

    return 0;
}
