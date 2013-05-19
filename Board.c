#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Global.h"
#include "Board.h"
#include "utilities.h"


/* We initialize the board (2D)
** Each box is empty
*/
void initializeGrid(board p)
{
    setTextColor(WHITE);
    int i,j;
    for(i=0;i<WIDTH;i++){
		for(j=0;j<HEIGHT;j++){
			p[i][j] = EMPTY;
        }
    }
}

/* Display of the board,
** with graphic-text boxes
** and we fill boxes
*/
void showBoard(board p)
{
	int i, j;
	char ch;
    system("cls");	// Clear the screen
    setCursorPosition(19, 0);
    for(i = 0; i < 29; i++) // Print the top line of hifens
		putchar('-');
	setCursorPosition(28, 1);
    printf("GAME BOARD");
    for(j = 0; j < 7; j++)	// Print all lines of chars
    {
        setCursorPosition(19, 2 + j * 2);
        for(i = 0; i <= 28; i++)
        {
            if(i == 0) // Top line
			{
				if(j == 0)
					ch = 201;
				else if(j == 6)
					ch = 200;
				else
					ch = 204;
			}
			else if(i == 28) // Bottom line
			{
				if(j == 0)
					ch = 187;
				else if(j == 6)
					ch = 188;
				else
					ch = 185;
			}
            else if(i % 4 == 0) // Check if there should be a '+' or not
			{
				if(j == 0)
					ch = 203;
				else if(j == 6)
					ch = 202;
				else
					ch = 206;
			}
			else
			{
				ch = 205; // -
			}
            putchar(ch);
        }
    }
    for(i = 0; i <= 7; i++) // Print all columns of chars
    {
        for(j = 1; j <= 12; j++)
        {
            if(j % 2 != 0) // Check if there isn't an intesection with a line. If there is an intersection, there is no need to draw anything because there is already a '+'
            {
                setCursorPosition(19 + i * 4, 2 + j);
                putchar(186); // |
            }
        }
    }
    for(i = 0; i < HEIGHT; i++) // Print the content of the game board
    {
        for(j = 0; j < WIDTH; j++)
        {
            setCursorPosition(21 + j * 4, 3 + i * 2);
            putch(p[j][i]);
        }
    }
    setCursorPosition(21, 15);
    printf("1   2   3   4   5   6   7"); // Print column's numbers
    setCursorPosition(19, 16);
    for(i = 0; i < 29; i++) // Print the bottom line of hyfens
        putch('-');
}
