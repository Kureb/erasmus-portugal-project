#include <stdio.h>
#include <conio.h>
#include "Global.h"
#include "utilities.h"
#include "TeamPT.h"

int welcome(SDL_Surface * screen, TTF_Font * font, TTF_Font * bigFont)
{
    int option = 0;


    printWindow(0,0,0,999,50,screen,"4InALine",bigFont);
    printWindow(0,0,0,999,300,screen,"Please choose an option",font);
    printWindow(0,0,0,999,330,screen, "1 - Player vs Player",font);
    printWindow(0,0,0,999,360,screen, "2 - Player vs Computer",font);
    printWindow(0,0,0,999,400,screen,"Q - Exit",font);

    do{
        option = pause()+1;
    }while(!(option > 0 && option < 3 || option == -1));   // Check if the option was valid and repeat the cicle if not


    return option;
}

int chooseDifficulty(SDL_Surface * screen, TTF_Font * font, TTF_Font * bigFont)
{
    int difficulty;

    printWindow(0,0,0,999,50,screen,"4InALine",bigFont);
    printWindow(0,0,0,999,210,screen,"Please choose the difficulty level",font);
    //printStringCenter("Please choose the difficulty level", 12);
    printWindow(0,0,0,999,210,screen,"Please choose the difficulty level",font);
    //printStringCenter("1 - Easy", 14);
    printWindow(0,0,0,999,250,screen,"1 - Easy",font);
    //printStringCenter("2 - Normal", 15);
    printWindow(0,0,0,999,280,screen,"2 - Normal",font);
    //printStringCenter("3 - Hard", 16);
    printWindow(0,0,0,999,310,screen,"3 - Hard",font);
    //printStringCenter("0 - Return", 17);
    printWindow(0,0,0,999,340,screen,"Q - Return",font);
    do
    {

        difficulty = pause()+1; // Read a char from the keyboard without echo and subtract the ASCII value of 0 to it, creating an integer that suits our needs
    }
    while(!(difficulty > 0 && difficulty < 4 || difficulty == -1));   // Check if the option was valid and repeat the cicle if not
    return difficulty;
}

