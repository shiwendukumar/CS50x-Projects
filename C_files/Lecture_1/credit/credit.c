#include <stdio.h>
#include <stdbool.h>

//Function Declaration
bool checksum (long long input);
int sum_of_digits(int num);
int number_of_digits(long long input);
bool american_express(long long input);
bool mastercard(long long input);
bool visa(long long input);

int main()
{
    //Get input from user
    long long input;
    printf("Number: ");
    scanf("%lld", &input);

    //Check conditions
    if (checksum(input))
    {
        //Check American Express
        if (american_express(input))
        {
            printf("AMEX\n");
        }
        
        //Check Mastercard
        else if (mastercard(input))
        {
            printf("MASTERCARD\n");
        }

        //Check VISA
        else if (visa(input))
        {
            printf("VISA\n");
        }

        //If checksum is valid but it is none of the cards
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
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
        return false;
    }
    return false;
}

//Mastercard Function
bool mastercard(long long input)
{
    if (number_of_digits(input) == 16)
    {
        if (input / 100000000000000 == 51 || input / 100000000000000 == 52 || input / 100000000000000 == 53 || input / 100000000000000 == 54 || input / 100000000000000 == 55)
        {
            return true;
        }
        return false;
    }
    return false;
}

//VISA Function
bool visa(long long input)
{
    if (number_of_digits(input) == 13)
    {
        if (input / 1000000000000 == 4 || input / 1000000000000 == 4)
        {
            return true;
        }
        return false;
    }
    else if (number_of_digits(input) == 16)
    {
        if (input / 1000000000000000 == 4 || input / 1000000000000000 == 4)
        {
            return true;
        }
        return false;
    }
    return false;
}

