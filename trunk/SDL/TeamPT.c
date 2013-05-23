#include <stdio.h>
#include <conio.h>
#include "Global.h"
#include "utilities.h"
#include "TeamPT.h"

int welcome()
{
    int option = 0;
/*

    printStringCenter("Please choose an option", 12);
    printStringCenter("1 - Player vs Player", 14);
    printStringCenter("2 - Player vs Computer", 15);
    printStringCenter("3 - Check Statistics", 16);
    printStringCenter("4 - Credits", 17);
    printStringCenter("5 - Description", 18);
    printStringCenter("0 - Exit", 19);
*/
    do
    {
        option = pause()+1;
        //fflush(stdin);
        //option = getch() - '0'; // Read a char from the keyboard without echo and subtract the ASCII value of 0 to it, creating an integer that suits our needs
    }while(option < 0 || option > 5);   // Check if the option was valid and repeat the cicle if not

    return option;
}

int chooseDifficulty()
{
    int difficulty;

    setCursorPosition(14, 4);
    printf(" _  _     _____                 _      _");
    setCursorPosition(14, 5);
    printf("| || |   |_   _|               | |    (_)");
    setCursorPosition(14, 6);
    printf("| || |_    | |  _ __     __ _  | |     _ _ __   ___");
    setCursorPosition(14, 7);
    printf("|__   _|   | | | '_ \\   / _` | | |    | | '_ \\ / _ \\");
    setCursorPosition(14, 8);
    printf("   | |    _| |_| | | | | (_| | | |____| | | | |  __/");
    setCursorPosition(14, 9);
    printf("   |_|   |_____|_| |_|  \\__,_| |______|_|_| |_|\\___|");

    printStringCenter("Please choose the difficulty level", 12);
    printStringCenter("1 - Easy", 14);
    printStringCenter("2 - Normal", 15);
    printStringCenter("3 - Hard", 16);
    printStringCenter("0 - Return", 17);
    do
    {
        fflush(stdin);
        difficulty = getch() - '0'; // Read a char from the keyboard without echo and subtract the ASCII value of 0 to it, creating an integer that suits our needs
    }
    while(difficulty < 0 || difficulty > 3);   // Check if the option was valid and repeat the cicle if not
    return difficulty;
}

