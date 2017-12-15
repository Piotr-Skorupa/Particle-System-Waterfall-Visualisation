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
	lifeTime = fRand(6.3,7.0);
	lifeTimer = std::clock();  //start timera

	//reszta danych
	radius = 2.0;
	vz = ofRandom(19, 25);
	v0 = vz;
	vx = 0;
	vy = 0;
	mass = 5.0;
	dt = 0.1;
	g = -9.81;
	isAlive = true;
	startGravity = false;
	
	// bariery kolizyjne
	barierY = 356.0;
	barierZ = 340.0;

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
		
		ruch();
		
		if (y < barierY && z < barierZ) {
			vy = -vy;
			vy = vy + g * dt * std::pow(mass,2);
			y = y + vy * dt;
			//z = v0;
		}
		else {
			y = y + vy * dt;
			vy = vy + g * dt;
		}
	}
}

void Particle::ruch_prostoliniowy() {
	//funkcja ruchu 
	if (isAlive == true) {
		z = z + vz* dt;
		
	}
}

void Particle::ruch() {
	//druga wersja ruchu prostoliniowego
	z = z + v0 * dt;
	x = x + vx *dt;
	
}

void Particle::check_collision_with_ball(Particle object)
{
	float diff_x = x - object.getX();
	float diff_y = y - object.getY();
	float diff_z = z - object.getZ();

	float difference_sum = std::sqrt(std::pow(diff_x,2) + std::pow(diff_y,2) + std::pow(diff_z,2));

	if (difference_sum <= (radius + object.get_radius())) {

		// check collision point
		float collisionPointX =((x * object.get_radius()) + (object.getX() * radius))
			/ (radius + object.get_radius());

		float collisionPointY =((y * object.get_radius()) + (object.getY() * radius))
			/ (radius + object.get_radius());
		float collisionPointZ =((z * object.get_radius()) + (object.getZ() * radius))
			/ (radius + object.get_radius());
		
		//wektor normalny od srodka kuli start obliczen
		float normal_vectorX = object.getX() - collisionPointX;
		float normal_vectorY = object.getY() - collisionPointY;
		float normal_vectorZ = object.getZ() - collisionPointZ;

		// odleglosc miedzy punktem kolizji a srodkiem kuli
		float dis_tance = std::sqrt(std::pow(object.getX() - collisionPointX, 2)+
			std::pow(object.getY() - collisionPointY, 2) +
			std::pow(object.getZ() - collisionPointZ, 2));
		// wynikowy wektor normalny
		normal_vectorX = normal_vectorX / dis_tance;
		normal_vectorY = normal_vectorY / dis_tance;
		normal_vectorZ = normal_vectorZ / dis_tance;

		// skladowa V prostopadla
		float v_prostopadle = vx * normal_vectorX + vy * normal_vectorY + v0 * normal_vectorZ;
		float normal_v_prostopadle = normal_vectorX * v_prostopadle + normal_vectorY * v_prostopadle + normal_vectorZ* v_prostopadle;
		float v_rownolegle = std::abs(vx - normal_v_prostopadle + vy - normal_v_prostopadle + v0 - normal_v_prostopadle);
		// wektory v 
		float vprostX = normal_vectorX * v_prostopadle;
		float vprostY = normal_vectorY * v_prostopadle;
		float vprostZ = normal_vectorZ * v_prostopadle;

		float vrownolX = vx - vprostX;
		float vrownolY = vy - vprostY;
		float vrownolZ = v0 - vprostZ;

		// FINALNY WEKTOR ODBICIA
		float vODB_x = vrownolX - 2 * vprostX;
		float vODB_y = vrownolY - 2 * vprostY;
		float vODB_z = vrownolZ - 2 * vprostZ;

		
		//ODBICIE
		vx += vODB_x;
		vy += vODB_y;
		v0 += vODB_z;

		x += vx * dt;
		//y += vy *dt;
		z += v0 *dt;

		
	}
}



void Particle::check_lifeTime() {
	double duration = (std::clock() - lifeTimer) / (double)CLOCKS_PER_SEC;
	if (duration > lifeTime) {
		isAlive = false;
	}
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

float Particle::get_radius() {
	return radius;
}

float Particle::getMass() {
	return mass;
}

double Particle::getLifeTime() {
	return lifeTime;
}