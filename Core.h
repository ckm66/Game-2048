#pragma once
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <vector>
#include <stack>
#include "struct.h"
#include "DataBase.h"

void Initalizing_Game(Game_Data &New_Game)
{
    New_Game.Index = rand() % 1000 + 1;

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

    if (New_Game.Game_Board[x][y] == 0)
    {
        New_Game.Game_Board[x][y] = 2;
    }

    else
    {
        Adding_Block(New_Game);
    }

    New_Game.Score += 2;
    return;
}

bool Check_Game_Status(Game_Data &New_Game)
{
    bool Full{true};

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

void Swipe(Game_Data &New_Game, char Direction_of_Swipe)
{
    switch (Direction_of_Swipe)
    {
    case 'w': // Up
    {
        for (int x = 0; x < New_Game.Board_Size; x++)
        {
            for (int y = 0; y < New_Game.Board_Size; y++)
            {
                if (New_Game.Game_Board[x][y] == 0)
                {
                    continue;
                }

                for (int y1 = y + 1; y1 < New_Game.Board_Size; y1++)
                {
                    if (New_Game.Game_Board[x][y] == New_Game.Game_Board[x][y1])
                    {
                        New_Game.Game_Board[x][y] += New_Game.Game_Board[x][y1];
                        New_Game.Game_Board[x][y1] = 0;
                        break;
                    }

                    else if (New_Game.Game_Board[x][y1] != 0)
                    {
                        break;
                    }
                }
            }
        }

        for (int x = 0; x < New_Game.Board_Size; x++)
        {
            for (int y = 0; y < New_Game.Board_Size; y++)
            {
                if (New_Game.Game_Board[x][y] == 0)
                {
                    for (int y1 = y + 1; y1 < New_Game.Board_Size; y1++)
                    {
                        if (New_Game.Game_Board[x][y1] == 0)
                        {
                            continue;
                        }

                        else if (New_Game.Game_Board[x][y1] != 0)
                        {
                            New_Game.Game_Board[x][y] = New_Game.Game_Board[x][y1];
                            New_Game.Game_Board[x][y1] = 0;
                            break;
                        }
                    }
                }
            }
        }
        break;;
    }

    case 'a': // Left
    {
        for (int y = 0; y < New_Game.Board_Size; y++)
        {
            for (int x = 0; x < New_Game.Board_Size; x++)
            {
                if (New_Game.Game_Board[x][y] == 0)
                {
                    continue;
                }

                for (int x1 = x + 1; x1 < New_Game.Board_Size; x1++)
                {
                    if (New_Game.Game_Board[x][y] == New_Game.Game_Board[x1][y])
                    {
                        New_Game.Game_Board[x][y] += New_Game.Game_Board[x1][y];
                        New_Game.Game_Board[x1][y] = 0;
                        break;
                    }

                    else if (New_Game.Game_Board[x1][y] != 0)
                    {
                        break;
                    }
                }
            }
        }

        for (int y = 0; y < New_Game.Board_Size; y++)
        {
            for (int x = 0; x < New_Game.Board_Size; x++)
            {
                if (New_Game.Game_Board[x][y] == 0)
                {
                    for (int x1 = x + 1; x1 < New_Game.Board_Size; x1++)
                    {
                        if (New_Game.Game_Board[x1][y] == 0)
                        {
                            continue;
                        }

                        else if (New_Game.Game_Board[x1][y] != 0)
                        {
                            New_Game.Game_Board[x][y] = New_Game.Game_Board[x1][y];
                            New_Game.Game_Board[x1][y] = 0;
                            break;
                        }
                    }
                }
            }
        }
        break;
    }

    case 's': // Down
    {        
        for (int x = 0; x < New_Game.Board_Size; x++)
        {
            for (int y = New_Game.Board_Size - 1; y >= 0; y--)
            {
                if (New_Game.Game_Board[x][y] == 0)
                {
                    continue;
                }

                for (int y1 = y - 1; y1 >= 0; y1--)
                {
                    if (New_Game.Game_Board[x][y] == New_Game.Game_Board[x][y1])
                    {
                        New_Game.Game_Board[x][y] += New_Game.Game_Board[x][y1];
                        New_Game.Game_Board[x][y1] = 0;
                        break;
                    }

                    else if (New_Game.Game_Board[x][y1] != 0)
                    {
                        break;
                    }
                }
            }
        }
        
        for (int y = New_Game.Board_Size - 1; y >= 0; y--)
        {
            for (int x = 0; x < New_Game.Board_Size; x++)
            {
                if (New_Game.Game_Board[x][y] != 0)
                {
                    continue;
                }

                for (int y1 = y - 1; y1 >= 0; y1--)
                {
                    if (New_Game.Game_Board[x][y1] == 0)
                    {
                        continue;
                    }
                    
                    else if (New_Game.Game_Board[x][y1] != 0)
                    {
                    New_Game.Game_Board[x][y] = New_Game.Game_Board[x][y1];
                    New_Game.Game_Board[x][y1] = 0;
                    break;
                    }
                }
            }
        }
        break;
    }

    case 'd': // Right
    {
        
        for (int y = 0; y < New_Game.Board_Size; y++)
        {
            
            for (int x = New_Game.Board_Size - 1; x >= 0; x--)
            {
                if (New_Game.Game_Board[x][y] == 0)
                {
                    continue;
                }
                

                for (int x1 = x - 1; x1 >= 0; x1--)
                {
                    if (New_Game.Game_Board[x][y] == New_Game.Game_Board[x1][y])
                    {
                        New_Game.Game_Board[x][y] += New_Game.Game_Board[x1][y];
                        New_Game.Game_Board[x1][y] = 0;
                        break;
                    }

                    else if (New_Game.Game_Board[x1][y] != 0)
                    {
                        break;
                    }
                }
            }
        }

        for (int y = 0; y < New_Game.Board_Size; y++)
        {
            for (int x = New_Game.Board_Size - 1; x >= 0; x--)
            {
                if (New_Game.Game_Board[x][y] != 0)
                {
                    continue;
                }

                for (int x1 = x - 1; x1 >= 0; x1--)
                {
                    if (New_Game.Game_Board[x1][y] != 0)
                    {
                        New_Game.Game_Board[x][y] += New_Game.Game_Board[x1][y];
                        New_Game.Game_Board[x1][y] = 0;
                        break;
                    }
                }
            }
        }
        break;
    }
    }
}

void Save_Current_Game(player_Information Current_Player, Game_Data &Current_Game)
{   
    std::vector<player_Information>::iterator head = std::find_if(Player_Data_Base.begin(), Player_Data_Base.end(), [=](player_Information Players){return Players.player_ID == Current_Player.player_ID;});

    std::vector<Game_Data>::iterator tail = std::find_if(head->Game_Storage.begin(), head->Game_Storage.end(), [=](Game_Data Games){return Games.Index == Current_Game.Index;});

    if (tail != head->Game_Storage.end())
    {
        head->Game_Storage.erase(tail);
    }
    head->Game_Storage.push_back(Current_Game);
}