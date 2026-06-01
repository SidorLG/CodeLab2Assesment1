#pragma once

#include "ofMain.h"
#include "Circle.hpp" //Provide access to our Circle.h in the ofApp.h
#include <vector>

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    //create vector to store our circles
    vector<Circle> circles;
    //used to track circle count, and helps delete correct ones
    int numCircles;
};
