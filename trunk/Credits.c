#include <windows.h>
#include <string.h>
#include <stdio.h>
#include "utilities.h"
#include "Credits.h"

void print_credits()
{
    system("cls");
    printStringCenter("Credits", 1);
    printStringCenter("The Tea Mate", 3);

    setCursorPosition(2,5);
    printf("Rafael Caetano");
    setCursorPosition(2,6);
    printf("Jorge Goncalves");
    setCursorPosition(2,7);
    printf("Alexandre Daussy");
    setCursorPosition(2,8);
    printf("Claudio Baffi");
    setCursorPosition(45,5);
    printf("Giacomo Corpino");
    setCursorPosition(45,6);
    printf("Don Gourdet");
    setCursorPosition(45,7);
    printf("Otteran Ludachris");


    printStringCenter("A proposal from", 15);
    setCursorPosition(2,17);
    printf("Marisa Maximiano");
    setCursorPosition(45,17);
    printf("Vitor Tavora");



    printStringCenter("Press ENTER to return", 22);
    do
    {
        fflush(stdin);
    }
    while(getch() != 13);



}


print_informations()
{
    system("cls");
    printStringCenter("Informations", 1);
    setCursorPosition(5,5);
    printf("The aim of this project is the development of the 4InALine game. The concept of the game is to arrange four discs in a row (in our case since we use a text-based interface it depends on the player symbol). The payer discs need to be lined up. Horizontal, vertical, and diagonal lines are valid. There are two players and only one player plays at a time.");

     printStringCenter("Press ENTER to return", 22);
    do
    {
        fflush(stdin);
    }
    while(getch() != 13);
}







