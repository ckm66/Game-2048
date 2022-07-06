#pragma once 
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <stack>
#include "DataBase.h"

struct Game_Data
{
    int Index;
    time_t Game_Time;
    int Board_Size = 0;
    int Game_Board[11][11];
};

std::stack <Game_Data> Temporate_Game_Storage;

void Initalizing_Game(Game_Data &New_Game)
{
    New_Game.Index = rand() %1000 + 1;

    New_Game.Game_Time = time(NULL);

    std::cout << "Please enter your desire Game Board Size (4-9)";
    
    std::cin >> New_Game.Board_Size;

   
    for (int x = 0; x < New_Game.Board_Size; x++)
    {
        for (int y = 0; y < New_Game.Board_Size; y++)
        {
            New_Game.Game_Board[x][y] = 0;
        }
    }
}

void Adding_Block(Game_Data &New_Game)
{   
    

    int x = rand() % New_Game.Board_Size;
    int y = rand() % New_Game.Board_Size;
    
    if ( New_Game.Game_Board[x][y] == 0)
    {
        New_Game.Game_Board[x][y] = 2;
    }

    else
    {
        Adding_Block(New_Game);
    }
    return;
}

bool Check_Game_Status(Game_Data New_Game)
{
    bool Full {true};

    for (int x = 0; x < New_Game.Board_Size; x++)
    {
        for (int y = 0; y < New_Game.Board_Size; y++)
        {
            if (New_Game.Game_Board[x][y] == 0)
            {
                Full = false;
                return Full;
            }
        }
    }
    return Full;
}

void Print_Board(Game_Data New_Game)
{
    for (int y = 0; y < New_Game.Board_Size; y++)
    {
        for (int x = 0; x < New_Game.Board_Size; x++)
        {
            std::cout << New_Game.Game_Board[x][y];
        }
        std::cout << '\n';
    }
    return;
}

void Swipe(Game_Data New_Game)
{

}