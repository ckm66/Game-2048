#include <iostream>
#include <ncurses.h>
#include "Display.h"

int main()
{
    initscr();
    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);
    Registeration_Page(ymax, xmax);
    endwin();
}