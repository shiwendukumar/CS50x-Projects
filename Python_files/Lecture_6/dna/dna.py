import csv
import sys


def main():

    # TODO: Check for command-line usage
    if (len(sys.argv) != 3):
        print("Correct usage: python dna.py databases.csv sequences.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for name in reader:
            database.append(name)
    
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as file1:
        sample = file1.read()
    counts = {}

    # TODO: Find longest match of each STR in DNA sequence
    # SYNTAX SOURCE: https://note.nkmk.me/en/python-dict-keys-values-items/
    for key in database[0].keys():
        if key == 'name':
            continue
        else:
            counts[key] = longest_match(sample, key)

    # TODO: Check database for matching profiles
    # SYNTAX SOURCE: https://note.nkmk.me/en/python-dict-keys-values-items/
    for row in database:
        match = True
        for key in row.keys():
            if key == 'name':
                continue
            if int(row[key]) != counts[key]:
                match = False
                break

        if match == True:
            print(row['name'])
            sys.exit(0)

    print('No Match')

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
