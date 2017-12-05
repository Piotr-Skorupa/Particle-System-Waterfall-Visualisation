#include "MyCube.h"

void MyCube::setup()
{
	color = ofColor(199, 199, 199);
}

void MyCube::draw()
{
	
	ofSetColor(color);
	ofFill();
	ofDrawBox(100.0, 200.0, 0.0, 300.0, 500.0, 300.0);
	ofNoFill();
	ofSetColor(0);
	ofDrawBox(100.0, 200.0, 0.0, 300.0, 500.0, 300.0);
	
	
}