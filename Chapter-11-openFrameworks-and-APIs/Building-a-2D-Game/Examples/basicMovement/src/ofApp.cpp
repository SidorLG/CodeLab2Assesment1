#include "ofApp.h"

void ofApp::setup(){
    //Set initial x and y position
    xPos = 350; yPos = 350;
}

void ofApp::update(){
    if(uPressed){
        yPos -= 10;
    }
    if(dPressed){
        yPos += 10;
    }
    if(lPressed){
        xPos -= 10;
    }
    if(rPressed){
        xPos += 10;
    }
}

void ofApp::draw(){
    //draw a circle, use xPos and yPos variables to set its position
    ofDrawCircle(xPos, yPos, 40);
}


void ofApp::keyPressed(int key){
    //switch to check key presses
    //set boolean to true dependant on key pressed
    switch(key){
        case 'w':
        case OF_KEY_UP:
            uPressed = true;
            break;
        case 'a':
        case OF_KEY_LEFT:
            lPressed = true;
            break;
        case 's':
        case OF_KEY_DOWN:
            dPressed = true;
            break;
        case 'd':
        case OF_KEY_RIGHT:
            rPressed = true;
            break;
    }
}

void ofApp::keyReleased(int key){
    //switch to check key presses
    //set boolean to true dependant on key pressed
    switch(key){
        case 'w':
        case OF_KEY_UP:
            uPressed = false;
            break;
        case 'a':
        case OF_KEY_LEFT:
            lPressed = false;
            break;
        case 's':
        case OF_KEY_DOWN:
            dPressed = false;
            break;
        case 'd':
        case OF_KEY_RIGHT:
            rPressed = false;
            break;
    }
}
