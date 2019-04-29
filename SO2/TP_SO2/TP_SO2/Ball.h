#ifndef BALL_H
#define BALL_H

#include "includes.h"
#include "Player.h"

typedef struct BallEntity
{
	double x; //X Position
	double y; //Y Position

	int movementMode; //1 - Up+Right, 2 - Up+Left, 3 - Down+Right, 4 - Down+Left

	double speed; //Maybe an int?

	pPlayer lastPlayer; //Last player that touched the ball
} Ball, *pBall;

#endif