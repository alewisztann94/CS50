#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int min;
    int max;
    struct node* prev;
    struct node* next;
}
node;

int main(int argc, char* argv[])
{
    FILE* min_int = fopen("min.txt", "r");
    FILE* max_int = fopen("max.txt", "r");

    
    node* head = malloc(sizeof(node));
    node* crawler = head;
    fscanf(min_int, "%i", &head->min);
    fscanf(max_int, "%i", &head->max);
    while (!feof (min_int) || !feof (max_int))
    {
        crawler->next = malloc(sizeof(node));
        crawler = crawler->next;
        fscanf(min_int, "%i", &crawler->min);
        fscanf(max_int, "%i", &crawler->max);
    }
    
    crawler = head;
    fclose(min_int);
    fclose(max_int);
    
    int differences[20];
    int net_diff = 0;
    int count = 0;
    for (int i = 0; i<9; i++)
    {
        int one_day = crawler->min - crawler->max;
        differences[count] = one_day;
        net_diff+= one_day;
        count++;
        int temp = crawler->min;
        crawler = crawler->next;
        int next_day = crawler->max - temp;
        net_diff += next_day;
        differences[count] = next_day;
        count++;
    }
    
    printf("%i", net_diff);
}