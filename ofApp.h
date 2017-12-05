#pragma once

#include "ofMain.h"
#include "MyCube.h"
#include "of3dGraphics.h"
#include "Particle.h"
#include <iostream>
#include <vector>
#include <random>

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

		ofVboMesh mesh;
		const int side = 200.0f;
		MyCube cube;
		const int N = 1000; // poczatkowa ilosc particli
		std::vector<Particle> krople;
		Particle prubny_obiekt;
		ofLight light; // creates a light and enables lighting
		ofEasyCam cam; // add mouse controls for camera movement
		
};
