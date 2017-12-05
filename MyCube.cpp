#include "MyCube.h"

void MyCube::setup()
{
	color = ofColor(199, 199, 199);
	ofLoadImage(texture, "resources/rock.jpg");
	
}

void MyCube::draw()
{
	
	ofSetColor(color);
	ofFill();
	//texture.bind();
	ofDrawBox(100.0, 200.0, 0.0, 300.0, 500.0, 300.0);
	//texture.unbind();
	ofNoFill();
	//ofSetColor(0);
	//ofDrawBox(100.0, 200.0, 0.0, 300.0, 500.0, 300.0);
	
	
}