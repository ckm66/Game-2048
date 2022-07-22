#include <iostream>
#include <ncurses.h>
#include <string>
#include "Display.h"
#include "DataBase.h"

int main()
{
    read_Data_Base();

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
    
    int option {0};
    while (option != 3)
    {   
        option = game_Menu(ymax, xmax, User.Game_Storage.empty());

        switch(option)
        {
            case 0:
            {
                Game_Data Game;
                break;
            }
            case 1:
            {
                Game_Data New_Game;
                New_Game_Session(New_Game, ymax, xmax);
                break;
            }
            case 2:
            {
                break;
            }
        }
    }

    endwin();
    Generate_Data_Base();
    return 0;
}