#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <stack>

struct Player_Information
{
    std::string ID{"Stephenisstupid."};
    std::string Password{"0"};
};

std::vector<Player_Information> User_Data_Base;

void Creating_New_Player(std::string ID, std::string Password)
{
    do
    {
        if (std::find_if(User_Data_Base.begin(), User_Data_Base.end(), [=](std::vector<Player_Information>::iterator a)
                         { return a->ID == ID; }) != User_Data_Base.end() &&
                ID != "Stephenisstupid." ||
            ID == "")
        {
            std::cout << "This User Name is already used or User Name can not be empty." << '\n';
        }
        std::cout << "User Name: ";
        std::cin >> ID;
    } while (std::find_if(User_Data_Base.begin(), User_Data_Base.end(), [=](std::vector<Player_Information>::iterator a)
                          { return a->ID == ID; }) != User_Data_Base.end());
    std::cout << "User Name Set!" << '\n';
    std::cout << "Welcome " + ID << '\n';

    std::cout << "Password: ";
    std::cin >> Password;

    std::cout << "Please Re-enter Password: ";
    std::string Password_Copy;
    std::cin >> Password_Copy;

    while (Password != Password_Copy)
    {
        std::cout << "Please Re-enter Password : ";
        std::cin >> Password_Copy;
    }
}