def checksum(input):
    final_sum = 0

    # Calculate sum of digits of even-placed digits multiplied by 2
    temp1 = input
    while temp1 != 0:
        temp1, digit = divmod(temp1, 10)
        mul = digit * 2
        final_sum += sum_of_digits(mul)

    # Calculate sum of odd-placed digits
    temp2 = input
    while temp2 != 0:
        final_sum += temp2 % 10
        temp2 //= 100

    # Return True or False based on Luhn's algorithm
    return final_sum % 10 == 0


def sum_of_digits(num):
    return sum(int(digit) for digit in str(num))


def number_of_digits(input):
    return len(str(input))


def american_express(input):
    if number_of_digits(input) == 15:
        return input // 10000000000000 in (34, 37)
    return False


def mastercard(input):
    if number_of_digits(input) == 16:
        return input // 100000000000000 in (51, 52, 53, 54, 55)
    return False


def visa(input):
    if number_of_digits(input) == 13:
        return input // 1000000000000 == 4
    elif number_of_digits(input) == 16:
        return input // 1000000000000000 == 4
    return False


def main():
    # Get input from the user
    input_value = int(input("Number: "))

    # Check conditions
    if checksum(input_value):
        # Check American Express
        if american_express(input_value):
            print("AMEX")
        # Check Mastercard
        elif mastercard(input_value):
            print("MASTERCARD")
        # Check VISA
        elif visa(input_value):
            print("VISA")
        # If checksum is valid but it is none of the cards
        else:
            print("INVALID")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()
