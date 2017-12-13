#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableSmoothing();
	ofEnableDepthTest();
	cam.setDistance(1000);
	ofBackground(0, 0, 0);
	ofSetFrameRate(60);
	birth_time = 0.5;
	birthTimer = std::clock();


	cube.setup(100.0, 200.0, 0.0, 300.0, 500.0, 300.0);
	smallCube.setup(100., 150.0, 170.0,300.0, 400.0, 300.0);
	ball.setup(100.0, 100.0, 470.0);

	for (int i = 0; i < N; i++) {
		int o1 =  75 + (rand() % static_cast<int>(125 - 75 + 1));
		int o2 = 453;
		int o3 = 0+(rand() % static_cast<int>(80 - 0 + 1));  
		
		krople.push_back(Particle());
		krople[i].setup(o1, o2, o3);
		
	}
	lightVec.set(0, 1000, 1330);
	light.setDirectional();
	ofEnableLighting();
	light.setOrientation(lightVec);
	light.enable();
	msg = "Author: Piotr Skorupa \nTo fullscreen press 'F' \nTo restart press 'R' \nTo exit press 'Esc'";
	msg += "\n\nfps: " + ofToString(ofGetFrameRate(), 2);


	
		
	
}
//--------------------------------------------------------------
void ofApp::update(){
		
	if (krople.size() >= VECTOR_MAX_SIZE) {
		
		krople.erase(krople.begin(), krople.begin()+3000);
		
	}
	else {
		for (int i = 0; i < 30; i++) {
			int o1 = 75 + (rand() % static_cast<int>(125 - 75 + 1));
			int o2 = 453;
			int o3 = 0 + (rand() % static_cast<int>(80 - 0 + 1));
			krople.push_back(Particle(o1, o2, o3));
		}
	}
	for (int i = 0; i < krople.size() - 1; i++) {
		
		krople[i].check_lifeTime();
		if (krople[i].getZ() > 150) {
			krople[i].gravity();
			krople[i].check_collision_with_ball(ball);
		}
		else {
			krople[i].ruch_prostoliniowy();
		}
		
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	cam.begin();
	ofPushMatrix();
	cube.draw();
	smallCube.draw();
	ball.draw();
	for (int i = 0; i < krople.size()-1; i++) {
		krople[i].draw();
	}
	
	ofPopMatrix();	
	cam.end();
	ofSetColor(255);
	ofDrawBitmapStringHighlight(msg, 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	//fullscreen on/off
	case 'f':
		ofToggleFullscreen();
		break;
	//restart animation
	case 'r':
		krople.clear();
		setup();
		break;
	//see number of particles
	case 's':
		std::cout << krople.size() << std::endl;
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
