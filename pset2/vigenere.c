#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool AlphabetOnly(string key);

int main(int argc, string argv[])
{
    if (argc != 2) //Must only accept one command line argument with the exception of main.
    {
        printf("Please try again!");
        return 1;
    }
    else if (AlphabetOnly(argv[1]) == false) //Checks if command-line argument has anything besides alphabet letters. If so, return false.
    {
        printf("Letters only.");
        return 1;
    }
    else
    {
        string key = argv[1]; //Take string argv[1] and convert it into an array of integers.
        int keylen = strlen(key);
        int keynum[keylen];
        for (int j = 0; j < keylen; j++)
        {
            if (isupper(key[j])) //Convert uppercase value of key[j] to alphabetical key int. (e.g. H = 72 - 65 = 7)
            {                          //Collect all 
                int upperkey = key[j];
                keynum[j] = upperkey - 65;
                keynum[keylen] = keynum[j];
            } 
            else if (islower(key[j]))
            {
                int lowerkey = key[j];
                keynum[j] = lowerkey - 97;
                keynum[keylen] = keynum[j];
            }
        }
        string plaintext = GetString(); //Get plaintext from user. 
        int n = strlen(plaintext);
        int k = 0; //such an easy fix... just declare an int outside loop. No need to make another loop inside loop dummy.
        //increase count everytime plaintext[i] is alphabetical. Derp. 
        for (int i = 0; i < n; i++)
        {
            if (isupper(plaintext[i])) //The caesar cipher formula only works when ints are 0-26, so using ASCII,
            {                          //Subtract 65 to make A-Z reflect 0-26. Likewise for lower cases, except subtract 97.
                int mod = k % keylen;
                int modkey = keynum[mod];
                int alpha = plaintext[i] - 65;
                int result = (alpha + modkey) % 26;
                printf("%c", result + 65);
                k++;
            }
            else if (islower(plaintext[i]))
            {
                int mod = k % keylen;
                int modkey = keynum[mod];
                int alpha = plaintext[i] - 97;    //Once the integer value is encrypted via the formula, translate back to ASCII...
                int result = (alpha + modkey)  % 26;    //Integer values by adding the previously subtracted integers.
                printf("%c", result + 97);
                k++;
            }
            else    //If user input is not part of the alphabet, print the symbols unchanged, delay implementation of key. 
            {
                printf("%c", plaintext[i]);   
            }
        }
        printf("\n");
        return 0;
    }    
}


bool AlphabetOnly(string key) //FUNCTION TO RETRIEVE ONLY ALPHABET LETTERS IN COMMAND LINE ARGUMENT. 
{
    int n = strlen(key);
    for (int i = 0; i < n; i++)
    {
        if (isalpha(key[i]))
        {
            continue;
        }
        else 
        {
            return false;
        }    
    }
    return true;
}
