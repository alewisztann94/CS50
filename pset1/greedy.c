#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    do         //This section codes for retrieving a user generated input for the amount of change. Positive values only.
    {
        printf("Please input how much change is required: \n");
        change = GetFloat();
    }
    while (change < 0);
    
    change = change * 100; //Conversion from dollars to cents. User input of 4 would equal 400 cents. 
    change = round(change); //For error 4.2 yields output of 22 it's because float multiplication is imprecise. (4.19 as opposed to 4.2)
                              
    int quarters; //Loops all structurally congruent. Declare int counter value for coin value. 
                 //Loop will subtract coin value from change value until coin value exceeds change value.
    for (quarters = 0; change >= 25; quarters++)
    {
        if (change >= 25)
        {
            change = change - 25;
        }
    }
    
    int dimes;
    for (dimes = 0; change >= 10; dimes++)
    {
        if (change >= 10)
        {
            change = change - 10;
        }
    }
    
    int nickels;
    
    for (nickels = 0; change >= 5; nickels++)
    {
        if (change >= 5)
        {
            change = change - 5;
        }
    }
    
    int pennies;
    
    for (pennies = 0; change >= 1; pennies++)
    {
        if (change >= 1)
        {
            change = change - 1;
        }
    }
    
    int optimal_change = quarters + dimes + nickels + pennies;
    
    printf("%d\n", optimal_change);
}