#include <iostream>
#include "struct.h"
#include "DataBase.h"
#include "Core.h"
#include "Display.h"

int main()
{   
    initscr();
    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);
    Information_Page();
    Initalization_Window(ymax, xmax);   

    endwin();
}
