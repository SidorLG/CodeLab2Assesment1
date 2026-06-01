#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	loadData();//calls function that loads data from file
	page = 0;//set page to zero used to access team vector

	//load fonts and set line height on main text font
	title.load("font.ttf", 20);
	text.load("font.ttf", 15);
	text.setLineHeight(30);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);//set colour to white to avoid tints on image
	teams[page].drawBadge(25, 10, 300, 300);//draw current teams page

	int titleX = ofGetWidth() / 2 - title.stringWidth(teams[page].getName()) / 2;//get middle of screen to place team name
	title.drawString(teams[page].getName(), titleX, 350);//draw team name string

	ofSetColor(200);//set colour to grey

	//insert information from team class into stringstream. String stream used as have string and int data
	teamInfo << "Manager: " << teams[page].getManager() << endl;
	teamInfo << "Year Founded: " << teams[page].getYearFounded() << endl;
	teamInfo << "Stadium: " << teams[page].getStadium() << endl;
	teamInfo << "Capacity: " << teams[page].getCapacity() << endl;
	text.drawString(teamInfo.str(), 10, 400);//draw contents of string stream
	teamInfo.str("");//clear contents of string stream
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_LEFT && page != 0) {//listen for left key press if not on first page
		page--;//reduce page number
	}
	else if (key == OF_KEY_RIGHT && page != teams.size() - 1) {//listen for key press if not on last page
		page++;//increase page number
	}
}

void ofApp::loadData() {//function loads in data from file
	inFile.open(ofToDataPath("teams.txt"));//open file store in data folder
	if (inFile.is_open()) {//check file is open
		while (!inFile.eof()) {//keep reading from file until we reach the end
			//temp variables to store information read in from file
			string name, manager, stadium, path;
			int year, capacity;

			getline(inFile, name, ',');//read name from file
			getline(inFile, manager, ',');//read manager from file
			inFile >> year;//read year founded from file
			inFile.ignore(10, ',');//skip the comma character
			getline(inFile, stadium, ',');//read stadium from file
			inFile >> capacity;//read capacity from file
			inFile.ignore(10, ',');//skip the comma character
			getline(inFile, path);//read image file path from file

			Team newTeam(name, manager, stadium, year, capacity, path);//construct new team object and pass data to its members via the constructor
			teams.push_back(newTeam);//push the new team into the vector
		}
		inFile.close();//close the file
	}
}
