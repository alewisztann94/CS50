#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2) //Must only accept one command line argument with the exception of main.
    {
        printf("Please try again!");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]); //Convert string argv[1] to an integer with atoi.
        string plaintext = GetString();
        int n = strlen(plaintext);
        for (int i = 0; i < n; i++)  //This loop will run over all characters of the string input.
        {
            if (isalpha(plaintext[i]))   //Differentiate between alphabet characters, upper and lower case.
            {
                if (isupper(plaintext[i])) //The caesar cipher formula only works when ints are 0-26, so using ASCII,
                {                          //Subtract 65 to make A-Z reflect 0-26. Likewise for lower cases, except subtract 97.
                    int alpha = plaintext[i] - 65;
                    int result = (alpha + key) % 26;
                    printf("%c", result + 65);
                }
                else
                {
                    int alpha = plaintext[i] - 97;    //Once the integer value is encrypted via the formula, translate back to ASCII...
                    int result = (alpha + key) % 26;    //Integer values by adding the previously subtracted integers.
                    printf("%c", result + 97);
                }
            }
            else    //If user input is not part of the alphabet, print the symbols unchanged. 
            {
                printf("%c", plaintext[i]);
            }
        }
    }
    printf("\n"); //End the line to pass check50 and return 0; to indicate the success of the program.
    return 0;
}    
        

   