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

void init(void);
bool even(int d);
void draw(void);
bool move(int tile);




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
    
    init();
    draw();
    int tile = GetInt();
        // quit if user inputs 0 (for testing)
    move(tile);
   
}    

    









bool won(void)
{
    int row;
    int col; 
    for (row = 0; row < d; row++)
    {
        for (col = 0; col < d; col++)
        {
            if (board[row][col] == 1)
                continue; 
            else if (board[row][col] == board[row][col-1] + 1)
                continue;
            else if (board[row][col] == board[row-1][d-1] + 1)
                continue;
            else if (board[row][col] == 95)    
                continue;
            else
                return false;
        }        
    }
    return true;
}





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
        board[d-1][d-1] = 95;
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
        board[d-1][d-1] = 95;
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
            if (board[i][j] == 95)
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
    int array_temp[d][d];
    for (int row = 0; row < d; row++)
    {
        for (int col = 0; col < d; col++)
        {
            if (tile == board[row][col])
            {
                if (95 == board[row][col+1]) //Blankspace right
                {
                    array_temp[row][col] = board[row][col];
                    board[row][col] = board[row][col+1];
                    board[row][col+1] = array_temp[row][col];
                    return true;
                }    
                else if (95 == board[row][col-1]) //Blankspace left
                {
                    array_temp[row][col] = board[row][col];
                    board[row][col] = board[row][col-1];
                    board[row][col-1] = array_temp[row][col];
                    return true;
                }
                else if (95 == board[row+1][col]) //Blankspace down 
                {
                    array_temp[row][col] = board[row][col];
                    board[row][col] = board[row+1][col];
                    board[row+1][col] = array_temp[row][col];
                    return true;
                }    
                else if (95 == board[row-1][col]) //Blankspace up
                {
                    array_temp[row][col] = board[row][col];
                    board[row][col] = board[row-1][col];
                    board[row-1][col] = array_temp[row][col];
                    return true;
                }
            }    
            else
                return false;
        }
    }
    return 0;
}


