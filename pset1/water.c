#include <stdio.h>
#include <cs50.h>

//This program converts minutes/shower time to bottles of water/shower time.

int main(void)
{
    printf("How many minutes did you just spend in the shower? \n");
    int minutes = GetInt();
    printf("You spent %d minutes in the shower.\n", minutes);
    int bottles = minutes * 12;
    printf("That is the equivalent of %d bottles of water!\n", bottles);
}