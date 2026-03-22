#include <iostream>
#include <string>
#include <player.hpp>
#include <exphandler.hpp>
#include <thread>
#include <chrono>

using namespace std;

void levelUp(Player &player);

void expHandlerPlayer(Player &player, Levels &levels)
{
    int result = 0;

    while (true)
    {
    levels.currentLevel = player.experience;

   // levelUp(player);

    if (levels.currentLevel == levels.lvl1_exp)
    {
        result =  levels.lvl2_exp - player.experience ;
        cout << "Congratulations! You gained a level! your current level is: " << levels.currentLevel << " next level in: " << result << endl;
        player.level = levels.lvl1;
    }
    else if (levels.currentLevel == levels.lvl2_exp)
    {
        result = 0;
        result = levels.lvl3_exp - player.experience ;
        cout << "Congratulations! You gained a level! your current level is: " << levels.currentLevel << " next level in: " << result << endl;
        player.level = levels.lvl2;
    }
    else if (levels.currentLevel == levels.lvl3_exp)
    {
        result = 0;
        result =  levels.lvl4_exp - player.experience ;
        cout << "Congratulations! You gained a level! your current level is: " << levels.currentLevel << " next level in: " << result << endl;
        player.level = levels.lvl3;
    }
    else if (levels.currentLevel == levels.lvl4_exp)
    {
        result = 0;
        result = levels.lvl5_exp - player.experience ;
        cout << "Congratulations! You gained a level! your current level is: " << levels.currentLevel << " next level in: " << result << endl;
        player.level = levels.lvl4;
    }
    else if (levels.currentLevel == levels.lvl5_exp)
    {
        cout << "You reached max level!" << endl;
        player.level = levels.lvl5;
    }
    }
}

/* void levelUp(Player &player)
{
        this_thread::sleep_for(chrono::seconds(5*60));
        int currentExp = player.experience += 5;
} */