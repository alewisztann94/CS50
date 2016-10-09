/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"


/**
 * Returns true if value is in array of n values, else false.
 */
 
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

 
bool search(int value, int values[], int n)
{
    int min = 0;
    int max = n;
    for (int i = 0; i < n; i++)
    {
        int midpoint = FindMid(min, max);
        if (values[midpoint] == value)
            return true;
        else if (value > values[midpoint])
        {
            min = midpoint + 1;
        }
        else if (value < values[midpoint])
        {
            max = midpoint - 1;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
 
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
