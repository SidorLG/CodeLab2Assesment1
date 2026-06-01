#include "ofApp.h"

void ofApp::setup(){
    //set initial game time
    seconds = 30;
    //gives us time since app started
    startTime = ofGetElapsedTimef();
}

void ofApp::update(){
    //get time passed on each frame minus the start time
    float tick = ofGetElapsedTimef() - startTime;
    //if a second has passed reset startTime
    if(tick > 1){
        //set start time to time since app started
        startTime = ofGetElapsedTimef();
        //decrease remaining game time
        seconds--;
    }
}

void ofApp::draw(){
    //clear string stream
    gameInfo.str("");
    //insert seconds into string stream
    gameInfo << seconds << " seconds remaining" << endl;
    ofDrawBitmapString(gameInfo.str(), 10, 10);
}
