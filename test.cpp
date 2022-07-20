#include <iostream>
#include <ncurses.h>
#include <string>
#include "Display.h"
#include "DataBase.h"

int main()
{
    read_Player_Data_Base();

    initscr();
    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);

    char Choice = Initalization_Window(ymax, xmax);
    player_Information User;
    switch (Choice)
    {
    case 'L':
        sign_In(ymax, xmax, User);
        break;
    
    case 'R':
        sign_Up(ymax, xmax, User);
        break;
    }



    endwin();
}