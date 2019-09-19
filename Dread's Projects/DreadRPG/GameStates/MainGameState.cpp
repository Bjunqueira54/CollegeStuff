#include "MainGameState.h"

MainGameState::MainGameState(string name)
{
    gData = new GameData(name);
}

MainGameState::~MainGameState() {}