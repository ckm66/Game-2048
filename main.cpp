#include <iostream>
#include "DataBase.h"
#include "Core.h"

int main()
{
    Reading_Player_Data_Base();
    sign_up();

    Game_Data New_Game;
    Initalizing_Game(New_Game);
    Adding_Block(New_Game);

    Generate_Player_Data_Base();
}