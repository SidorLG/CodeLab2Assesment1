#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	colour = colours::NONE; //set colour enum to none
	pressed = false;//set pressed to false

	//load in image files
	happy.load("happy.png");
	sad.load("sad.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//check value of colour enum and set background colour accordingly
	if (colour == colours::NONE) {
		ofSetBackgroundColor(0);//black
	}else if (colour == colours::RED) {
		ofSetBackgroundColor(255, 0, 0);//red
	}
	else if (colour == colours::GREEN) {
		ofSetBackgroundColor(0, 255, 0);//green
	}
	else if (colour == colours::BLUE) {
		ofSetBackgroundColor(0, 0, 255);//blue
	}

	if (pressed == false) {//check if pressed is false
		sad.draw((ofGetWidth() / 2) - 50, (ofGetHeight() / 2 - 50), 100, 100);//draw sad face in middle of screen
	}
	else {
		happy.draw((ofGetWidth() / 2) - 50, (ofGetHeight() / 2 - 50), 100, 100);//draw happy face in middle of screen
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//check for letter presses and set colour enum accordingly
	if (key == 'r') {
		colour = colours::RED;
	}
	else if (key == 'g') {
		colour = colours::GREEN;
	}
	else if (key == 'b') {
		colour = colours::BLUE;
	}
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	//if any key is released set colours enum to none
	colour = colours::NONE;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	pressed = true;//when mouse press is triggered set pressed to true
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	pressed = false;//when mouse release is triggered set pressed to false
}

