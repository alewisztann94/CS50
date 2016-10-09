/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

#define TRUE 1 
#define FALSE 0

typedef uint8_t  BYTE;



bool isJpeg(BYTE buffer[512]) //checks for jpeg signature, first four bytes of a 512 byte array. 
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
    {
        if (buffer[3] >= 224 && buffer[3] <= 239)
            return TRUE;
    }
    return FALSE;
}

int main(int argc, char* argv[])
{
    // Open memory card file
    BYTE buffer[512];
    FILE* card = fopen("card.raw", "r");
    if (card == NULL)
    {
        printf("File not found.\n");
        return 1;
    }
    
    //recover jpeg files
    int count = 0;
    FILE* image = NULL;
    while (fread(&buffer, sizeof(buffer), 1, card) == 1) //fread executes whilst in condition, thus pointer to stream will be changed in card. 
    {
        char jpeg[8]; //don't forget to include space in memory for \0
        sprintf(jpeg,"%03i.jpg", count);
        if (isJpeg(buffer) == TRUE)
        {
            if (image != NULL)
            {
                fclose(image);
                count++;
                image = fopen(jpeg, "w");
            }
            if (image == NULL)
            {
                image = fopen(jpeg, "w");
                count++;
            }
        }
        if (image != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, image);
        }
    }
    fclose(image); //close last image file
    fclose(card);
}


