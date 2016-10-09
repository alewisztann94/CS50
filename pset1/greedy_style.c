#include <stdio.h>
#include <cs50.h>

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
    printf("%f\n", change);
    
    
    int quarters; //Loops all structurally congruent. Declare int counter value for coin value. 
                 //Loop will subtract coin value from change value until coin value exceeds change value.
    for (quarters = 0; change >= 25; quarters++)
    {
        if (change >= 25)
        {
            change = change - 25;
        }
    }
    printf("%d\n", quarters);
    
    int dimes;
    for (dimes = 0; change >= 10; dimes++)
    {
        if (change >= 10)
        {
            change = change - 10;
        }
    }
    printf("%d\n", dimes);
    
    int nickels;
    
    for (nickels = 0; change >= 5; nickels++)
    {
        if (change >= 5)
        {
            change = change - 5;
        }
    }
    printf("%d\n", nickels);
    
    int pennies;
    
    for (pennies = 0; change >= 1; pennies++)
    {
        if (change >= 1)
        {
            change = change - 1;
        }
    }
    printf("%d\n", pennies);
    
    int optimal_change = quarters + dimes + nickels + pennies;
    
    printf("This is the least amount of coins that returns the exact change: %d\n", optimal_change);
}
