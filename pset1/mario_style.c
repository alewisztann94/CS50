#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int line;
    int height;  
    
    do
    {
        printf("Please pick the height of the half pyramid. Only between 0 and 23 please!\n");
        height = GetInt();
    }    
    while (height > 23 || height < 0); 
    
    printf("Height chosen: %d\n", height);
    
    for (line = 0; line < height; line++)
    {
        for (int space = 0; space < height - line - 1; space++) 
        {
            printf(" ");
        }
        for (int hash = 0; hash < line+2; hash++)
        {
            printf("#");
        }    
            printf("\n");
    }    
}        
    
 