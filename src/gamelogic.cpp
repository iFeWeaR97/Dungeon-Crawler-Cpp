#include <iostream>
#include <string>
#include <json.hpp>
#include <fstream>
#include <player.hpp>
#include <saveFile.hpp>
#include <enemy.hpp>
#include <gamelogic.hpp>
#include <menulogic.hpp>

using namespace std;

void gameLogicGlobal()
{
    GameState gameState;

    if (gameState.currentLocation == "Village")
    {
        VillageLogic();
    }
}

void isDayTime()
{
    GameState gameState;

    if (gameState.isDay)
    {
        cout << "It's daytime. You can explore the world, gather resources, and interact with NPCs." << endl;
    }
    else
    {
        cout << "It's nighttime. Be cautious, as stronger enemies may appear." << endl;
    }
}

void VillageLogic()
{
    Player player;
    cout << "Welcome to the Village! Here you can rest and trade." << endl;
    cout << "Press 'r' to rest and recover health, or 't' to trade with the merchant." << endl;

    char inputUser;
    cin >> inputUser;
    inputUser = tolower(inputUser);

    switch (inputUser)
    {
    case 'r':
        cout << "You take a rest and recover some health." << endl;
        player.health = min(player.health + 20.0, 100.0);
        cout << "Your current health: " << player.health << endl;
        break;
    case 't':
        cout << "You approach the merchant to trade." << endl;
        MerchantLogic();
        break;
    default:
        cout << "Invalid input. Please try again." << endl;
        break;
    }
}
void MerchantLogic()
{
    Player player;

    bool inMerchant = true;

    while(inMerchant)
    {

    cout << "Welcome to the merchant! Here you can buy and useful items." << endl;
    cout << "Press 'h' to buy a health potion for 20 gold" << endl;
    cout << "Press 's' to buy a sword for 50 gold" << endl;
    cout << "Press 'a' to buy armor for 40 gold" << endl;
    cout << "Press 'e' to exit the merchant" << endl;

    char inputMerchant;
    cin >> inputMerchant;
    inputMerchant = tolower(inputMerchant);

    switch (inputMerchant)
    {
    case 'h':
        if (player.gold >= 20)  
        {
            cout << "You buy a health potion for 20 gold." << endl;
        }
        else
        {
            cout << "You don't have enough gold to buy a health potion." << endl;
        }
        break;
    case 's':
        if(player.gold >= 50)  
        {
            cout << "You buy a sword for 50 gold." << endl;
        }
        else
        {
            cout << "You don't have enough gold to buy a sword." << endl;
        }
        break;
    case 'a':
        if(player.gold >= 40)  
        {
        cout << "You buy armor for 40 gold." << endl;
        }
        else
        {
            cout << "You don't have enough gold to buy armor." << endl;
        }
        break;
    case 'e':
        inMerchant = false;
        cout << "You exit the merchant." << endl;
        WelcomeMessage();
        break;
    default:
        cout << "Invalid input. Please try again." << endl;
        break;
    }
}}
void GoldLogic()
{
    Player player;
    cout << "You have " << player.gold << " gold." << endl;
}
