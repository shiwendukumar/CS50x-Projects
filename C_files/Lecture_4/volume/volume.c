// Modifies the volume of an audio file
// Usage: ./volume input.wav output.wav factor

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
typedef int16_t SAMPLE;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    BYTE temp;
    for (int i = 0; i < HEADER_SIZE; i++)
    {
        fread(&temp, sizeof(temp), 1, input);
        fwrite(&temp, sizeof(temp), 1, output);
    }

    // TODO: Read samples from input file and write updated data to output file
    SAMPLE sample; 
    while (fread(&sample, sizeof(sample), 1, input) != 0)
    {
        sample *= factor;
        fwrite(&sample, sizeof(sample), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
