#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		
    
        //x and y positions for movement
        float xPos, yPos;
        //speed & velocity
        float speed, velX, velY, friction, maxSpeed;
        //boolean variables to check if key is pressed
        bool uPressed, dPressed, lPressed, rPressed;
		
};
