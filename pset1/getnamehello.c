#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("what is your name brah: ");
    string n = GetString();
    printf("hello, %s\n", n);
}