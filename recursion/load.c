#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "dictionary.h"


int word_count;
bool destroy(node* crawler);

bool load(const char* dictionary)
{
    root = calloc(1, sizeof(node));
    FILE* openDic = fopen(dictionary, "r");
    node* crawler = root;
    for (char c = fgetc(openDic); c != EOF; c = fgetc(openDic))
    {
        if (c != '\n')
        {
            // translate into a value between 0 and 26!!! not 27!!! FUCK!!!
            int key = tolower(c) - 'a'; 
            if (key < 0)
            {
                key = 26 //don't set it to 27 DUMMY!!! array[26] is the final element in a 27 element array.
            }
            if (crawler->children[key] == NULL)
            {
                crawler->children[key] = calloc(1, sizeof(node));
                crawler = crawler->children[key];
            }
            else if (crawler->children[key] != NULL)
            {
                crawler = crawler->children[key];
            }
        }    
        else if (c == '\n')
        {
            crawler->is_word = true;
            word_count++;
            crawler = root;
        }
    }
    fclose(openDic);
    if (root != NULL)
        return true;
    else    
        return false;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return word_count;    
    }
}

bool unload(void)
{
    destroy(root);
    return true;
}

bool destroy(node* crawler)
{
    for (int i = 0; i < 27; i++)
    {
        if (crawler->children[i] != NULL)
        {
            destroy(crawler->children[i]);
        }
        else if (crawler->children[i] == NULL)    
            continue;
    }
    free(crawler);
    return true;
}


int main(void)
{
    const char* small = "large";
    load(small);
    printf("%i\n", word_count);
    if (root->children[2] != NULL)
        printf("nyes\n");
    node* crawler = root->children[2];    
    if (crawler->children[0] != NULL)
        printf("b-a\n");
    crawler = crawler->children[0];
    if (crawler->children[19] != NULL)
        printf("b-a-t ???\n");
    crawler = crawler->children[19];    
    if (crawler->is_word == true)
        printf("HUM HO!!!!");
    unload();
}