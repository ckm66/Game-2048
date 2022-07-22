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
    Game_Board(ymax, xmax);
}