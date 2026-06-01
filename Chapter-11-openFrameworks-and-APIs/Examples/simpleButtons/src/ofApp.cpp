#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//load in image file
	btnImg.load("playBTN.png");

	//setup button size and position
	btn1.set(20, 100, 200, 100);
	btn2.set(270, 100, 50, 50);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//set colour to white so no tint on image
	ofSetColor(255);
	//drawing button image based on first rectangle values
	btnImg.draw(btn1);

	//set colour to blue for second button
	ofSetColor(0, 0, 255);
	//draw button using draw rectange with second rectangle values
	ofDrawRectangle(btn2);
}



//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//check if mouse positions are inside either of the buttons
	if (btn1.inside(x, y)) {
		cout << "Image Button Clicked" << endl;
	}

	if (btn2.inside(x, y)) {
		cout << "Button Clicked" << endl;
	}
}
