#include <windows.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include "utilities.h"
#include "Credits.h"
#include <SDL/SDL.h>

//#include <SDL/SDL_image.h>
void print_credits(SDL_Surface *screen, TTF_Font *font)
{
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    printWindow(0,0,0,999,20,screen,"Credits", font);
    printWindow(0,0,0,999,40,screen,"The Team Mate",font);
    SDL_Rect position;
    SDL_Surface *PTflag = NULL, *FRflag = NULL, *ITflag = NULL, *NLflag = NULL;
    PTflag = SDL_LoadBMP("PTflag.bmp");
    FRflag = SDL_LoadBMP("FRflag.bmp");
    ITflag = SDL_LoadBMP("ITflag.bmp");
    NLflag = SDL_LoadBMP("NLflag.bmp");

    position.x=(screen->w/4)-(PTflag->w/2);
    position.y=80;
    SDL_BlitSurface(PTflag, NULL, screen, &position);
    printWindow(0,0,0,360,110,screen,"Rafael  Caetano", font);
    printWindow(0,0,0,360,150,screen,"Jorge Gonçalves", font);
    position.x=screen->w-(screen->w/4)-(FRflag->w/2)-100;
    position.y=80;
    printWindow(0,0,0,780,120,screen,"Alexandre Daussy", font);
    SDL_BlitSurface(FRflag, NULL, screen, &position);
    printWindow(0,0,0,360,260,screen,"Giacomo Corpino", font);
    printWindow(0,0,0,360,300,screen,"Claudio Baffi", font);
    position.x=(screen->w/4)-(PTflag->w/2);
    position.y=100+PTflag->h;
    SDL_BlitSurface(ITflag, NULL, screen, &position);
    position.x=screen->w-(screen->w/4)-(FRflag->w/2)-100;
    position.y=100+PTflag->h;
    printWindow(0,0,0,780,260,screen,"Don Gourdet", font);
    printWindow(0,0,0,780,300,screen,"Otteran Ludachris", font);


    printWindow(0,0,0,999,400,screen,"A Proposal from Portugal",font);
    printWindow(0,0,0,999,430,screen,"Marisa Maximiano",font);
    printWindow(0,0,0,999,450,screen,"Catrina Silva",font);
    printWindow(0,0,0,999,470,screen,"Vitor Távora",font);


    SDL_BlitSurface(NLflag, NULL, screen, &position);



    SDL_free(PTflag);
    SDL_free(FRflag);
    SDL_free(ITflag);
    SDL_free(NLflag);






    int option;
    printWindow(0,0,0,999,510,screen,"Press ENTER to return",font);
    do
    {
        option = pause();
    }
    while(option != 13);

   SDL_Flip(screen);
}

/*
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
*/







