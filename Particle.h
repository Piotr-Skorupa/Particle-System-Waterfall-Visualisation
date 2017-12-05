#pragma once
#include "ofMain.h"

class Particle 	
{
	//ofSpherePrimitive sphere;
	ofTexture texture;
	ofColor color;
	float x, y, z, v;
	float x0, y0, z0, v0;
	float radius; 
	float mass;
	float dt;
	float g;
	bool isAlive;
	bool startGravity;
	float barier;
	
	void setV0();
public:
	
	Particle();
	~Particle();
	void setup(int x1, int y1, int z1);
	void draw();
	void gravity();
	void ruch_prostoliniowy();
	void opor();
	float getX();
	float getY();
	float getZ();
	



};

