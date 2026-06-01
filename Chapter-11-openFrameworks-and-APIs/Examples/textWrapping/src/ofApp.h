#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		string ofApp::wrapString(string text, int width); //wrapString function declaration

		ofTrueTypeFont myFont;//font object
		string text, newText;//string variables
		
};
