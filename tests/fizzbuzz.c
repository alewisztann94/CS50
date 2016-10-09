#include <stdbool.h>
#include <stdio.h>

int isMult(int num);


int main(void)
{
    for (int i = 1; i <= 100; i++)
    {
        if (isMult(i) == 3)
            printf("Fizz\n");
        else if (isMult(i) == 1)
            printf("FizzBuzz\n");
        else if (isMult(i) == 2)
            printf("Buzz\n");
        else    
            printf("%i\n", i);
    }
}

int isMult(int num)
{
    if (num % 3 == 0 && num % 5 == 0)
        return 1;
    else if (num % 5 == 0)
        return 2;
    else if (num % 3 == 0)
        return 3;
    else return -1;
}

