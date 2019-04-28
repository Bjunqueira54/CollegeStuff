#include "Game.h"

Game::Game()
{
    playing = true;
    choice = 0;
}

void Game::mainMenu()
{
    cout << "Main Menu" << endl;
    cout << "1 - Travel" << endl;
    cout << "2 - Shop" << endl;
    cout << "3 - Level Up" << endl;
    cout << "4 - Rest" << endl;
    cout << "0 - Quit" << endl;
    
    cin >> choice;
    
    switch(choice)
    {
        case 0:
            playing = false;
            break;
        default:
            break;
    }
}

Game::~Game() {}