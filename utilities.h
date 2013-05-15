#ifndef UTILITIES_H
#define UTILITIES_H

#include <windows.h>

// Colors
#define BLACK 0
#define WHITE 7
#define RED 4
#define GREEN 2
#define BLUE 1
#define BROWN 6
#define PURPLE 5
#define CYAN 3
#define GREY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define TURQUOISE 11
#define LIGHT_RED 12
#define PINK 13
#define YELLOW 14
#define PURE_WHITE 15

// This header contains some utilitie functions that may be useful in the development of the project

#define SCREENWIDTH 80	// Width of the console

//*****************************************
//Sets the cursor at the desired coordinates
//
//input parameters:
//		x - the x coordinate (starting from 0)
//		y - the y coordinate (starting from 0)
//output value: nothing
//*****************************************
void setCursorPosition(int x, int y);

//*****************************************
//Prints a string at the center of the screen, at the y line
//
//input parameters:
//		*str : the string to be displayed
//		y : the line in which it will be displayed (starting from 0)
//output value:
//		nothing
//*****************************************
void printStringCenter(char *str, int y);

//*****************************************
//Removes the the last character of a string if it's a '\n'
//
//input parameters:
//		*str : the string to be chomped
//output value:
//		nothing
//*****************************************
void chomp(char *str);

//*****************************************
//Sets the console to display text in the desired color
//
//input parameters:
//		color: the color in which the text will be displayed
//output value:
//		nothing
//*****************************************
void setTextColor(short color);

//*****************************************
//Changes the cursos visibility
//
//input parameters:
//		visible: whether the cursor will be visible or not
//output value:
//		nothing
//*****************************************
void setCursorVisible(BOOL visible);

#endif // UTILITIES_H
