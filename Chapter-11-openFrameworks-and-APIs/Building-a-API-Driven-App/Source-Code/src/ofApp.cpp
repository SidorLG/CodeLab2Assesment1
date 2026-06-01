#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    state = States::MENU; //set initial app state to menu
    
    //set coordinates for button rectangles
    fossilBTN.set(ofGetWidth()/2-100, 200, 200, 50);
    fishBTN.set(ofGetWidth()/2-100, 400, 200, 50);
    bugsBTN.set(ofGetWidth()/2-100, 600, 200, 50);
    homeBTN.set(ofGetWidth()-80, 20, 50, 50);
    prevBTN.set(30, ofGetHeight() - 70, 50, 50);
    nextBTN.set(ofGetWidth()-80, ofGetHeight() - 70, 50, 50);
    
    //load image files
    homeImg.load("home.png");
    prevImg.load("prev.png");
    nextImg.load("next.png");
    
    //load font files
    mainFont.load("font.otf", 12);
    subFont.load("sub.otf", 17);
    headFont.load("header.ttf", 22);
    
    page = 0;//set current page - used to access array index
    ofBackground(236,238,239); //set background colour
}

void ofApp::getData(){
    page = 0;//reset page variable
    
    //check current state and open relevant API url
    if(state == States::FOSSIL){
        json.open("https://acnhapi.com/v1/fossils");
    }else if(state == States::FISH){
        json.open("https://acnhapi.com/v1/fish");
    }else if(state == States::BUGS){
        json.open("https://acnhapi.com/v1/bugs");
    }
    
    members = json.getMemberNames();//store list of creatures into vector (overwrites any existing info).
    getCreature();//call function to get creature information
    
    cout << json.getRawString() << endl;
}
void ofApp::getCreature(){
    /*
     Note members[page] accesses the members vector which contains a list of creatures
     returned by the API. The page variable is used to set the index of the array we
     want to access. This allows us to easily navigate up and down the vector and
     get the next creature by incrementing the page variable and recalling this function
     We dynamically set this name as we have do not know the names of the creatures the
     API will return ahead of time. It also means we only have to do this once and it
     will run for every creature.
     As an example of what members[page] returns for the first creature from the Fish
     API the value will be "bitterling"
     */
    url = json[members[page]]["image_uri"].asString();//set image url
    name = json[members[page]]["name"]["name-EUen"].asString();//set creature name
    price = json[members[page]]["price"].asString();//set creature price
    
    //check if we are handling Fish or Bugs as the available data differs from Fossils
    if(state == States::FISH || state == States::BUGS){
        rarity = json[members[page]]["availability"]["rarity"].asString();//set rarity
        location = json[members[page]]["availability"]["location"].asString();//set location
        
        /*
         For the availability string the aim is to display the months and time the bug
         of fish can be found. However if the creature is available all year or all day
         the months and time values will be empthy. Therefore we run checks first so we
         can correctly format the string we want to display
         */
        availability = "";//reset availability ready to append new info
        //check creature is NOT available all year
        if(json[members[page]]["availability"]["isAllYear"].asBool() == false){
            //if not available all year add months available to availability string
            availability.append("Months ("+json[members[page]]["availability"]["month-southern"].asString()+")");
        }
        //check create is NOT available all day
        if(json[members[page]]["availability"]["isAllDay"].asBool() == false){
            //check create is NOT available all year. If so add seperator between Month and time info
            if(json[members[page]]["availability"]["isAllYear"].asBool() == false){
                availability.append("   |   ");
            }
            //Append hours creature can be found to availability string
            availability.append("Time ("+json[members[page]]["availability"]["time"].asString()+")");
        }
        //if creature is available all year and all day set string to Anytime
        if(json[members[page]]["availability"]["isAllYear"].asBool() == true && json[members[page]]["availability"]["isAllDay"].asBool() == true){
            availability.append("Anytime");
        }
        
    }
    desc = wrapString(json[members[page]]["museum-phrase"].asString(), 400);//set description
    name[0] = toupper(name[0]);//set first character of creature name to upper case
    icon.load(url);//load creature image via image url set earlier
}


