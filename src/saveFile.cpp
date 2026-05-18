#include <json.hpp>
#include <iostream>
#include <player.hpp>
#include <fstream>

using json = nlohmann::json;


void savePlayerInfo(Player &player)
{
    json saveFile;

    saveFile["username:"] = player.username;
    saveFile["level:"] = player.level;
    saveFile["health:"] = player.health;
    saveFile["experience:"] = player.experience;
    saveFile["gold:"] = player.gold;

    std::ofstream file("saveFile/player.json");
    file << saveFile.dump(4) << std::endl;
    file.close();
}

void loadPlayerInfo(Player &player)
{
    std::ifstream file("saveFile/player.json");
    json saveFile;
    file >> saveFile;

    player.username = saveFile.value("username:", "Unknown");
    player.level = saveFile.value("level:", "Rankless");
    player.health = saveFile.value("health:", 100.0);
    player.experience = saveFile.value("experience:", 0.0);
    player.gold = saveFile.value("gold:", 0.0);

    file.close();
}
