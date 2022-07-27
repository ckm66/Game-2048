#include <iostream>
#include <ncurses.h>
#include <string>
#include "Display.h"
#include "DataBase.h"

int main()
{   
    initscr();
    Game_Data Game;
    Game.Board_Size = 3;
    for (int y = 0; y < Game.Board_Size; y++)
    {
        for (int x  = 0; x < Game.Board_Size; x++)
        {
            Game.Game_Board[x][y] = 0;
        }
    }

    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);
    Game_Board(Game, ymax, xmax);

    refresh();
    endwin();
}