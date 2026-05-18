#include <iostream>
#include <string>
#include <menulogic.hpp>

using namespace std;

void WelcomeMessage();
void retunToMenu();

void menuLogicGlobal()
{
   
}

 void WelcomeMessage()
{
    cout << "Welcome to Terminal Crawl!" << endl;
    cout << "Embark your Journey fight monsters level up buy items and lands!" << endl;
    cout << "\nPress\nE to display player info\nV to visist the village\nS to save\nL to load\nQ to quit\nC to creat a User\nM to return to menu\n"
         << endl;
}

void returnToMenu()
{
   WelcomeMessage();
}