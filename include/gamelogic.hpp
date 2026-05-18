#pragma once

#include <string>
#include <json.hpp>
#include <fstream>
#include <player.hpp>
#include <saveFile.hpp>
#include <enemy.hpp>

struct GameState
{
    bool isDay = true;
    bool isInCombat = false;
    bool isGameOver = false;
    string currentLocation = "Village";
    int dayCount = 0;

};


void gameLogicGlobal();
void isDayTime();
void VillageLogic();
void MerchantLogic();
void GoldLogic();


