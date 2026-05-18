#pragma once

#include <string>

using namespace std;

struct Player
{
    string username;
    string level = "No level";
    double health = 100.0;
    double experience = 0;
    double gold = 0;
};


void creatPlayer(Player &player, string username, string level, double health, double experience);
void displayPlayerInfo(const Player &player);
void checkUsername(Player &player);
void playerDead(Player &player);
