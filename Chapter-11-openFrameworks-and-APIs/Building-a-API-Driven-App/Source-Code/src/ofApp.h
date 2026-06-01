#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include <vector>


class ofApp : public ofBaseApp{

public:
    /*---- FUNCTIONS ---*/
    //openframeworks functions
    void setup();
    void draw();
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    //function which calls the API
    void getData();
    //function gets creature info
    void getCreature();
    //function returns a wrapped string to keep text on screen
    string wrapString(string text, int width);
    
    /*---- VARIABLES / OBJECTS ---*/
    //JSON object stores data returned from API
    ofxJSONElement json;
    //vector stores list of creatures returned from API
    vector<string> members;
    //rectangle objects used for clickable buttons
    ofRectangle fossilBTN, fishBTN, bugsBTN, nextBTN, prevBTN, homeBTN;
    //font objects for drawing text
    ofTrueTypeFont headFont, mainFont, subFont;
    //enum handles the Apps state
    enum class States {MENU, FOSSIL, FISH, BUGS};
    States state;
    //image objects for drawing images to screen
    ofImage icon, prevImg, nextImg, homeImg;
    //int and string variables to store key information
    int page, size;
    string name, url, price, rarity, location, availability, desc;
    
};
