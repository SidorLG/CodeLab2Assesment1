#pragma once
#include "ofMain.h"

class Item {
private:
	int r, g, b, size;//item variables
public:
	Item();//item constructor
	void update();
	void draw();
	int xPos, yPos, points;//item variables
};