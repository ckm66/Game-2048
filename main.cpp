#include <iostream>
#include "DataBase.h"
#include "Core.h"

int main()
{
    srand(time(NULL));
    Reading_Player_Data_Base();
    sign_up();

    Game_Data New_Game;
    Initalizing_Game(New_Game);
    Adding_Block(New_Game);
    while (!Check_Game_Status(New_Game))
    {
        Adding_Block(New_Game);
        Print_Board(New_Game);
    }

    Generate_Player_Data_Base();
}
