#include "MainMenuState.h"

MainMenuState::MainMenuState(GameData* gData): GameState(gData) {}

void MainMenuState::ShowCredits()
{
    Interface::PrintCredits();
}

void MainMenuState::ShowHelpSection()
{
    Interface::PrintHelpSection();
}

void MainMenuState::ShowMenu()
{
    Interface::PrintMainMenu();
}

MainMenuState::~MainMenuState() {}