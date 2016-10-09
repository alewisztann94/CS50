#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//Program to print the initials of any name separated by a single whitespace.
//Print first character at index 0 of string and uppercase it.
//Loop through all characters of string and print/capitalize [i+1] character where character[i] equates to a whitespace.
int main(void)
{
    string name = GetString();
    int i;
    int n = strlen(name);
    printf("%c", toupper(name[0]));
    for (i = 0; i < n; i++)
    {
        if (name[i] == (char) 32) // 32 is the ASCII integer that represents a whitespace " ".
        {
            printf("%c", toupper(name[i+1]));
        }
    }    
    printf("\n");
}




