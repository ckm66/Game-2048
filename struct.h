#pragma once
#include <time.h>
#include <string.h>
#include <vector>

struct Game_Data
{
    int Index {0};
    time_t Game_Time;
    bool Completed {false};
    int Board_Size = 0;
    int Game_Board[11][11] {0};
    int Score {0};
};

struct player_Information
{
    std::string player_ID;
    std::string password;
    std::vector <Game_Data> Game_Storage;
};

std::vector<player_Information> Player_Data_Base;


