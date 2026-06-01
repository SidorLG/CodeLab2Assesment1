//
//  Circle.cpp
//  classObjects
//
//  Created by Jake Hobbs on 13/08/2020.
//

#include "Circle.hpp"

void Circle::setup(float x, float y){
    //set x and y position to value passed in
    //value passed in will be set by mouse click
    xPos = x; yPos = y;
    //set random radius between 10 and 50
    radius = ofRandom(10, 50);
}

void Circle::update(){
    //make circle fall
    yPos += 5;
}

void Circle::draw(){
    //draw the circle
    ofDrawCircle(xPos, yPos, radius);
}
