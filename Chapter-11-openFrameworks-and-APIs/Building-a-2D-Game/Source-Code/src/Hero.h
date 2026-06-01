#pragma once
#include "ofMain.h"

class Hero {
private:
	enum directions { NONE, LEFT, RIGHT};//set of possible directions
	directions dir;//variable to store direction
public:
	void setup();
	void update();
	void draw();
	void setDirection(int key, bool pressed);//function to set position
	int xPos, yPos;//store hero positions
};