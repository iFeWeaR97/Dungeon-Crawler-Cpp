#include <iostream>
#include <string>
#include <player.hpp>
#include <exphandler.hpp>

using namespace std;

void creatPlayer(Player &player, string username, string level, double health, double experience)
{
    player.username = username;
    player.level = level;
    player.health = health;
    player.experience = experience;
}

void checkUsername(Player &player)
{
    Levels levels;

    while (true)
    {
        cout << "Enter your username: ";
        cin >> player.username;

        if (player.username.length() >= 1 && player.username.length() <= 30)
        {
            cout << "Username is valid." << endl;

            creatPlayer(player, player.username, player.level, 100.0, levels.currentLevel);
            break;
        }
        else
        {
            cout << "Username must be between 3 and 15 characters." << endl;
        }
    }
}

void displayPlayerInfo(const Player &player)
{
    cout << "\n--- Player Info ---\n";
    cout << "Username: " << player.username << endl;
    cout << "Level: " << player.level << endl;
    cout << "Health: " << player.health << endl;
    cout << "Experience: " << player.experience << endl;
    cout << "Gold: " << player.gold << endl;
}

void playerDead(Player &player)
{
        cout << "Player " << player.username << " is dead!" << endl;
        cout << "GAME OVER!" << endl;
        cout << "Press C to create a new player." << endl;
        player.experience = 0;
        player.username = "";
        player.level = "";
}
