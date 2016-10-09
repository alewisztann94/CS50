/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "dictionary.h"





int word_count;

bool destroy(node* crawler);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    node* crawler = root;
    for (int i = 0; i < strlen(word) + 1; i++)
    {
        if (islower(word[i]))
        {
            int key = word[i] - 'a';
            if (crawler->children[key] == NULL)
            {
                return false;
            }
            else if (crawler->children[key] != NULL)
            {
                crawler = crawler->children[key];
            }
        }
        else if (isupper(word[i]))
        {
            int key = word[i] - 'A';
            if (crawler->children[key] == NULL)
            {
                return false;
            }
            else if (crawler->children[key] != NULL)
            {
                crawler = crawler->children[key];
            }
        }
        else if (word[i] == '\'')
        {
            int key = 26; //NOT 27!!! children[26] is the 27th element!!
            if (crawler->children[key] == NULL)
            {
                return false;
            }
            else if (crawler->children[key] != NULL)
            {
                crawler = crawler->children[key];
            }
        }
        else if (word[i] == '\0')
        {
            if (crawler->is_word == true)
                return true;
            else if (crawler->is_word == false)
                return false;
        }
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
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
                key = 26; //don't set it to 27!!! array[26] is the final element in a 27 element array.
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

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    destroy(root);
    return true;
}

bool destroy(node* crawler)
{
    for (int i = 0; i < 27; i++) //iterate over all children nodes in a node.
    {
        if (crawler->children[i] != NULL)
        {
            destroy(crawler->children[i]); //recursively call destroy if children node points to another space in memory.
        }
        else if (crawler->children[i] == NULL)    
            continue;
    }
    free(crawler); //don't free the node until you've gone over all children nodes.
    return true;
}
    