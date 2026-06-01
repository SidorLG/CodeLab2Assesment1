#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		float startTime;
        int seconds;
        stringstream gameInfo;
};
