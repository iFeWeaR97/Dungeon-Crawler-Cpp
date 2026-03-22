#pragma once

#include <string>
#include <player.hpp>

struct Levels
{
    const string lvl1 = "Farmer";
    const string lvl2 = "Knight";
    const string lvl3 = "Baron";
    const string lvl4 = "Duke";
    const string lvl5 = "Elite";
    const int lvl1_exp = 500;  
    const int lvl2_exp = 2000; 
    const int lvl3_exp = 5000;
    const int lvl4_exp = 15000;
    const int lvl5_exp = 30000;
    int currentLevel =0;
};

//void levelUp(Player &player);
void expHandlerPlayer(Player &player,Levels &levels);