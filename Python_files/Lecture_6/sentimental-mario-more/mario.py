# TODO
while True:
    try:
        height = int(input('Height: '))
        if height > 0 and height < 9:
            break
    except ValueError:
        print('Invalid input')

# Print the pyramid
for i in range(height):
    for j in range(height - i - 1):
        print(' ', end='')
    for k in range(i + 1):
        print('#', end='')
    print('  ', end='')
    for l in range(i + 1):
        print('#', end='')
    print()