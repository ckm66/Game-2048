#pragma once
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

struct player_Information
{
    std::string player_ID;
    std::string password;
};

std::vector<player_Information> Player_Data_Base;

void sign_up()
{
    player_Information New_User;
    bool Repeated{false};

    while (true)
    {
        std::cout << "Player ID: ";
        std::getline(std::cin, New_User.player_ID);

        if (std::find_if(Player_Data_Base.begin(), Player_Data_Base.end(), [=](player_Information player)
                      { return New_User.player_ID == player.player_ID; }) == Player_Data_Base.end())
        {
            std::cout << "Registeration Successful!" << '\n';
            std::cout << "Welcome! " << New_User.player_ID << '\n';
            break;
        }

        else
        {
            std::cout << "This Player Name has been used" << '\n';
        }
    }
    Player_Data_Base.push_back(New_User);

    while (true)
    {
        
    }
}
