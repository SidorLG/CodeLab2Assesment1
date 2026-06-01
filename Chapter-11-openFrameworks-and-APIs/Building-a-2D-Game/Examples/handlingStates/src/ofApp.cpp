#include "ofApp.h"

void ofApp::setup(){
    //set initial game state to menu
    gameState = 'm';
}

void ofApp::update(){
    if(gameState=='m'){
        //any updates required on menu screen
    }else if(gameState == 'p'){
        //any updates required during play
    }else if(gameState == 'g'){
        //any updates required on game over screen
    }
}



void ofApp::draw(){
    if(gameState=='m'){
        //any drawing required on menu screen
        ofBackground(0, 0, 255);
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("Main Menu", 100, 100);
    }else if(gameState == 'p'){
        //any drawing requied during play
        ofBackground(0, 255, 0);
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("Playing Game", 100, 100);
    }else if(gameState == 'g'){
        //any drawing required on game over screen
        ofBackground(255, 0, 0);
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("Game Over", 100, 100);
    }
}

void ofApp::keyPressed(int key){
      switch(key){//switch to test game states
        case 'm':
            gameState = 'm';
            break;
        case 'p':
            gameState = 'p';
            break;
        case 'g':
            gameState = 'g';
            break;
    }
}
