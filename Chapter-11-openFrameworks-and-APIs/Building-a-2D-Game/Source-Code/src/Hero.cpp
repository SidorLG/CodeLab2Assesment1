#include "Hero.h"

void Hero::setup() {
	xPos = 350;//initial xpos
	yPos = 700;//initial ypos
}

void Hero::update() {
	if (dir == LEFT) {//if direction left
		xPos -= 5;//move back along x
	}
	else if (dir == RIGHT) {//if direction right
		xPos += 5;//move along x
	}
}

void Hero::draw() {
	ofSetColor(255);//set colour white
	ofDrawRectangle(xPos, yPos, 50, 50); //draw rectangle
}

void Hero::setDirection(int key, bool pressed) { //determines which key has been pressed or released
	if (pressed == true) { //if key is pressed
		switch (key) {//check which key is pressed and set direction accordingly
			case OF_KEY_LEFT:
				dir = LEFT;
				break;
			case OF_KEY_RIGHT:
				dir = RIGHT;
				break;
			default:
				dir = NONE;
		}
	}
	else {//if key not pressed set direction to none
		dir = NONE;
	}
}