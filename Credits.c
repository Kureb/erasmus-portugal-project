#include <windows.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include "utilities.h"
#include "Credits.h"

void print_credits()
{
    int i, j;
    system("cls");
    printStringCenter("Credits", 1);
    printStringCenter("The Tea Mate", 3);

	// Portuguese flag
	setTextColor(GREEN);
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 4; j++)
		{
			setCursorPosition(6 + j, 7 + i);
			putchar(219);
		}
	}
	setCursorPosition(9, 8);
	setTextColor(YELLOW);
	for(i = 0; i < 2; i++)
		putchar(219);
	setTextColor(LIGHT_RED);
	setCursorPosition(10, 7);
	putchar(219);
	setCursorPosition(10, 9);
	putchar(219);
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 3; j++)
		{
			setCursorPosition(11 + i, 7 + j);
			putchar(219);
		}
	}
	setTextColor(PURE_WHITE);
	setCursorPosition(7, 5);
	printf("Portugal");

	// Dutch flag
	setTextColor(LIGHT_RED);
	setCursorPosition(26, 7);
	for(i = 0; i < 9; i++)
		putchar(219);
	setCursorPosition(26, 8);
	setTextColor(PURE_WHITE);
	for(i = 0; i < 9; i++)
		putchar(219);
	setCursorPosition(26, 9);
	setTextColor(LIGHT_BLUE);
	for(i = 0; i < 9; i++)
		putchar(219);
	setTextColor(PURE_WHITE);
	setCursorPosition(25, 5);
	printf("Netherlands");


	// Italian flag
	setTextColor(GREEN);
	for(i = 0; i < 3; i++)
	{
		setCursorPosition(46, 7 + i);
		for(j = 0; j < 3; j++)
			putchar(219);
	}
	setTextColor(PURE_WHITE);
	for(i = 0; i < 3; i++)
	{
		setCursorPosition(49, 7 + i);
		for(j = 0; j < 3; j++)
			putchar(219);
	}
	setTextColor(LIGHT_RED);
	for(i = 0; i < 3; i++)
	{
		setCursorPosition(52, 7 + i);
		for(j = 0; j < 3; j++)
			putchar(219);
	}
	setTextColor(PURE_WHITE);
	setCursorPosition(48, 5);
	printf("Italy");

	// French flag
	setTextColor(LIGHT_BLUE);
	for(i = 0; i < 3; i++)
	{
		setCursorPosition(66, 7 + i);
		for(j = 0; j < 3; j++)
			putchar(219);
	}
	setTextColor(PURE_WHITE);
	for(i = 0; i < 3; i++)
	{
		setCursorPosition(69, 7 + i);
		for(j = 0; j < 3; j++)
			putchar(219);
	}
	setTextColor(LIGHT_RED);
	for(i = 0; i < 3; i++)
	{
		setCursorPosition(72, 7 + i);
		for(j = 0; j < 3; j++)
			putchar(219);
	}
	setTextColor(PURE_WHITE);
	setCursorPosition(68, 5);
	printf("France");



	setTextColor(PURE_WHITE);

    setCursorPosition(3, 12);
    printf("Rafael Caetano");
    setCursorPosition(3,13);
    printf("Jorge Goncalves");

    setCursorPosition(25,12);
    printf("Don Gourdet");
    setCursorPosition(22,13);
    printf("Otteran Ludachris");

    setCursorPosition(44,12);
    printf("Claudio Baffi");
    setCursorPosition(43,13);
    printf("Giacomo Corpino");

    setCursorPosition(62,12);
    printf("Alexandre Daussy");


    printStringCenter("A proposal from Portugal", 16);
    setCursorPosition(15,18);
    printf("Marisa Maximiano");
    setCursorPosition(52,18);
    printf("Vitor Tavora");



    printStringCenter("Press ENTER to return", 21);
    do
    {
        fflush(stdin);
    }
    while(getch() != 13);
}


void print_informations()
{
    system("cls");
    printStringCenter("Informations", 0);
    setCursorPosition(1,5);
    printf("The aim of this project is the development of the 4InALine game.");
    setCursorPosition(1,6);
    printf("The concept of the game is to arrange four discs in a row");
    setCursorPosition(1,7);
    printf("(in our case since we use a text-based interface it depends ");
    setCursorPosition(1,8);
    printf("on the player symbol). The payer discs need to be lined up.");
    setCursorPosition(1,9);
    printf("Horizontal, vertical, and diagonal lines are valid.");
    setCursorPosition(1,10);
    printf("There are two players and only one player plays at a time.");

     printStringCenter("Press ENTER to return", 22);
    do
    {
        fflush(stdin);
    }
    while(getch() != 13);
}







