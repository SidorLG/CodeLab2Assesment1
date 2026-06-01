#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	state = MENU; //set state to menu
	playImg.load("playBtn.png");//load image file
	playBtn.set(450, 650, 100, 100); //set play button rectangle positions

	text.load("gameFont.ttf", 16); //load in font
}

//--------------------------------------------------------------
void ofApp::update(){
	if (state == PLAY) {//if we are in play state
		hero.update();//update hero object

		float secondTick = ofGetElapsedTimef() - secondsTimer;//get current tick time
		float itemTick = ofGetElapsedTimef() - itemTimer;//get current tick time
		if (secondTick > 1) {//check if difference between secondTick and secondTimer is 1 second
			seconds--;//decrement seconds
			secondsTimer = ofGetElapsedTimef(); //reset seconds timer
		}
		if (itemTick > 2) {//check if difference between itemTick and itemTime is 2 seconds
			Item newItem;//create new item, as its declare in scope of if statement it will be destroyed at end of if
			items.push_back(newItem);//copy and push item into vector to store it
			itemTimer = ofGetElapsedTimef();//reset tick timer
		}


		for (int i = 0; i < items.size(); i++) {//for loop to run through items vector
			items[i].update();//update current item

			if (items[i].yPos > 780) {//check if item is off screen
				items.erase(items.begin() + i); //remove item from vector
			}

			if (items[i].xPos > hero.xPos&& items[i].xPos < hero.xPos + 50 && items[i].yPos > hero.yPos&& items[i].yPos < hero.yPos + 50) {//if statement to check if item is in bounds of hero
				score += items[i].points;//add to score
				items.erase(items.begin() + i);//remove current item from vector
			}

			
		}
		if (seconds < 0) { //if no seconds left
			items.clear(); //clear the vector of its items
			state = MENU;//set state to menu
		}

	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (state == MENU) {//check if in menu state
		ofBackground(100);//set background to grey
		ofSetColor(255);//colour set to white
		playImg.draw(playBtn);//draw image with rectangle object inside
	}
	else if (state == PLAY) {//check if in play state
		ofBackground(0);//set background to black
		ofSetColor(255);//colour set to white
		gameInfo.str("");//clear string stream
		gameInfo << "Seconds: " << seconds << "    Score: " << score;//insert info to string stream

		text.drawString(gameInfo.str(), 10, 30); //draw string stream info to screen
		text.drawString("Hit M to Exit", 800, 30); //draw text to screen

		hero.draw();//draw hero to screen

		for (int i = 0; i < items.size(); i++) {//for loop to iterate through vector
			items[i].draw();//draw items
		}
	}
	else if (state == GAMEOVER) {//if in game over state
		ofBackground(255, 0, 0);//set background to red
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (state == MENU) {

	}
	else if (state == PLAY) {
		if (key == 'm' || key == 'M') {//if m key is pressed
			items.clear();//clear vector of items
			state = MENU; //set state back to menu
			
		}
		hero.setDirection(key, true);//call setdirection function on hero and pass in key and true for pressed
	}
	else if (state == GAMEOVER) {

	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (state == PLAY) {
		hero.setDirection(key, false); //if key is released set pressed to false
	}
}



//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (state == MENU) {
		if (playBtn.inside(x, y)) {
			//RESET ALL GAME VARIABLES
			state = PLAY;
			seconds = 30;
			score = 0;
			secondsTimer = ofGetElapsedTimef();
			itemTimer = ofGetElapsedTimef();
			hero.setup();
		}
	}
	else if (state == PLAY) {

	}
	else if (state == GAMEOVER) {

	}
}


