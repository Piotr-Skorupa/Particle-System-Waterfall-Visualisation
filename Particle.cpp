#include "Particle.h"



Particle::Particle()
{
	
}


 Particle::~Particle()
{

}

void Particle::setup(int x1, int y1, int z1)
{
	x = x1;
	y = y1;
	z = z1;
	radius = 3.0;
	v = 20.0;
	mass = 0.3;
	dt = 0.1;
	g = -9.81;
	isAlive = true;
	startGravity = false;

	//kolory wody 
	ofColor c1 = ofColor(0, 0, 205);
	ofColor c2 = ofColor(0, 128, 255);
	ofColor c3 = ofColor(41, 39, 108);
	
	//losowy kolor dla poszczegolnych particli
	int result = 1 + (rand() % static_cast<int>(3 - 1 + 1));
	switch (result) {
	case 1:
		color = c1;
		break;
	case 2:
		color = c2;
		break;
	case 3:
		color = c3;
		break;
	default:
		color = c1;
		break;
	}
}

void Particle::draw()
{	
	
	if (isAlive == true) {
		ofSetColor(color);
		ofFill();
		ofDrawSphere(x, y, z, radius);
	}
}

void Particle::gravity() {
	
	if (isAlive == true) {
		// sila grawitacji 
		setV0();
		y = y + v * dt;
		v = v + g * dt;
	}
}

void Particle::ruch_prostoliniowy() {
	//funkcja ruchu 
	if (isAlive == true) {
		z = z + v* dt;
	}
}

void Particle::opor() {
	//funkcja oporu (lepkosci)
}

float Particle::getX()
{
	return x;
}

float Particle::getY()
{
	return y;
}

float Particle::getZ()
{
	return z;
}

void Particle::setV0() {
	if (startGravity == false) {
		v = 0;
		startGravity = true;
	}
}