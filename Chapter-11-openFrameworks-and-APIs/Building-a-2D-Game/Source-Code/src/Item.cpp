#include "Item.h"

Item::Item() {
	yPos = -10;//set inital y
	xPos = ofRandom(10, 1000); //set x to random value across screen
	size = ofRandom(5, 15);//set size
	points = 50 / size;//set points (smaller items worth more)
	r = ofRandom(10, 255);//set r colour value
	g = ofRandom(10, 255);//set g colour value
	b = ofRandom(10, 255);//set b colour value
}
void Item::update() {
	yPos += 5;//add to y value
}

void Item::draw() {
	ofSetColor(r, g, b);//set colour based on rgb variables
	ofDrawCircle(xPos, yPos, size);//draw circle on screen
}