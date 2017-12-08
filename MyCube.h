#pragma once
#include "ofMain.h"
#include "of3dPrimitives.h"

class MyCube 
{
	ofTexture texture;
	ofColor color;
	float x, y, z, sx, sy, sz;
public:
	
	void setup(float x1, float y1, float z1, float sx1, float sy1, float sz1);
	void draw();

};

