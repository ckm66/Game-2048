#include <iostream>
#include <ncurses.h>
#include <string>
#include "Display.h"
#include "DataBase.h"

int main()
{   
    initscr();
    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);
    bool previous_Game {false};
    game_Menu(ymax, xmax, previous_Game);
    endwin();
}