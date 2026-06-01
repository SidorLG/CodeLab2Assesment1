#include "ofApp.h"

void ofApp::setup(){
    //Set initial x and y position
    xPos = 350; yPos = 350;
    //Set initial speed and velocity variables
    speed = 0.8; velX = 0; velY = 0; friction = 0.93; maxSpeed = 10;
}

void ofApp::update(){

    //UP DOWN
    if(uPressed){
        velY -= speed; //increase velocity by speed
    }else if(dPressed){
        velY += speed; //increase velocity by speed
    }else{
        velY *= friction; //* slow down based on friction
    }
    yPos += velY; //move based on y velocity
    //ensure velocity isn't more than max speed
    if(velY > maxSpeed){
        velY = maxSpeed;
    }else if(velY < -maxSpeed){
        velY = -maxSpeed;
    }

    //LEFT RIGHT
    if(lPressed){
        velX -= speed; //increase velocity by speed
    }else if(rPressed){
        velX += speed; //increase velocity by speed
    }else{
        velX *= friction; //* slow down based on friction
    }
    xPos += velX; //move based on x velocity
    //ensure velocity isn't more than max speed
    if(velX > maxSpeed){
        velX = maxSpeed;
    }else if(velX < -maxSpeed){
        velX = -maxSpeed;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //draw a circle, use xPos and yPos variables to set its position
    ofDrawCircle(xPos, yPos, 40);
}

//--------------------------------------------------------------
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
//--------------------------------------------------------------
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
