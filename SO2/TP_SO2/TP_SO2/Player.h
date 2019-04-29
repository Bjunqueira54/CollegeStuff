#ifndef PLAYER_H
#define PLAYER_H

struct PlayerEntity
{
	//Client Vars
	char *name;
	int score;

	//Barrier Vars
	double x;
	double y;

	int size;


};

typedef struct PlayerEntity Player, *pPlayer;

#endif