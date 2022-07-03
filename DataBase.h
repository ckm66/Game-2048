#pragma once
#include <iostream>
#include <fstream>
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

    while (true)    // Set Up Player ID
    {
        std::cout << "Player ID: ";
        std::getline(std::cin, New_User.player_ID);

        if (std::find_if(Player_Data_Base.begin(), Player_Data_Base.end(), [=](player_Information player)
                      { return New_User.player_ID == player.player_ID; }) == Player_Data_Base.end())
        {
            std::cout << "Player ID Registeration Successful!" << '\n';
            break;
        }

        else
        {
            std::cout << "This Player Name has been used" << '\n';
        }
    }
    

    while (true)
    {
        std::cout << "Password: ";
        std::getline(std::cin, New_User.password);

        std::string Comparation_Password;
        std::cout << "Please re-enter to Confirm: " ;
        std::getline(std::cin, Comparation_Password);

        if (New_User.password == Comparation_Password)
        {
            Player_Data_Base.push_back(New_User);
            std::cout << "Account set up!" << '\n';
            std::cout << "Welcome! " << New_User.player_ID << '\n';
            break;
        }

        else
        {
            std::cout << "Password does not match. Pleasw Re-Enter Password." << '\n';
        }
    }
}

