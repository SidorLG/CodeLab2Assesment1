#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		
		bool validKey(int key);//will check if valid key can be added to string

		ofTrueTypeFont myFont;//font object
		ofRectangle textBox;//rectangle object used for text box
		bool textInput;//bool to check if we can caputre text input from user
		string word;//string to store users input
		
};
