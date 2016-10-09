#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"
int FindMid(int min, int max)
{
    int MidPoint = (min + max) / 2;
    return MidPoint;
}

bool BinarySearch(int key, int array[], int min, int max)
{
    if (max < min)
    {
        return false;
    }
    else 
    {
        int midpoint = FindMid(min, max);
        if (array[midpoint] < key)
        {
            return BinarySearch(key, array, midpoint + 1, max);
        }
        else if (array[midpoint] > key)
        {
            return BinarySearch(key, array, min, midpoint - 1);
        }
        else
            return true;
    }
}

void sort(int values[], int n) //n is array length of values. 
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (values[j] < values[min])
                min = j;
        }        
        if (min != i)
        {
            int temp;
            temp = values[min];
            values[min] = values[i];
            values[i] = temp;
        }    
    }
    return;
}


int main(void)
{
    int coolhwip[5] = {5, 4, 3, 2, 1};
    int key = 7;
    int min = 0;
    int max = 5;
    sort(coolhwip, max);
    if (BinarySearch(key, coolhwip, min, max))
        printf("nyes.");
    else
        printf("laklak");
}
