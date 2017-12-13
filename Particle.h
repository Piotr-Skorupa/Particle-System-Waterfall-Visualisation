#pragma once
#include "ofMain.h"
#include <ctime>
#include <cmath>

class Particle 	
{
protected:
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
	float barierY;
	float barierZ;
	double lifeTime;
	clock_t lifeTimer;
	
	void setV0();
	

public:
	
	Particle();
	Particle(int x1, int y1, int z1);
	virtual ~Particle();
	virtual void setup(int x1, int y1, int z1);
	void draw();
	
	float getX();
	float getY();
	float getZ();
	double getLifeTime();
	void check_lifeTime();
	double fRand(double fMin, double fMax);
	void odbicie();
	void gravity();
	void ruch_prostoliniowy();
	void opor();
	void check_collision_with_ball(Particle object);



};

