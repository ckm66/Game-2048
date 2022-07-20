#pragma once
#include <ncurses.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include "struct.h"
#include "Core.h"
#include "Display.h"

void sign_Up(int ymax, int xmax, player_Information &New_User)
{
    bool Repeated{false};

    while (true) // Set Up Player ID
    {
        std::pair <std::string, std::string> id_And_Password;
        id_And_Password = Registeration_Page(ymax, xmax, Repeated);
        New_User.player_ID = id_And_Password.first;

        if (std::find_if(Player_Data_Base.begin(), Player_Data_Base.end(), [=](player_Information player) { return New_User.player_ID == player.player_ID; }) == Player_Data_Base.end())
        {
            Player_Data_Base.push_back(New_User);
            break;
        }
        Repeated = true;
    }
}

void sign_In(int ymax, int xmax, player_Information &Player)
{   
    bool unfound {false};
    while (true)
    {
        std::pair <std::string, std::string> user_ID_And_Password;
        user_ID_And_Password  = Login_Page(ymax, xmax, unfound);

        Player.player_ID = user_ID_And_Password.first;
        Player.password = user_ID_And_Password.second;

        std::vector <player_Information>::iterator Index = std::find_if(Player_Data_Base.begin(), Player_Data_Base.end(), [=](player_Information Save){return Save.player_ID == Player.player_ID && Save.password == Player.password;});
        if (Index != Player_Data_Base.end())
        {
            Player = *Index;
            break;
        }
        unfound = true;
    }
}

void Input_Game_Data(Game_Data &Game, std::string column)
{
    std::stringstream column_(column);
    std::string Block;
    int x{0};
    int y{0};
    while (std::getline(column_, Block, ','))
    {
        Game.Game_Board[x][y] = stoi(Block);
        x++;
        if (x > 11)
        {
            x = 0;
            y++;
        }
    }
}

void Read_Player_Game_Base(player_Information &Player)
{
    std::fstream Game(Player.player_ID + "_Game_Record.csv", std::fstream::in);
    std::string line;
    while (std::getline(Game, line))
    {
        if (line == "Player_ID,Completed?,Game Index,Game Time,Board Size,")
        {
            continue;
        }

        Game_Data Game;
        std::stringstream line_(line);
        std::string column;
        int count = 0;
        while (std::getline(line_, column, ','))
        {
            switch (count)
            {
            case 0: // Player ID
            {
                break;
            }

            case 1: // Completed
            {
                if (column == "0")
                {
                    Game.Completed = false;
                    break;
                }

                Game.Completed = true;

                break;
            }

            case 2:
            {
                Game.Index = std::stoi(column);
                break;
            }

            case 3:
            {
                Game.Board_Size = std::stoi(column);
                break;
            }

            default:
            {
                Input_Game_Data(Game, column);
            }
            }
            count++;
        }
    }
}

void read_Player_Data_Base()
{
    std::fstream Player("Player Data Base.csv", std::fstream::in);

    if (!Player.is_open())
    { return; }

    std::string line;
    while (std::getline(Player, line))
    {
        if (line == "Player ID,Password")
        {
            continue;
        }

        player_Information New_Player;
        std::stringstream line_(line);
        int count{0};
        std::string column;
        while (std::getline(line_, column, ','))
        {
            switch (count)
            {
            case 0:
                New_Player.player_ID = column;
                break;

            case 1:
                New_Player.password = column;
                break;
            }
            count++;
        }
        Read_Player_Game_Base(New_Player);
        Player_Data_Base.push_back(New_Player);
    }
    Player.close();
}

void Generate_Game_Data_Base(std::vector<player_Information>::iterator Player, std::string player_ID)
{
    std::fstream Game_Record(player_ID + "_Game_Record.csv", std::fstream::out | std::fstream::trunc);
    Game_Record << "Player_ID" << ','
                << "Completed?" << ','
                << "Game Index" << ','
                //<< "Game Time" << ','
                << "Board Size" << ','
                << '\n';
    for (int Game_Number = 0; Game_Number != Player->Game_Storage.size(); Game_Number++)
    {
        Game_Record << Player->player_ID << ','
                    << Player->Game_Storage[Game_Number].Completed << ','
                    << Player->Game_Storage[Game_Number].Index << ','
                    //<< Player->Game_Storage[Game_Number].Game_Time << ','
                    << Player->Game_Storage[Game_Number].Board_Size << ',';

        for (int y = 0; y < 10; y++)
        {
            for (int x = 0; x < 10; x++)
            {
                Game_Record << Player->Game_Storage[Game_Number].Game_Board[x][y] << ',';
            }
        }
        Game_Record << '\n';
    }
}

void Generate_Player_Data_Base()
{
    std::fstream Player_Record("Player Data Base.csv", std::fstream::out | std::fstream::trunc);
    Player_Record << "Player ID" << ',' << "Password" << '\n';
    for (std::vector<player_Information>::iterator head = Player_Data_Base.begin(); head != Player_Data_Base.end(); head++)
    {
        Player_Record << head->player_ID << ',' << head->password << '\n';
        Generate_Game_Data_Base(head, head->player_ID);
    }
}

void Reset()
{
    remove("Player Data Base.csv");
}
