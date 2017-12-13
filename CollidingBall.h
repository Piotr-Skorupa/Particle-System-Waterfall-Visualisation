#pragma once
#include "Particle.h"
#include "ofMain.h"

class CollidingBall :
	public Particle
{
public:
	CollidingBall();
	void setup(float x1, float y1, float z1);
};

