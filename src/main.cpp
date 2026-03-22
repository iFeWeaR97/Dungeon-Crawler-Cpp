#include <iostream>
#include <string>
#include <json.hpp>
#include <fstream>
#include <player.hpp>
#include <saveFile.hpp>
#include <enemy.hpp>
#include <menulogic.hpp>
#include <gamelogic.hpp>
#include <exphandler.hpp>
#include <thread>
#include <mutex>

using namespace std;
std::mutex mtx;
bool running = true; // noch nicht implementiert 

// Multithreading später implimentieren für autoamtisches speichern alle 3 min z.B

int main()
{
    Player player;
    Levels levels;

    char input;
    thread exp(expHandlerPlayer, ref(player), ref(levels)); //EXP im Hintergrund

    WelcomeMessage();
    //levelUp(player);

    while (true)
    {
        cin >> input;
        input = tolower(input);

        switch (input)
        {
        case 'e':
            displayPlayerInfo(player);
            break;
        case 'c':
            checkUsername(player);
            break;
        case 'm':
            returnToMenu();
            break;
        case 's':
            if (player.username.empty())
            {
                cout << "No user exists!\n";
            }
            else
            {
                cout << "Saving player info...\n";
                savePlayerInfo(player);
                cout << "Player info saved successfully.\n";
            }
            break;
        case 'l':
        {
            ifstream file("saveFile/player.json");

            if (!file || file.peek() == ifstream::traits_type::eof())
            {
                cout << "No save file found or file is empty!\n";
            }
            else
            {
                cout << "Loading player info...\n";
                loadPlayerInfo(player);
                cout << "Player loaded successfully.\n";
            }
            break;
        }
        case 'd':
        {
            player.health -= 10;

            if (player.health == 0)
            {
                playerDead(player);
                exp.join();
                break;
            }

            break;
        }
        case 'q':
        {
            cout << "Program ended." << endl;
            running = false;
            exp.join();
            return 0;
        }
        default:
            cout << "Invalid input." << endl;
    }
}
}
