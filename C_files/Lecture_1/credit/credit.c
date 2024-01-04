#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool checksum (long long input);
int sum_of_digits(int num);
int number_of_digits(long long input);
bool american_express(long long input);

int main()
{
    //Get input from user
    long long input;
    printf("Number: ");
    scanf("%lld", &input);

    if (checksum(input))
    {
        if (american_express(input))
        {
            printf("AMEX\n");
        }
        printf("Valid\n");
    }
    else
    {
        printf("Invalid\n");
    }

    return 0;
}

//Luhn's Algorithm function
bool checksum (long long input)
{
    int final_sum = 0;

    //Calculate sum of digits of even place digit multiply by 2
    long long temp1 = input;
    while (temp1 != 0)
    {
        temp1 = temp1 / 10;
        int digit = temp1 % 10;
        int mul = (digit * 2);
        final_sum += sum_of_digits(mul);
        temp1 = temp1 / 10;
    }

    //Calculate sum of odd placed digits
    long long temp2 = input;
    while (temp2 != 0)
    {
        final_sum += temp2 % 10;
        temp2 = temp2 / 100;
    }

    //Return true of false based on Luhn's algorithm
    if (final_sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Sum of digits function
int sum_of_digits(int num)
{
    int sum = 0;
    long long temp = num;
    while (temp != 0)
    {
        sum += (temp % 10);
        temp = temp / 10;
    }
    return sum;
}

//Number of digits function
int number_of_digits(long long input)
{
    int digits = 0;
    while (input != 0)
    {
        input = input / 10;
        digits++;
    }
    return digits;
}

//American Express Function
bool american_express(long long input)
{
    if (number_of_digits(input) == 15)
    {
        if (input / 10000000000000 == 34 || input / 10000000000000 == 37)
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}