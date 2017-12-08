#include "MyCube.h"

void MyCube::setup(float x1, float y1, float z1, float sx1, float sy1, float sz1)
{
	color = ofColor(199, 199, 199);
	ofLoadImage(texture, "resources/rock.jpg");
	x = x1;
	y = y1;
	z = z1;
	sx = sx1;
	sy = sy1;
	sz = sz1;
	
}

void MyCube::draw()
{
	
	ofSetColor(color);
	ofFill();
	//texture.bind();
	ofDrawBox(x,y,z,sx,sy,sz);
	//texture.unbind();
	ofNoFill();
	//ofSetColor(0);
	//ofDrawBox(100.0, 200.0, 0.0, 300.0, 500.0, 300.0);
	
	
}