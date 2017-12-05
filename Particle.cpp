#include "Particle.h"



Particle::Particle()
{
	
}


 Particle::~Particle()
{

}

void Particle::setup(int x1, int y1, int z1)
{
	//wartosci modyikowane na biezaco
	x = x1;
	y = y1;
	z = z1;
	//stale wartosci poczatkowe
	x0 = x1;
	y0 = y1;
	z0 = z1;

	//reszta danych
	radius = 2.0;
	v = 20.0;
	v0 = v;
	mass = 0.3;
	dt = 0.1;
	g = -9.81;
	isAlive = true;
	startGravity = false;
	
	// bariera zywotnosci
	barier = 0 + (rand() % static_cast<int>(140 - 0 + 1));

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
		z = z + v0 * dt;
		y = y + v * dt;
		v = v + g * dt;
		if (y < barier) {
			setup(x0,y0,z0);
		}
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