#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
    GameData *gData;
    
public:

    GameState() = delete;
    GameState(const GameState& orig) = delete;
    GameState(GameData *gData);
    
    virtual GameData* getGameData() { return gData; }
    
    virtual void ShowMenu() = 0;

    virtual ~GameState();
};

#endif