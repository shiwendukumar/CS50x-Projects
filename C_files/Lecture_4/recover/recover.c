#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    //CHECK FOR CORRECT NUMBER OF ARGUMENTS
    if (argc != 2)
    {
        printf("Incorrect usage \n");
        return 1;
    }
    else
    {
        //OPEN FILE TO BE READ AND CHECK IF NULL
        FILE *f = fopen(argv[1], "r");
        if (f == NULL)
        {
            return 1;
        }

        //INITIALIZE VARIABLES
        FILE *o = NULL;
        uint8_t buffer[512];
        int pics = 0;
        char filename[8];

        //LOOP
        while (fread(buffer, 512, 1, f) == 1)
        {
            //CHECK FOR CORRECT INITIALS FROM NOTES AND WALKTHROUGH
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                //CLOSE CURRENT O FILE
                if (pics != 0)
                {
                    fclose(o);
                }

                //WRITE NEW JPG file
                sprintf(filename, "%03i.jpg", pics);
                o = fopen(filename, "w");
                pics++;
            }
            //WRITE SET OF 512 TO NEW FILENAME
            if (pics != 0)
            {
                fwrite(buffer, 512, 1, o);
            }
        }

        //CLOSE FILES
        fclose(f);
        fclose(o);

        //TELL COMPUTER THE PROGRAM IS A SUCCESS
        return 0;
    }
}