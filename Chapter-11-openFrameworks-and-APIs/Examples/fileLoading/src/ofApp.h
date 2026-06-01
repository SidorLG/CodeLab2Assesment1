#pragma once

#include "ofMain.h"
#include "Team.h"
#include <fstream>
#include <sstream>
#include <vector>

class ofApp : public ofBaseApp{

	public:
		//function declarations
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void loadData();
		//variables
		ifstream inFile;//file object
		vector<Team> teams;//vector containing team class objects
		int page;//keeps track of vector index
		ofTrueTypeFont title, text;//font objects for text drawing
		stringstream teamInfo;//string stream to store team information
		
};
