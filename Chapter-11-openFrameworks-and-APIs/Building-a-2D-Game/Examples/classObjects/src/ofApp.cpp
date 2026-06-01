#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    //Set number of circles to zero
    numCircles = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    //update circles and erase from vector is off screen
    for(int i = 0; i < circles.size(); i++){
        circles.at(i).update();
        if(circles.at(i).yPos > ofGetHeight()){
            circles.erase(circles.begin()+i);
                  numCircles--;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //draw circles
    for(int i = 0; i < circles.size(); i++){
        circles.at(i).draw();
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //increase object count
    numCircles++;
    //resize vector & create new circle in vector
    circles.resize(numCircles);
    //setup new object passing in x & y position from mouse press
    circles.at(numCircles-1).setup(x, y);
}

