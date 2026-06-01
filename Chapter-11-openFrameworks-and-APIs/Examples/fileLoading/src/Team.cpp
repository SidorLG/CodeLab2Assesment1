#include "Team.h"

Team::Team() {//default constructor

}

//parameterised constructor, used to set the class members using the info sent to the parameters
Team::Team(string name, string manager, string stadium, int yearFounded, int capacity, string path) {
	//set each class member with appropriate parameter
	this->name = name;
	this->manager = manager;
	this->stadium = stadium;
	this->yearFounded = yearFounded;
	this->capacity = capacity;
	badge.load(path);//load the club badge using the file path sent in
}

void Team::drawBadge(int x, int y, int w, int h) {//draws badge at position, width height sent to function
	badge.draw(x, y, w, h);
}

//getters return the relevant data members
string Team::getName() {
	return name;
}
string Team::getManager() {
	return manager;
}
string Team::getStadium() {
	return stadium;
}
int Team::getYearFounded() {
	return yearFounded;
}
int Team::getCapacity() {
	return capacity;
}