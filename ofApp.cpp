#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableSmoothing();
	ofEnableDepthTest();
	ofBackground(0, 0, 0);
	ofSetFrameRate(30);
	//prubny_obiekt.setup(100, 450, 155); // probny obiekt rysowany w mijescu spadku wodospadu 
	cube.setup();
	for (int i = 0; i < N; i++) {
		int o1 =  75 + (rand() % static_cast<int>(125 - 75 + 1));
		int o2 = 450;
		int o3 = 0+(rand() % static_cast<int>(30 - 0 + 1));  // wspolrzedna spadku gdy bedzie 155 to grawitacja ON !
		Particle * p = new Particle();
		krople.push_back(*p);
		krople[i].setup(o1, o2, o3);
		delete p;
	}
	
	light.enable();
	
	
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < N; i++) {
		
		
		if (krople[i].getZ() > 155) {
			krople[i].gravity();
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
	for (int i = 0; i < N; i++) {
		krople[i].draw();
	}
	
	ofPopMatrix();
	cam.end();
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
		setup();
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
