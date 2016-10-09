/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
bool even(int d);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int row;
    int col; 
    int m = 1;
    if (even(d))
    {
        {
            for (row = 0; row < d; row++)
            {
                for (col = 0; col < d; col++)
                {
                    board[row][col] = d * d - m;
                    m++;
                }
            }
        }
        board[d-1][d-1] = 0;
    }
    else
    {
        for (row = 0; row < d; row++)
        {
            for (col = 0; col < d; col++)
            {
                board[row][col] = d * d - m;
                m++;
            }
        }
        board[d-1][d-2] = 2;
        board[d-1][d-3] = 1;
        board[d-1][d-1] = 0;
    }
}    

bool even(int lak)
{
    if (lak == 4 | lak == 6 | lak == 8)
        return false;
    else 
        return true;
}

void draw(void)
{
    for(int i = 0; i < d; i++) 
    {
        for(int j = 0; j < d; j++)
        {
            if (board[i][j] == 0)
                printf(" %c", 95);
            else if (board[i][j] < 10)
            {
                printf(" %i ", board[i][j]);
                if (j == d - 1)
                    printf("\n");
            }    
            else    
            {
                printf("%i ", board[i][j]);
                if (j == d - 1)
                    printf("\n");
            }
        }    
    }
}

bool move(int tile)
{
    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
            if (tile == board[row][col])
            {
                if (col < d - 1) // Don't look right if you are already at the edge.
                {
                    if (0 == board[row][col+1]) //Blankspace right
                    {
                        board[row][col+1] = tile;
                        board[row][col] = 0;
                        return true;
                    }
                }    
                if (col > 0) //Don't look left if you're going to be left 4 dead.
                {   
                    if (0 == board[row][col-1]) //Blankspace left
                    {
                        board[row][col-1] = tile;
                        board[row][col] = 0;
                        return true;
                    }
                }    
                if (row < d - 1) //Don't look down in your memory when you don't know what you'll find...
                {
                    if (0 == board[row+1][col]) //Blankspace down 
                    {
                        board[row+1][col] = tile;
                        board[row][col] = 0;
                        return true;    
                    }
                }    
                if (row > 0) //Don't look up or a fridge might fall on your face.
                {
                    if (0 == board[row-1][col]) //Blankspace up
                    {
                    board[row-1][col] = tile;
                    board[row][col] = 0;
                    return true;
                    }
                }
            }
        }
    }
    return false;
}

bool won(void)
{
    int row;
    int col; 
    for (row = 0; row < d; row++)
    {
        for (col = 0; col < d; col++)
        {
            if (row == 0 && col == 0) //Greetings traveller, same business as move... 
            {                       //you gotta do nested if loops.
                if (board[row][col] == 1)
                    continue;
                else
                    return false;
            }        
            else if (col == 0 && row > 0) //Essentially need to check for every position on board.
            {                             //When you move to next row checking the last column will seg fault. 
                if (board[row][col] == board[row-1][d-1] + 1) //Check prev top right corner of matrix instead.
                    continue;
                else
                    return false;
            }
            else if (row == d - 1 && col == d -1)
            {
                if (board[row][col] == 0)
                    continue;
                else 
                    return false;
            }        
            else 
            {
                if (board[row][col] == board[row][col-1] + 1)
                    continue;
                else 
                    return false;
            }
        }        
    }
    return true;
}