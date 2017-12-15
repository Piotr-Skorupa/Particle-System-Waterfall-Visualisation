#pragma once

#include "ofMain.h"
#include "MyCube.h"
#include "of3dGraphics.h"
#include "of3dPrimitives.h"
#include "Particle.h"
#include "CollidingBall.h"
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <ctime>

class ofApp : public ofBaseApp{

	

	public:

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		

		CollidingBall ball;
		double birth_time;
		clock_t birthTimer;
		ofVec3f lightVec;
		MyCube cube;
		MyCube smallCube;
		ofSoundPlayer sound;
		const int N = 10; // poczatkowa ilosc particli
		const int VECTOR_MAX_SIZE = 15000;
		std::vector<Particle> krople;
		Particle prubny_obiekt;
		ofLight light; // creates a light and enables lighting
		ofEasyCam cam; // add mouse controls for camera movement
		std::string msg;

};
