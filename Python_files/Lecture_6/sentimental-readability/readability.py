# Number of letters function
def num_of_letters(input):
    count = 0
    for char in input:
        if char.isalpha():
            count += 1
    return count

# Number of words function
def num_of_words(input):
    count = 1
    for char in input:
        if char == " ":
            count += 1
    return count

# Number of sentences function
def num_of_sentences(input):
    count = 0
    for char in input:
        if char in [".", "!", "?"]:
            count += 1
    return count
        

def main():
    # Get user input
    input_value = input("Text: ")

    # Calculate variables
    letter = num_of_letters(input_value)
    words = num_of_words(input_value)
    sentences = num_of_sentences(input_value)
    L = (letter / words) * 100
    S = (sentences / words) * 100

    # Calculate grade
    grade = round(0.0588 * L - 0.296 * S - 15.8)

    # Print results
    if grade >= 16:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")

if __name__ == "__main__":
    main()

