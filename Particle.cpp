#include "Particle.h"



Particle::Particle()
{
	
}

Particle::Particle(int x1, int y1, int z1)
{
	setup(x1, y1, z1);
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
	//czas zycia w sekundach
	lifeTime = fRand(7.3,8.0);
	lifeTimer = std::clock();  //start timera

	//reszta danych
	radius = 2.0;
	v = ofRandom(19, 24);
	v0 = v;
	mass = 5;
	dt = 0.1;
	g = -9.81;
	isAlive = true;
	startGravity = false;
	
	// bariery kolizyjne
	barierY = 356.0;
	barierZ = 300.0;

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
		opor();
		
		if (y < barierY && z < barierZ) {
			odbicie();
		}
		else {
			y = y + v * dt;
			v = v + g * dt;
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
	z = z + v0 * dt;
	//float D = (-6)*3.14*v0*0.003*radius;
	//float a = D / mass;
	//v0 = a*dt;
}

void Particle::check_collision_with_ball(Particle object)
{
	float diff_x = x - object.getX();
	float diff_y = y - object.getY();
	float diff_z = z - object.getZ();

	float difference_sum = diff_x*diff_x + diff_y*diff_y + diff_z*diff_z;

	if (difference_sum <= object.radius*object.radius) {
		v = -v;
	}


}



void Particle::check_lifeTime() {
	double duration = (std::clock() - lifeTimer) / (double)CLOCKS_PER_SEC;
	if (duration > lifeTime) {
		isAlive = false;
	}
}

void Particle::odbicie() {
	v = -v;
	v = v + g * dt * mass *4;
	y = y + v * dt;
}

//generate random double
double Particle::fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
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

double Particle::getLifeTime() {
	return lifeTime;
}