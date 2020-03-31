#ifndef INTERFACE_H
#define INTERFACE_H

#include "includes.h"
#include "Game.h"

class Interface
{
	Game *game;
	bool quit;
	char opt;

public:

	Interface();

	void run();

	~Interface();

private:

	void drawWelcomeScreen();
	void drawMainMenu();
	void ShowCredits();
	char Read();
	void clear();

	void MainMenu();
};

#endif