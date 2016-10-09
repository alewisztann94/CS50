#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int line;
    int height;  
    
    do  //This code prompts user for a height value between 0 and 23 inclusive, re-prompting if an invalid input is given. 
    {
        printf("Please pick the height of the half pyramid. Only between 0 and 23 please!\n");
        printf("height: \n");
        height = GetInt();
    }    
    while (height > 23 || height < 0); 

    
    for (line = 0; line < height; line++) //The initial loop runs until the amount of lines matches the height of the pyramid. 
    {
        for (int space = 0; space < height - line - 1; space++) //Spaces are always height - 1 per line. 
        {
            printf(" ");
        }
        for (int hash = 0; hash < line+2; hash++) //Hashes are always line + 2.
        {
            printf("#");
        }    
            printf("\n");
    }    
}        
    
 

