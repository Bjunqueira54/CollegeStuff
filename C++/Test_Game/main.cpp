#include "includes.h"
#include "Game.h"

int main(int argc, char** argv)
{
    Game game;
    
    while(game.getPlaying())
    {
        game.mainMenu();
    }
    
    return 0;
}