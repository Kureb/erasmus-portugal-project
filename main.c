#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "Global.h"
#include "utilities.h"
#include "TeamPT.h"
#include "Play.h"
#include "Board.h"
#include "Statistics.h"
#include "Credits.h"

/* -------------------------- main project goals ----------------------
-> define the data structures and other configurations that support the game
-> UI (text-based)
-> game loop with persistence (text files to store the game state)
-> develop the behaviour of the player. The game must support different playing modes (e.g. Person vs Person, Person vs Computer, etc.)
-> highscores for the five best players, possibly considering the number of movements
-> statistics will be stored in files
-------------------------- main project goals ---------------------- */

//*****************************************
// Main function
//*****************************************
int main()
{
    int option, difficulty = 4;

    do
    {
        clrscr(); // Replaces system("cls"). Only testing for now
        setCursorVisible(FALSE);
        option = welcome(); // Give the welcome screen to the user and wait until he decides which game type he will choose. His decision is then returned
        if(option > 0)
        {
            if(option == 3)
            {
                showStatistics();
            }
            else if(option == 5)
            {
                print_informations();
            }
            else if(option == 4)
            {
                print_credits();
            }
            else
            {
                if(option == 2)
                {
                    system("cls");
                    difficulty = chooseDifficulty();
                }
                if(difficulty > 0)
                {
                    setCursorVisible(TRUE);

                    board p;
                    Gamer g1, g2;
                    char name[PLAYERNAME];

                    do
                    {
                        system("cls");
                        printf("Enter player 1 name: ");
                        fflush(stdin);
                        fgets(name, PLAYERNAME, stdin);
                        chomp(name);
                    }
                    while(strcmp(name, "") == 0); // Make sure the name is not empty
                    strcpy(g1.name, name);
                    g1.num = 1;
                    g1.moves = 0;

                    if(option == 2)
                    {
                        strcpy(g2.name, "Computer");
                    }
                    else
                    {
                        do
                        {
                            system("cls");
                            printf("Enter player 2 name: ");
                            fflush(stdin);
                            fgets(name, PLAYERNAME, stdin);
                            chomp(name);
                            if(stricmp(g1.name, name) == 0) // Check if both players don't have the same name
                            {
                                printf("Both players can't have the same name. Press ENTER to type a new name.");
                                do
                                {
                                    fflush(stdin);
                                }
                                while(getch() != 13);
                            }
                        }
                        while(strcmp(name, "") == 0 || stricmp(g1.name, name) == 0); // Make sure the name is not empty
                        strcpy(g2.name, name);
                    }
                    g2.num = 2;
                    g2.moves = 0;

                    initializeGrid(p);
                    showBoard(p);
                    setCursorVisible(FALSE);
                    if(option == 1) // Player vs Player
                        playerVsPlayer(&g1, &g2, p);
                    else // Player vs Computer
                        playerVsComputer(&g1, &g2, p, difficulty);
                }
            }
        }
    }
    while(option != 0);   // Show menu until the user chooses the exit option
    return 0;
}
