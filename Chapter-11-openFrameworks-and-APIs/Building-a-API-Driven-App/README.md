# Building an API Driven Application in openFrameworks

* [Getting Started](#getting-started)
* [Setting up the Project](#setting-up-the-project)
* [Using this Section](#using-this-section)
* [App Aims](#app-aims)
* [main.cpp](#maincpp)
* [ofApp.h](#ofApph)
  * [Includes](#includes)
  * [openFrameworks Functions](#openframeworks-functions)
  * [Custom Functions](#custom-functions)
  * [Standard Variables](#standard-variables)
* [ofApp.cpp](#ofappcpp)
  * [setup()](#setup)
  * [getWeatherData()](#getweatherdata)
  * [getData()](#getdata)
  * [getCreature()](#getcreature)
  * [draw()](#draw)
  * [keyPressed()](#keypressed)
  * [mousePressed()](#mousepressed)
  * [wrapstring()](#wrapstring)

&nbsp;
&nbsp;

## Getting Started

This section provides a step by step guide on how to build an application driven by data access from an API. In particular we will be developing an Animal Crossing database which allows the user to find out key information about Bugs, Fish and Fossils available in the New Horizons version of the game.  The material covered here will complement a video tutorial available on Minerva demonstrating how to build the app.

The app makes use of the ANCH API to retrieve data (see: https://github.com/alexislours/ACNHAPI) and uses the openFrameworks addon  ```ofxJSON``` to read in the data. 

*Note since the original writing of this tutorial the full live version of this API is no longer available :(, the key data required to follow this tutorial is now available at: https://acnh-bsu.netlify.app/*


The ofxJSON addon can be downloaded from here:
https://github.com/jeffcrouse/ofxJSON.

This addon should be unzipped then placed in the addons folder of your openFrameworks installation. If you are using the version of openFrameworks downloadable from Minerva this addon will already be installed.

&nbsp;
&nbsp;


## Setting up the Project

* Open the project generator and give the project a name (e.g. WeatherApp).
* Include the ```ofxJson``` addon in the addons box.
* Click ```Generate```
* Click ```open in IDE``` and run the project (if you get a grey window the project has successfully generated
* Locate the assets provide in the resources folder  section of the GitHub repository, this contains the fonts and images used in the project. Copy these files in this folder to the ```bin → data``` folder of your openFrameworks project.
* Clean up the functions in the ```ofApp.h``` and ```ofApp.cpp``` so you just have the following functions left
  * setup();
  * draw();
  * keyPressed();
  * mousePressed();

&nbsp;
&nbsp;

## Using this section

This section should be used in conjunction with the video demo of this app. The code for this project will be written across three files (```main.cpp```, ```ofApp.h```, ```ofApp.cpp```). These should get automatically generated when you setup the project as per the instructions above. When working through this section the code for each file is presented in full, before being broken down to provide further information about what is happening at each step.

Don’t just jump in and copy the code without taking time to read the comments and additional instructions. As you are working through ensure you understand what is happening on each line of code, if you are unsure just ask. Also if you feel confident, feel free to experiment and modify some of the code to make the app your own.

&nbsp;
&nbsp;

## App Aims

The aims for this app are to build a simple Animal crossing database with the following features:

* Allow the user to select between Bugs, Fish & Fossils
* Read data based on user selection
* Present retrieved data to the user
* Allow the user to interact with key presses and mouse clicks

Along the way we will make use of our own functions to improve the efficiency of the program.

&nbsp;
&nbsp;

## main.cpp

The ```main.cpp``` file in an openFrameworks project sets up the app by initialising the graphics window and launching a new instance of the ```ofApp``` class that will contain the code to run our program.

We will make one small modification here to alter the size of the graphics window to 480x854 (*this will be rather small on retina displays, yet there is a reason for this*).

```C++
#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(480,854,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
```

&nbsp;
&nbsp;

## ofApp.h

In C++ we make use of header files to declare the data members (variables) and methods (functions) that characterise our classes. In this program we will just be using one class (the default ```ofApp```) that will hold all the variables and functions to run our program.

In ```ofApp.h``` we want to declare all the variables, objects and functions we will use in our program, we then fully define the implementation of these in the ```.cpp```

```C++
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

```

Let's break down the elements of this header file one by one...

&nbsp;
&nbsp;

### Includes

```C++
#include "ofMain.h" //access to main openframeworks functionality
#include "ofxJson.h" //access to ofxJson addon
#include <vector> //access to string functionality
```

Our includes give us access to different parts of the C++ standard library, the openFrameworks toolkit and addons we wish to use (e.g. ```ofxJson```). We will be using a ```vector``` to store the data received from the API.

&nbsp;
&nbsp;

### OpenFrameworks Functions

```C++
//key Openframeworks functions
void setup();
void draw();
void keyPressed(int key);
void mousePressed(int x, int y, int button);
```

When you generate an openFrameworks project the default ```ofApp``` class comes with some in built functions that handle the main running of the program and enable user interaction. We will be making use of 4 of these as (the others that may be present when generating the project can be removed).


&nbsp;
&nbsp;

### Custom Functions

```C++
//Custom functions
//function which calls the API
void getData();
//function gets creature info
void getCreature();
//function returns a wrapped string to keep text on screen
string wrapString(string text, int width);
```

These user defined functions will be used to handle the key operations that occur multiple times in our App. More detailed information on each is included below...

* ```getData()``` - This function will be used to read in data from the api. This function gets called each time a user interacts with the main menu and will call the relevant API url dependant on the users selection.
* ```getCreature``` - This function updates variables storing information about the currently viewed creature. This function gets called each time the user navigates the view the next or previous creature.
* ```wrapString(string text, int width)``` - openFrameworks does not automatically wrap text to the window size. This function allows us to set a paragraph size for text we wish to display, thus preventing it from going off screen.


&nbsp;
&nbsp;

### Standard Variables

```C++
//Standard Variables
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
```

We will be making use of a number of data types and objects in our program to store and manipulate the information retrieved from the ACNH API. These include standard C++ datatypes and objects available from openFrameworks. A breakdown of these is included below:

* ```vector<string> members``` - This vector will be used to store the string values of all the creatures returned by the API and allow us to easily iterate through each creature returned.
* ```ofRectangle fossilBTN, fishBTN, bugsBTN, nextBTN, prevBTN, homeBTN;``` - These rectangle objects will be used to display buttons to the screen and listen for user clicks.
* ```ofTrueTypeFont headFont, mainFont, subFont;``` - These font objects will be used to draw custom fonts to our user interface. We need multiple objects for different font sizes and styles.
* ```enum class States {MENU, FOSSIL, FISH, BUGS};``` - This enum will be used to determine which state the program is currently in. This will allow us to only draw certain things at certain times.
* ```States state;``` - This is the enum varaible created from the above enum that will handle the program states.
* ```ofImage icon, prevImg, nextImg, homeImg;``` - These image objects are used to display images on our interface, including icons for the retrieved creature and also button images.
* ```int page, size;``` - ints for storing the current page we are on and the total number of creatures returned by current API call.
* ```string name, url, price, rarity, location, availability, desc;``` - set of strings to store information of the current creature ready to be displayed to the interface.

&nbsp;
&nbsp;

## ofApp.cpp

Now we have declared all of the data members (variables & objects) and methods (functions) that our program will use we need to define them. We do this in the class ```.cpp``` file. This file should already have the skeleton definitions for the openFrameworks functions (```setup```, ```update```, ```draw```, ```keyPressed```), but we will need to add code to these as well as adding the definitions for our custom functions. The code required for the ```ofApp``` file is presented per method. Attempting to run the program before all methods have been implemented fully is likely to run into errors. The code for each method is explained below within the description and the code comments.

&nbsp;
&nbsp;

### setup()

```C++
void ofApp::setup(){
    state = States::MENU; //sets initial app state to menu

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
```

The setup function runs once, as soon as the app is launched. The setup function should be used to load in assets (e.g fonts)  as well as initialising variables. Let's break down what is happening in our setup function step by step.

&nbsp;
&nbsp;

```C++
state = States::MENU; //set initial app state to menu
```

This first line of code sets our enum variable to MENU. We do this as we want to ensure the first screen the user sees is the menu screen.

&nbsp;
&nbsp;

```C++
fossilBTN.set(ofGetWidth()/2-100, 200, 200, 50);
fishBTN.set(ofGetWidth()/2-100, 400, 200, 50);
bugsBTN.set(ofGetWidth()/2-100, 600, 200, 50);
homeBTN.set(ofGetWidth()-80, 20, 50, 50);
prevBTN.set(30, ofGetHeight() - 70, 50, 50);
nextBTN.set(ofGetWidth()-80, ofGetHeight() - 70, 50, 50);
```

Here we are setting the coordinates of our rectangle objects that will be used for buttons. The set method accepts the x, y, width and height values of the rectangle.

&nbsp;
&nbsp;

```C++
//load image files
homeImg.load("home.png");
prevImg.load("prev.png");
nextImg.load("next.png");
```

As noted before the setup function is a good place to load in assests, which is what we are doing here. These three lines of code load the relevant image file for each of our image objects.

&nbsp;
&nbsp;

```C++
//load in fonts - ensure the files are in the bin > data folder
mainFont.load("font.otf", 12);
subFont.load("sub.otf", 17);
headFont.load("header.ttf", 22);
```

Similar to loading in the images we need to load the required font files we want to use in the program and set their size. We are using multiple font objects as we want different font styles and sizes

&nbsp;
&nbsp;

```C++
//set second gradient color to white
page = 0;//set current page - used to access array index
ofBackground(236,238,239); //set background colour
```

These final two lines of code set the starting page number and the background colour of the app.

&nbsp;
&nbsp;

### getData()

```C++
void ofApp::getData(){
    page = 0;//reset page variable

    //check current state and open relevant API url
    if(state == States::FOSSIL){
        json.open("https://acnh-bsu.netlify.app/fossils.json");
    }else if(state == States::FISH){
        json.open("https://acnh-bsu.netlify.app/fish.json");
    }else if(state == States::BUGS){
        json.open("https://acnh-bsu.netlify.app/bugs.json");
    }

    members = json.getMemberNames();//store list of creatures into vector (overwrites any existing info).
    getCreature();//call function to get creature information

}
```

The ```getData``` function retrieves data from the API. This is done by using the ```open``` method on the ```ofxJSONElement``` object. This method opens the json file at the specified path. In our case we are requesting the object opens the json file at the url specified. The URL we request depends on the programs state which will get altered when the user interacts (e.g. button clicks). The ```if``` statement is used to check the ```state``` enum and adjust the url accordingly.

After the ```if``` statement we have the following line:
```C++
members = json.getMemberNames();//store list of creatures into vector (overwrites any existing info).
```
The ```getMemberNames()``` returns a list of all the members or data objects in the retrieved json data. The members are returned as a sequential list of strings so we are able to assign these directly to our ```members``` vector.

This function ends by then calling the ```getCreature()``` function.

&nbsp;
&nbsp;

#### Example data

```
{
   "acanthostega" : {
      "file-name" : "acanthostega",
      "image_uri" : "https://acnh-bsu.netlify.app/images/fossils/acanthostega.png",
      "museum-phrase" : "The acanthostega! Said to be one of the earliest amphibians, it existed well before dinosaurs. Because they lived as fish not long before, they still had gills and very webbed \"hands.\". To toss away the life they knew and venture onto unknown lands... they must have been very brave! Hmm... Does it still count as bravery if you have no understanding of what you're doing?",
      "name" : {
         "name-CNzh" : "棘螈",
         "name-EUde" : "Acanthostega",
         "name-EUen" : "acanthostega",
         "name-EUes" : "acantostega",
         "name-EUfr" : "acanthostéga",
         "name-EUit" : "acantostega",
         "name-EUnl" : "acanthostega",
         "name-EUru" : "акантостега",
         "name-JPja" : "アカントステガ",
         "name-KRko" : "아칸토스테가",
         "name-TWzh" : "棘螈",
         "name-USen" : "acanthostega",
         "name-USes" : "acantostega",
         "name-USfr" : "acanthostéga"
      },
      "part-of" : "acanthostega",
      "price" : 2000
   },
   "amber" : {
      "file-name" : "amber",
      "image_uri" : "https://acnh-bsu.netlify.app/images/fossils/amber.png",
      "museum-phrase" : "Amber is formed from the sap of ancient trees that hardened over time. Because of its beauty, it has often been traded and used as jewelry throughout history. However, individual specimens may contain ancient plants or insects trapped inside them! These are valuable resources for learning about ancient eras, such as when the dinosaurs roamed... And this is why they are sometimes displayed in certain...ahem... exceptional museums! Like mine.",
      "name" : {
         "name-CNzh" : "琥珀",
         "name-EUde" : "Bernstein",
         "name-EUen" : "amber",
         "name-EUes" : "ámbar",
         "name-EUfr" : "ambre",
         "name-EUit" : "ambra",
         "name-EUnl" : "barnsteen",
         "name-EUru" : "янтарь",
         "name-JPja" : "コハク",
         "name-KRko" : "호박",
         "name-TWzh" : "琥珀",
         "name-USen" : "amber",
         "name-USes" : "ámbar",
         "name-USfr" : "ambre"
      },
      "part-of" : "amber",
      "price" : 1200
   }
   ...etc etc
}
```

Above is an example of the data returned by the API and shows the first two objects from the fossils API. The API returns a series of objects, which contain the information for each fossil. All information inside the objects are in name and value pairs. When we want to access the data we can retrieve it by refering the the member name, which will return the corresponding value. This is demonstrated in the ```getCreature``` function below.

&nbsp;
&nbsp;

### getCreature()

The ```getCreature()``` function accessess the data retrieved by the API and assigns the available data to  string variables for drawing to the interface. To access the information we specify the name of value we want to access. If the value is nested down the data hierarchy we chain the names sequentialy in subscript operators ```[]```. For example if we wanted to get the name value of the first object in the example data above, we would need the following code:

```C++
json["acanthostega"]["name"]["name-USen"].asString();
```

This code retuns the value stored in ```name-USen``` inside the ```name``` object, which is nested inside the ```acanthostega``` object. The value returned by this code would be ```Acanthostega```

If we wanted the price we could use the following code:

```C++
json["acanthostega"]["price"].asString();
```

Or if we wanted the price in numerical format we could use:

```C++
json["acanthostega"]["price"].asInt();
```

The problem we have with our current program is we do not know the names of the members that will be returned by the API ahead of time, which makes it difficult to set name of the object we wish to access. Furthermore, we want the user to be able to navigate through the returned data and move from object to object. Therefore its no use 'hard-coding' the intial member name as we want the same code to work for every creature.

To solve this problem we can make use of the ```members``` vector which stores all the member names returned by the API (see ```getData()``` function above). These values are stored sequentially in our vector so ```members[0]``` would return *acanthostega* whilst ```members[1]``` would return *amber* based on the example data shown above.

Therefore, rather than hardcoding the initial member name we can set this dynamically using the members vector and setting the index with the ```page``` variable. We use the ```page``` variable as this can be modified. In our program this will be modified when the user interacts to create a paged navigation system through the data returned by the API.

You can see all of this in action in the full ```getCreature()``` function code below. Take note of the comments which further explains the code used in this function. In particular validating the availablity information returned for fish and bug creatures.

```C++
/*
     Note members[page] accesses the members vector which contains a list of creatures
     returned by the API. The page variable is used to set the index of the array we
     want to access. This allows us to easily navigate up and down the vector and
     get the next creature by incrementing the page variable and recalling this function
     We dynamically set this name as we have do not know the names of the creatures the
     API will return ahead of time. It also means we only have to do this once and it
     will run for every creature.
     As an example of what members[page] returns for the first creature from the fossil
     API the value will be "acanthostega"
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
         of fish can be found. However if the creature is available all year, or all day
         the months and time values will be empty. Therefore we run checks first so we
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
    desc = wrapString(json[members[page]]["museum-phrase"].asString(), 400);//set description and wrap the returned string to 400 characters wide.
    name[0] = toupper(name[0]);//set first character of creature name to upper case
    icon.load(url);//load creature image via image url set earlier
}
```
&nbsp;
&nbsp;


### draw()

The draw function is reponsible for all drawing to the screen. Anything we want to include on our interface must be drawn inside this function, or within a function that is called by the this function.

In the draw function you will see ```if``` statements being used to compare the ```state``` variable. This is done to allow us to draw different elements to the screen depending what state the app is in. For example if the app is in the menu state we want to display three buttons to the user allowing them to select which creature they would like to view (Fossil, Fish, Bugs). Then depending which creature has been selected draw slightly different information dependant on what is available from the API.

The draw function is presented in full below. Use the comments to familiarise yourself with what is happening line by line.

```C++
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
     check state and draw creature info on screen
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
        ofDrawLine(10, 370, ofGetWidth()-10, 370);//draw seperating line

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
```
&nbsp;
&nbsp;

### keyPressed()

```C++
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
```

The key pressed function is used to provide keyboard navigation on the creature information pages, hence why the first ```if``` statement checks if we are NOT on the menu state. Nested inside this first ```if``` statement we have further ```if``` statements checking which key has been pressed by comparing the ```key``` parameter passed in by the function. If the left key is pressed and the current page is not the first page (greater than 0) the program will decrease the ```page``` variable and call the ```getCreature()``` function to get the information for the creature stored on the specified page. If the right key is pressed and we are not on the last page (less than the size of the members vector) we do the same but increment the ```page``` variable instead. In effect this function enables the user to move up and down the members vector and get information about each creature returned by the API.

&nbsp;
&nbsp;

### mousePressed()

```C++
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
```

The mouse pressed function performs two jobs dependant on whether we are on the menu screen or not. If we are on the menu screen this function checks whether the mouse is clicked inside the fossil, fish or bugs buttons. If a mouse press is detected in a button the programs state is updated and the ```getData()``` function is called. This then retrieves new data from the API based on what state is selected.

If we are NOT in the menu state (and therefore on one of the creature states) the function listens for mouse presses on the next and previous buttons. The functionality here mirrors the functionality in the ```keyPressed()``` function, allowing the user to alter the ```page``` variable and retrieve the next/previous creatures information.

Additionally when in one of the creature states the function checks for presses on the home button, which if pressed returns the program back to the menu state.

&nbsp;
&nbsp;

### wrapString()

```C++
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
```
Openframeworks does not automatically wrap text to the screen width. This function wraps the specified string to desired width so we can control paragraph sizes. It works by splitting the specified text into a vector of strings and calculates each
line width before returning a new string with either spaces or line breaks added in the appropriate places. This method is introduced by Vanderlin in the openFrameworks forum https://forum.openframeworks.cc/t/text-wrapping/2953 (Vanderlin, 2012).

This function is called within the ```getCreature()``` function to wrap the ```desc``` string variable. This ensures this description text does not go off the screen and is instead nicely formatted in a paragraph.


## Full Code

The full source code for this project can be found [here](./Source-Code)
