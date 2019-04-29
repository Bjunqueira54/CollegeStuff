#include "Interface.h"

Interface::Interface()
{
	game = new Game();
	this->quit = false;
}

void Interface::run()
{
	drawWelcomeScreen();
	_getch();
	MainMenu();
}

void Interface::drawWelcomeScreen()
{
	cout << "Welcome to my quick RPG" << endl;
}

void Interface::drawMainMenu()
{
	cout << "1 - Start Game" << endl;
	cout << "2 - Credits" << endl;
	cout << "0 - Quit Game" << endl;
}

void Interface::ShowCredits()
{
	this->clear();

	cout << "Lead Programmer: Gothic Dread" << endl;
	_getch();

	this->clear();
}

char Interface::Read()
{
	return (char) _getch();
}

void Interface::MainMenu()
{
	while (!quit)
	{
		drawMainMenu();

		opt = Read();

		switch (opt)
		{
		case '1':

			break;
		case '2':
			ShowCredits();
			break;
		case '0':
			quit = true;
			break;
		}
	}
}

void Interface::clear()
{
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	SetConsoleCursorPosition(console, topLeft);
}

Interface::~Interface()
{
	delete game;
}