//--------------------------------------------------------------
void ofApp::draw(){
    //check state and draw MENU screen
    if(state == States::MENU){
        ofSetColor(50);//set colour to grey
        headFont.drawString("Animal Crossing Library", ofGetWidth()/2-headFont.stringWidth("Animal Crossing Library")/2, 80);//draw title at top middle of screen
        
        ofDrawRectangle(fossilBTN);//draw rectangle based on fossilBTN coordinates
        ofDrawRectangle(fishBTN);//draw rectangle based on fishlBTN coordinates
        ofDrawRectangle(bugsBTN);//draw rectangle based on bugsBTN coordinates
        
        ofSetColor(255);//set colour to white
        
        //Draw button text, position values set to sit over button rectangles
        subFont.drawString("Fossils", ofGetWidth()/2-subFont.stringWidth("Fossils")/2, 230);
        subFont.drawString("Fish", ofGetWidth()/2-subFont.stringWidth("Fish")/2, 430);
        subFont.drawString("Bugs", ofGetWidth()/2-subFont.stringWidth("Bugs")/2, 630);
        
    /*
     check state and draw creature info SCREEN
     Same drawing is used for FOSSIL, FISH & BUGS hence checking if state is NOT menu
     */
    }else if(state != States::MENU){
        ofSetColor(50);//set colour to grey
        headFont.drawString(name, ofGetWidth()/2-headFont.stringWidth(name)/2, 120);//draw creature name to top middle of screen
        ofSetColor(255);//set colour to white (avoids tint on image)
        icon.draw(ofGetWidth()/2-75, 150, 150, 150);//draw image icon to screen
        ofSetColor(50);//set colour to grey
        subFont.drawString("Information", ofGetWidth()/2-subFont.stringWidth("Information")/2, 350);//draw sub header
        ofSetLineWidth(3);//set line width
        ofDrawLine(10, 370, ofGetWidth()-10, 370);//draw seperating line\
        
        mainFont.drawString("Price: "+price, 30, 400);//draw creature price
        
        /*
         Next if statement checks if we state is FISH or BUGS as we have additional
         information to draw to the screen
        */
        if(state == States::FISH || state == States::BUGS){
            mainFont.drawString("Rarity: "+rarity, 30, 430);//draw rarity to screen
            mainFont.drawString("Availability: "+availability, 30, 460);//draw availability to scren
            mainFont.drawString("Location: "+location, 30, 490);//draw location to screen
            mainFont.drawString("Description: \n\n"+desc, 30, 520);//draw description to screen
        }else{//funs is state is not FISH or BUGS (e.g must be FOSSIL)
            mainFont.drawString("Description: \n\n"+desc, 30, 430);//draw description to screen slightly higher as less additional information for fossils
        }
        
        ofSetColor(255);//set colour to white to avoid tint on image
        
        /*
         Note the above images are draw using the rectangles objects, effectively
         drawing the image inside the rectangles. This allows us to use the ofRectangle
         .inside method to check if the mouse has clicked inside them
         */
        homeImg.draw(homeBTN);//draw home icon
        prevImg.draw(prevBTN);//draw prev icon
        nextImg.draw(nextBTN);//draw next icon
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(state!=States::MENU){//if not on menu page
        //if left arrow key pressed and not on first page
        if(key == OF_KEY_LEFT && page > 0){
            page--; //decrease page value
            getCreature();//get new creature info
        }
        //if left arrow key pressed and not on last page
        if(key == OF_KEY_RIGHT && page < members.size()-1){
            page++;//increase page value
            getCreature();//get new creature info
        }
    }
}



//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    /*
     If on menu screen check if mouse x and y is inside buttons
     If mouse is inside button when clicked update state and call API
    */
    if(state==States::MENU){
        if(fossilBTN.inside(x, y)){
            state = States::FOSSIL;//set state to FOSSIL
            getData();//run function which calls API
        }
        if(fishBTN.inside(x, y)){
            state = States::FISH;//set state to FISH
            getData();//run function which calls API
        }
        if(bugsBTN.inside(x, y)){
            state = States::BUGS;//set state to BUGS
            getData();//run function which calls API
        }
    }
    /*
     If not on menu screen check for clicks on prev, next or home buttons
     Perform appropriate actions depending which button is pressed
     */
    if(state!=States::MENU){
        if(prevBTN.inside(x, y) && page > 0){//if prev button clicked and not first page
            page--;//decrease page value
            getCreature();//get new creature info
        }
        if(nextBTN.inside(x, y) && page < members.size()-1){
            page++;//increase page value
            getCreature();//get new creature info
        }
        if(homeBTN.inside(x,y)){
            state = States::MENU;//set state to MENU
        }
    }
    
}

/*
 Openframeworks does not automatically wrap text to the screen width. This function
 wraps the specified string to desirec width so we can control paragraph sizes
 It works by splitting the specified text into a vector of strings and calculates each
 line width before returning a new string with either spaces or line breaks added in
 the appropriate places. This method is introduced by Vanderlin in the openFrameworks
 forum https://forum.openframeworks.cc/t/text-wrapping/2953 (Vanderlin, 2012)
 */
string ofApp::wrapString(string text, int width) {
    string typeWrapped = "";
    string tempString = "";
    vector <string> words = ofSplitString(text, " "); //create vector full of individual words in string passed in

    for(int i=0; i<words.size(); i++) { //run through vector
        string wrd = words[i]; //get current word in vector

        // if we aren't on the first word, add a space
        if (i > 0) {
            tempString += " ";
        }
        tempString += wrd; //add current word to temp string

        int stringwidth = mainFont.stringWidth(tempString); //set string width to length of line

        if(stringwidth >= width) {//check string with to add either space or new line before current word
            typeWrapped += "\n"; //if line is now longer than desired width add a new line
            tempString = wrd; // make sure we're including the extra word on the next line
        } else if (i > 0) {
            typeWrapped += " "; // if we aren't on the first word, add a space
        }
        typeWrapped += wrd; //add current word to string to be returned with new lines for wrapping
    }

    return typeWrapped;

}
