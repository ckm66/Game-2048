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

    std::cout << "Player ID: ";
    std::cin >> New_User.player_ID;

    if (std::find_if(Player_Data_Base.begin(), Player_Data_Base.end(), [=](player_Information player)
                     { return New_User.player_ID == player.player_ID; }) != Player_Data_Base.end())
    {

        std::cout << "This Player Name has been using.";
    }
}
