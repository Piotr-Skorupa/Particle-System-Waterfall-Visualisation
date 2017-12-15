#include "CollidingBall.h"

CollidingBall::CollidingBall(){

}

void CollidingBall::setup(float x1, float y1, float z1)
{
	x = x1;
	y = y1;
	z = z1;
	radius = 70.0;
	mass = 20.0;
	isAlive = true;

	color = ofColor(115, 59, 36);
	
}

