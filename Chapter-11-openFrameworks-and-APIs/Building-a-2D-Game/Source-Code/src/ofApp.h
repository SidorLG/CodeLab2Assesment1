#pragma once

#include "ofMain.h"
#include "Hero.h"
#include "Item.h"
#include <sstream>
#include <vector>

class ofApp : public ofBaseApp{
private:
	enum states { MENU, PLAY, GAMEOVER };//possible states of game
	states state;//enum variable to control states

	ofImage playImg; //image for play button
	ofRectangle playBtn; //rectange for button

	int secondsTimer, seconds, itemTimer, score; //main game variables
	stringstream gameInfo;//string stream to store score and seconds

	ofTrueTypeFont text; //font object

	Hero hero; //player object

	vector<Item> items;//vector to store items

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		
		void mousePressed(int x, int y, int button);
		
		
};
