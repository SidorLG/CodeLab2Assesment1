#pragma once

#include "ofMain.h"

class Team {
	//encapsulated team data
	string name;
	string manager;
	string stadium;
	int yearFounded;
	int capacity;
	ofImage badge;
public:
	Team();//constructor
	Team(string name, string manager, string stadium, int yearFounded, int capacity, string path);//parameterised constructor
	void drawBadge(int x, int y, int w, int h);//draws the badge

	//getters
	string getName();
	string getManager();
	string getStadium();
	int getYearFounded();
	int getCapacity();


};