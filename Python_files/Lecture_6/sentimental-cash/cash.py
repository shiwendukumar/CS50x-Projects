# TODO
from cs50 import get_float

# Get user input
while True:
    cash = get_float('Change owed: ')
    if cash > 0:
        break

# Convert to cents
cents = cash * 100

# Calculate number of quarters
quarters = int(cents / 25)
cents = cents - quarters * 25

# Calculate number of dimes
dimes = int(cents / 10)
cents = cents - dimes * 10

# Calculate number of nickels
nickels = int(cents / 5)
cents = cents - nickels * 5

# Calculate number of pennies
pennies = int(cents / 1)

# Calculate number of coins to be returned
coins = quarters + dimes + nickels + pennies

# Print the results
print(f'{coins}')