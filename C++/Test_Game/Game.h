#ifndef GAME_H
#define GAME_H

#include "includes.h"

class Game
{
    int choice;
    bool playing;
    
public:
    
    Game();
    
    void mainMenu();
    
    bool getPlaying() { return this->playing; }
    
    virtual ~Game();
};

#endif