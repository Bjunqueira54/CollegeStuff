#pragma once

typedef struct BallEntity
{
	double x;
	double y;

	int ascending;
	int right;

	int speed;
} Ball, *pBall;