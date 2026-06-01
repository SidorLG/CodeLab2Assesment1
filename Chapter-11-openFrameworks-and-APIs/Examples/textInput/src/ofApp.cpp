#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	myFont.load("font.ttf", 20);//loads in font
	textBox.set(20, 20, 300, 50);//set position and size of text box rectangle
	textInput = false; //set text input to false initially
	word = "";//set word to empty on start up
}

//--------------------------------------------------------------
void ofApp::update(){
	if (textInput == false) {//if not capturing text input
		word = "Click to enter text";//set word to provide instruction
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (textInput == false) {//if not capturing text input
		ofSetColor(150);//set colour to grey for text box
	}
	else {
		ofSetColor(255); //set color to white for text box
	}
	ofDrawRectangle(textBox);//draw rectangle using textBox values

	ofSetColor(0);//set colour to black for text
	myFont.drawString(word, 30, 60);//drawing text to the screen
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (textInput == true && validKey(key)) {//if text box is selected and valid key entered
		if ((key == OF_KEY_BACKSPACE || key == OF_KEY_DEL)) {//check if key is delete
			if (word.length() != 0) {//if word has letters
				word.pop_back();//remove letter at end
			}
		}
		else if (key == OF_KEY_RETURN) {//check if key is return
			cout << "The entered word was: " << word << endl;//capture entered word on console
			word = "";//reset word string
			textInput = false;//disable text input
		}
		else {//otherwise accept the key
			if (word.length() < 20) {//check string is less than 20 chars
				ofUTF8Append(word, key);//add key to word string
			}
		}
	}
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (textBox.inside(x, y) && textInput == false) {//checks if textbox is selected
		textInput = true;//enable text input
		word = "";//reset word string
	}
	else {
		textInput = false;//disable text input
	}
}

bool ofApp::validKey(int key) {
	if (key == OF_KEY_ALT || key == OF_KEY_CONTROL || key == OF_KEY_SHIFT || key == OF_KEY_COMMAND || key == OF_KEY_LEFT_SHIFT || key == OF_KEY_RIGHT_SHIFT) {
		return false;
	}
	else {
		return true;
	}
}
