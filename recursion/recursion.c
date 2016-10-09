#include <stdio.h>
#include <cs50.h>

int sum(int n);
double fact(double n);

int main(void)
{
   printf("linear recursion: %i \n", sum(10)); 
   printf("factorial recursion: %f", fact(20));
}


int sum(int n)
{
    if (n == 1)
        return 1;
    else 
        return n + sum(n - 1);
}

double fact(double n)
{
    if (n == 1)
        return 1;
    else
        return n * fact(n - 1);
}