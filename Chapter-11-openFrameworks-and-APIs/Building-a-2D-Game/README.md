# Building a 2D Game in openFrameworks

This section provides a guide for building a simple 2D game in openFrameworks. The material covered here will complement a video tutorial available on minerva demonstrating how to build the game. It starts by providing some code examples for useful features for creating games in openFrameworks, but could also be adapted for your Data Driven App assessments. These techniques are then put together in a simple 2D game.

* [Game Tips](#game-tips)
  * [Creating a Timer](#creating-a-timer)
  * [Creating Game States](#creating-game-states)
  * [Basic Movement](#basic-movement)
  * [Better Movement](#better-movement)
  * [Class of Objects](#class-of-objects)
* [Putting it Together - Simple 2D Game](#putting-it-together---simple-2d-game)
  * [Setting up the Project](#setting-up-the-project)
  * [Project Aims](#project-aims)
  * [Main.cpp](#maincpp)
  * [ofApp.h](#ofapph)
    * [includes](#includes)
    * [openFrameworks Functions](#openframeworks-functions)
    * [Enumeration - States](#enumeration---states)
    * [Game Variables](#game-variables)
    * [Class Objects](#class-objects)
  * [hero.cpp](#herocpp)
    * [setup()](#setup)
    * [update()](#update)
    * [draw()](#draw)
  * [item.h](#itemh)
  * [item.cpp](#itemcpp)
    * [item()](#item)
    * [update()](#update)
    * [draw()](#draw)
  * [ofApp.cpp](#ofappcpp)
    * [setup()](#setup())
    * [update()](#update)
    * [draw()](#draw)
    * [keyPressed()](#keypressed)
  * [Extending the Game](#extending-the-game)

&nbsp;
&nbsp;

## Game Tips

The following examples include useful techniques for building a game in openFrameworks. The full source code for these example is included in the [examples folder](../Building-a-2D-Game/Examples). To run the example copy the folder from the repository into the ```apps/myApps``` folder of your openFrameworks installation and then import the folder via the project generator.

We will adapt these examples later when building a full game. Some of these techniques may also be useful for your Data Driven App assignments. To skip straight to the game instructions click [here](#putting-it-together---simple-2d-game)

&nbsp;
&nbsp;

### Creating a Timer

The following code provides a sample of how you can create a timer in openFrameworks. This could be used to create a countdown similar to the one used in the demo game, or could be modified to perform certain actions at set Intervals, e.g: spawn enemies every 5 seconds.

#### ofApp.h

The following variables should be added to the ```ofApp``` header file.

```C++
float startTime;
int seconds;
stringstream gameInfo;
```

#### ofApp.cpp

Below are the functions required in the ```ofApp``` implementation (```.cpp```) file. Refer to the comments for an overview of how the code functions.

```C++
void ofApp::setup(){
    //set initial game time
    seconds = 30;
    //gives us time since app started
    startTime = ofGetElapsedTimef();
}

void ofApp::update(){
    //get time passed on each frame minus the start time
    float tick = ofGetElapsedTimef() - startTime;
    //if a second has passed reset startTime
    if(tick > 1){
        //set start time to time since app started
        startTime = ofGetElapsedTimef();
        //decrease remaining game time
        seconds--;
    }
}

void ofApp::draw(){
    //clear string stream
    gameInfo.str("");
    //insert seconds into string stream
    gameInfo << seconds << " seconds remaining" << endl;
    ofDrawBitmapString(gameInfo.str(), 10, 10);
}
```

&nbsp;
&nbsp;

### Creating Game States

A simple gameState variable can be extremely useful in separating your main update and draw functions. This enables your update and draw to perform different actions depending on what state the game is in (e.g. Menu, Playing, Game Over). The example below uses a ```char``` data type for the variable, however you could use an ```int```, ```string```, or for improved readability create an ```enum```.

#### ofApp.h

The following variables should be added to the ```ofApp``` header file.

```C++
char gameState;
```

#### ofApp.cpp

Below are the functions required in the ```ofApp``` implementation (```.cpp```) file. Refer to the comments for an overview of how the code functions.

```C++
void ofApp::setup(){
    //set initial game state to menu
    gameState = 'm';
}

void ofApp::update(){
    if(gameState=='m'){
        //any updates required on menu screen
    }else if(gameState == 'p'){
        //any updates required during play
    }else if(gameState == 'g'){
        //any updates required on game over screen
    }
}



void ofApp::draw(){
    if(gameState=='m'){
        //any drawing required on menu screen
        ofBackground(0, 0, 255);
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("Main Menu", 100, 100);
    }else if(gameState == 'p'){
        //any drawing requied during play
        ofBackground(0, 255, 0);
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("Playing Game", 100, 100);
    }else if(gameState == 'g'){
        //any drawing required on game over screen
        ofBackground(255, 0, 0);
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("Game Over", 100, 100);
    }
}

void ofApp::keyPressed(int key){
      switch(key){//switch to test game states
        case 'm':
            gameState = 'm';
            break;
        case 'p':
            gameState = 'p';
            break;
        case 'g':
            gameState = 'g';
            break;
    }
}
```

&nbsp;
&nbsp;

### Basic Movement

With the following code we can create some basic movement on a circle object by modifying ```x``` and ```y``` values when certain keys are pressed. We can get these key presses via the inbuilt openFrameworks ```keyPressed``` function.

#### ofApp.h

The following variables should be added to the ```ofApp``` header file.

```C++
//x and y positions for movement
float xPos, yPos;
//boolean variables to check if key is pressed
bool uPressed, dPressed, lPressed, rPressed;
```

#### ofApp.cpp

Below are the functions required in the ```ofApp``` implementation (```.cpp```) file. Refer to the comments for an overview of how the code functions.

```C++
void ofApp::setup(){
    //Set initial x and y position
    xPos = 350; yPos = 350;
}

void ofApp::update(){
    if(uPressed){
        yPos -= 10;
    }
    if(dPressed){
        yPos += 10;
    }
    if(lPressed){
        xPos -= 10;
    }
    if(rPressed){
        xPos += 10;
    }
}

void ofApp::draw(){
    //draw a circle, use xPos and yPos variables to set its position
    ofDrawCircle(xPos, yPos, 40);
}


void ofApp::keyPressed(int key){
    //switch to check key presses
    //set boolean to true dependant on key pressed
    switch(key){
        case 'w':
        case OF_KEY_UP:
            uPressed = true;
            break;
        case 'a':
        case OF_KEY_LEFT:
            lPressed = true;
            break;
        case 's':
        case OF_KEY_DOWN:
            dPressed = true;
            break;
        case 'd':
        case OF_KEY_RIGHT:
            rPressed = true;
            break;
    }
}

void ofApp::keyReleased(int key){
    //switch to check key presses
    //set boolean to true dependant on key pressed
    switch(key){
        case 'w':
        case OF_KEY_UP:
            uPressed = false;
            break;
        case 'a':
        case OF_KEY_LEFT:
            lPressed = false;
            break;
        case 's':
        case OF_KEY_DOWN:
            dPressed = false;
            break;
        case 'd':
        case OF_KEY_RIGHT:
            rPressed = false;
            break;
    }
}
```

&nbsp;
&nbsp;

### Better Movement

The above movement is perfectly sufficient, but could be enhanced even further. Currently we are always moving at the same speed and stop as soon a key is pressed. To make the movement more realistic we could add speed and velocity.

#### ofApp.h

The following variables should be added to the ```ofApp``` header file.

```C++
//x and y positions for movement
float xPos, yPos;
//speed & velocity
float speed, velX, velY, friction, maxSpeed;
//boolean variables to check if key is pressed
bool uPressed, dPressed, lPressed, rPressed;
```


#### ofApp.cpp

Below are the functions required in the ```ofApp``` implementation (```.cpp```) file. Refer to the comments for an overview of how the code functions.

```C++
void ofApp::setup(){
    //Set initial x and y position
    xPos = 350; yPos = 350;
    //Set initial speed and velocity variables
    speed = 0.8; velX = 0; velY = 0; friction = 0.93; maxSpeed = 10;
}

void ofApp::update(){

    //UP DOWN
    if(uPressed){
        velY -= speed; //increase velocity by speed
    }else if(dPressed){
        velY += speed; //increase velocity by speed
    }else{
        velY *= friction; //* slow down based on friction
    }
    yPos += velY; //move based on y velocity
    //ensure velocity isn't more than max speed
    if(velY > maxSpeed){
        velY = maxSpeed;
    }else if(velY < -maxSpeed){
        velY = -maxSpeed;
    }

    //LEFT RIGHT
    if(lPressed){
        velX -= speed; //increase velocity by speed
    }else if(rPressed){
        velX += speed; //increase velocity by speed
    }else{
        velX *= friction; //* slow down based on friction
    }
    xPos += velX; //move based on x velocity
    //ensure velocity isn't more than max speed
    if(velX > maxSpeed){
        velX = maxSpeed;
    }else if(velX < -maxSpeed){
        velX = -maxSpeed;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //draw a circle, use xPos and yPos variables to set its position
    ofDrawCircle(xPos, yPos, 40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //switch to check key presses
    //set boolean to true dependant on key pressed
    switch(key){
        case 'w':
        case OF_KEY_UP:
            uPressed = true;
            break;
        case 'a':
        case OF_KEY_LEFT:
            lPressed = true;
            break;
        case 's':
        case OF_KEY_DOWN:
            dPressed = true;
            break;
        case 'd':
        case OF_KEY_RIGHT:
            rPressed = true;
            break;
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    //switch to check key presses
    //set boolean to true dependant on key pressed
    switch(key){
        case 'w':
        case OF_KEY_UP:
            uPressed = false;
            break;
        case 'a':
        case OF_KEY_LEFT:
            lPressed = false;
            break;
        case 's':
        case OF_KEY_DOWN:
            dPressed = false;
            break;
        case 'd':
        case OF_KEY_RIGHT:
            rPressed = false;
            break;
    }
}
```

&nbsp;
&nbsp;

### Class of Objects

If we have a game with multiple enemies the best approach of handling this would be via object oriented programming. This means we can create a set of behaviours we would like each enemy to have, rather than rewriting them each time. By creating a class we can make our code much more organised, efficient and reusable.

Below is example code for creating a simple class of circles. In the example a new circle object is instantiated every time the mouse is clicked. To keep the code organised the class is written in separate files (```circle.h``` & ```circle.cpp```). You will then need to include the ```circle.h``` file in your ofApp.h (see line 2 below).

*Note:* If you get an error saying ```Circle.h``` file not found this might be because visual studio will add the file outside of the ```src``` folder where your other code files are located in an openframeworks project. To fix this tweak the include so the file can be found in the folder up: ```#include "../Circle.h"```

#### ofApp.h

```C++
#include "ofMain.h"
#include "Circle.h" //Provide access to our Circle.h in the ofApp.h
#include <vector>

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    //create vector to store our circles
    vector<Circle> circles;
    //used to track circle count, and helps delete correct ones
    int numCircles;
};
```

#### ofApp.cpp




```C++
#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    //Set number of circles to zero
    numCircles = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    //update circles and erase from vector is off screen
    for(int i = 0; i < circles.size(); i++){
        circles.at(i).update();
        if(circles.at(i).yPos > ofGetHeight()){
            circles.erase(circles.begin()+i);
                  numCircles--;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //draw circles
    for(int i = 0; i < circles.size(); i++){
        circles.at(i).draw();
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //increase object count
    numCircles++;
    //resize vector & create new circle in vector
    circles.resize(numCircles);
    //setup new object passing in x & y position from mouse press
    circles.at(numCircles-1).setup(x, y);
}
```

#### Circle.h

```C++
#include "ofMain.h" //include core OF functionality
class Circle{
public:
    //x and y position variable
    float xPos, yPos;
    //radius variable
    int radius;

    //setup with parameter arguments
    void setup(float x, float y);
    void update();
    void draw();
};
```

#### Circle.cpp

```C++
#include "Circle.h"

void Circle::setup(float x, float y){
    //set x and y position to value passed in
    //value passed in will be set by mouse click
    xPos = x; yPos = y;
    //set random radius between 10 and 50
    radius = ofRandom(10, 50);
}

void Circle::update(){
    //make circle fall
    yPos += 5;
}

void Circle::draw(){
    //draw the circle
    ofDrawCircle(xPos, yPos, radius);
}
```

&nbsp;
&nbsp;

## Putting it Together - Simple 2D Game

Using some of the above techniques the remainder of this workbook will offer a guide for making a simple 2D game in openFrameworks. Use this as a basis for a project you could extend further.

&nbsp;
&nbsp;

### Setting up the Project

* Open the project generator
* If asked set the openFrameworks Path to the root folder
* Give the project a name (this will default to something like *“mySketch”*)
* Set the project path the your ```apps → myApps``` folder
* Click ```“Generate”```
* Click ```“Open in IDE”``` (you may need to wait a moment)
* Once the project has been generated add the following additional files to the project. When creating the files ensure they get saved into the ```src``` folder of your project.
  * ```item.h```
  * ```item.cpp```
  * ```hero.h```
  * ```hero.cpp```

&nbsp;
&nbsp;

### Project Aims

The aims of this project are to create a simple 2D where we can control a character at the bottom of the screen and catch items that fall from the top of the screen. We will have a timer that counts down and implement a scoring system for when we catch the times. The project will implement some classes including:

* ```ofApp``` - The standard openFrameworks class to run the program
* ```Hero``` - Class to control our main character
* ```Items``` - Class to control the objects the player will collect.

These classes are visualised below:

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/2dGame-UML.png">
</p>

The remainder of the project will be described  file by file, first presenting the code in full, before breaking this down into smaller steps to provide additional information.

&nbsp;
&nbsp;

### Main.cpp

The ```main.cpp``` file in an openFrameworks project sets up the app by initialising the graphics window and launching a new instance of the ```ofApp``` class that will contain the code to run our program.

```C++
#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    ofSetupOpenGL(1024,768,OF_WINDOW);            // <-------- setup the GL context

    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new ofApp());

}
```

&nbsp;
&nbsp;

### ofApp.h

```C++
#include "ofMain.h"
#include "item.hpp"
#include "hero.hpp"
#include <sstream>
#include <vector>

class ofApp : public ofBaseApp{
public:
    //declare required functions
    void setup(); //runs once when app launches - good place to initialise variables and load in assets
    void update(); //runs every frame (e.g. 60 times a second) - good place to update variables
    void draw();//runs immediately after update, anything we want to draw to the screen must be done here
    void keyPressed(int key); //used to determine which key has been pressed by the user.
    void keyReleased(int key); //used to determine which key has been released by the user.

    enum states { MAIN, PLAY, GAMEOVER};
    states state; //enum to handle states

    int secondsTimer, seconds, itemTimer, score; //main game variables
    stringstream gameInfo; //string stream to hold game information

    vector<Item> items; //vector to store objects from items class
    Hero hero; //object from hero class
};
```
In C++ we make use of header files to declare the data members (variables) and methods (functions) that characterise our classes. In this program our ```ofApp``` class will control the game. In ```ofApp.h``` we want to declare all the variables, objects and functions we will use in our program, we then fully define the implementation of these in ```ofApp.cpp```
Let’s break this code down…

&nbsp;
&nbsp;

#### Includes

```C++
#include "ofMain.h"
#include "item.h"
#include "hero.h"
#include <sstream>
#include <vector>
```

Our includes give us access to different parts of the C++ standard library, the openFrameworks toolkit and the additional classes we will be adding to our program.

&nbsp;
&nbsp;

#### OpenFrameworks Functions

```C++
//key Openframeworks functions
void setup(); //runs once when app launches - good place to initialise variables and load in assets
void update(); //runs every frame (e.g. 60 times a second) - good place to update variables
void draw(); //runs immediately after update, anything we want to draw to the screen must be done here
void keyPressed(int key); //used to determine which key has been pressed by the user.
void keyReleased(int key); //used to determine which key has been released by the user.  
```

When you generate an openFrameworks project the default ofApp class comes with some in built functions that handle the main running of the program and enable user interaction. We will be making use of 5 of these (all others can be removed).

&nbsp;
&nbsp;

#### Enumeration - States

```C++
enum states { MAIN, PLAY, GAMEOVER};
states state; //enum to handle states
```

Enumeration (or ```enum```) is a user defined data type used to assign names to a set of integer values. Enums can make your programs easier to read and maintain as the enum names can give more meaning to what is happening in the program. In this 2D we are going to use an ```enum``` to control the state our game is in and switch between the main screen, play screen and game over screen.

&nbsp;
&nbsp;

#### Game Variables

```C++
int secondsTimer, seconds, itemTimer, score; //main game variables
stringstream gameInfo; //string stream to hold game information
```

We will make use of a few basic ```int``` variables to store information about our game as it is in progress. The timer variables will be used to create timers as described earlier in this workbook. The ```stringstream``` object will then allow us to convert these numeric values into a string so we can draw them to the screen

&nbsp;
&nbsp;

#### Class Objects

```C++
vector<Item> items; //vector to store objects from items class
Hero hero; //object from hero class
```

We will be implementing two additional classes in our game, one for our character which will be implemented in a class called Hero. A second class will be for collectible items, implemented in a class called Items. We will want multiple items on the screen at anyone time and the number will continually grow and shrink, therefore we want to store them in a resizable container (e.g. a ```vector```). We will only have a single hero so we can just instantiate this as a single object from the hero class.

At this stage you will likely have some errors in your project as we have tried adding objects from classes we have not yet declared. Therefore before we begin implementing our ```ofApp``` class any further we will jump to our item and hero classes.

&nbsp;
&nbsp;

### hero.h

```C++
#include "ofMain.h"
class Hero{
public:
    void setup();
    void update();
    void draw();
    int xPos, yPos;
    enum directions {NONE, LEFT, RIGHT};
    directions direction; //enum to set hero direction
};
```

In our ```hero``` header file we want to declare the data members and methods that characterise our hero character. This will be a fairly simple class, the methods we will use will mimic the names of the core openFrameworks methods and will allow us to setup, update and draw our hero (*Note these don’t have to be called setup, update and draw but it makes sense to follow the same pattern that openFrameworks deploys so we know exactly what these methods are doing*).

We then have two simple ```int``` variables to store the hero's position on the screen, plus an ```enum``` object. This ```enum``` will allow us to change the direction the player is moving.

You will also notice we have a single ```include``` at the top of our hero class. This is required when adding your own classes to an openFrameworks project to access core OF functionality.

&nbsp;
&nbsp;

### hero.cpp

```C++
#include "hero.h"
void Hero::setup(){
    xPos = 350; //set starting x
    yPos = 700; //set starting y
}
void Hero::update(){
    if(direction==LEFT){ //if direction left
        xPos-=5; //move left on x axis
    }else if(direction==RIGHT){ //if direction right
        xPos+=5; //more right on x axis
    }
}
void Hero::draw(){
    ofSetColor(255, 255, 255); //set colour to white
    ofDrawRectangle(xPos, yPos, 50, 50); //draw hero
}
```

Now our hero class has been declared we want to implement it in the ```hero.cpp``` file. The implementation needs to include all the definitions of the methods we declared in the header. Let’s break this down. First we include the hero header file (```hero.h```) so we can access the declarations we made. Next we implement the class methods

&nbsp;
&nbsp;

#### setup()

```C++
void Hero::setup(){
    xPos = 350; //set starting x
    yPos = 700; //set starting y
}
```

In the setup method we simply set the starting ```x``` and ```y``` position of our hero. This means every time we restart the game from our ofApp class we can call this method and the hero will start in the middle of the screen.

&nbsp;
&nbsp;

#### update()

```C++
void Hero::update(){
    if(direction==LEFT){ //if direction left
        xPos-=5; //move left on x axis
    }else if(direction==RIGHT){ //if direction right
        xPos+=5; //more right on x axis
    }
}
```

Whilst the game is in progress we want to ensure the hero can move across the screen. The update method will keep track of the direction enum and update the hero’s position variables.

&nbsp;
&nbsp;

#### draw()

```C++
void Hero::draw(){
    ofSetColor(255, 255, 255); //set colour to white
    ofDrawRectangle(xPos, yPos, 50, 50); //draw hero
}
```

To be able to see our hero we need to draw them. The hero will just be a simple square graphic. To do this the draw method sets the hero’s colour as white, then calls the openFrameworks ```ofDrawRectangle``` method and passes in the hero’s ```x``` and ```y``` position and ```width``` and ```height```. We will call this draw method from the main ```ofApp``` draw method when the game is in progress.

&nbsp;
&nbsp;

### item.h

```C++
#include "ofMain.h"

class Item{
public:
    Item(); //item constructor
    void update();
    void draw();

    int xPos, yPos, r, g, b, size, points; //values for each item
};
```

In our ```item``` header file we want to declare the data members and methods that characterise our collectible items. For the purposes of this demo our items will just be some simple circles. Similar to the ```hero``` class the main methods we will use will mimic the names of the core openFrameworks methods and will allow us to update and draw our items. However, instead of using a setup method this time we will demonstrate the use of a class constructor to initialise the item object.

Alongside the method and constructor declarations you will also notice we have a single include at the top of our class to access core OF functionality. Furthermore we have some simple ```int``` variables that will allow use to control our item objects. ```xpos``` and ```ypos``` handle the positions, ```r```, ```g``` and ```b``` will be used to set the colour of the item, whilst ```size``` and ```points``` will do exactly as their name suggests.

&nbsp;
&nbsp;

### item.cpp

```C++
#include "item.h"

Item::Item(){ //item constructor gets called when object is instantiated
    yPos = -10; //start item off screen
    xPos = ofRandom(10, 1000); //start item somewhere on width of screen
    size = ofRandom(5, 15); //give random size
    points = 50/size; //set points based on size
    r = ofRandom(10, 255); g = ofRandom(10, 255); b = ofRandom(10, 255); //set random colour values
}
void Item::update(){
    yPos+=5; //increment y position
}
void Item::draw(){
    ofSetColor(r, g, b); //set item colour
    ofDrawCircle(xPos, yPos, size); //draw item circle
}
```
Now our ```item``` class has been declared we want to implement it in the ```item.cpp``` file. The implementation needs to include all the definitions of the methods we declared in the header. Let’s break this down. First we include the item header file (```item.h```) so we can access the declarations we made. Next we implement the class methods…

&nbsp;
&nbsp;

#### item()

```C++
Item::Item(){ //item constructor gets called when object is instantiated
    yPos = -10; //start item off screen
    xPos = ofRandom(10, 1000); //start item somewhere on width of screen
    size = ofRandom(5, 15); //give random size
    points = 50/size; //set points based on size
    r = ofRandom(10, 255); g = ofRandom(10, 255); b = ofRandom(10, 255); //set random colour values
}
```

First we have the class constructor, this will get called every time an item object is instantiated during the game. In this constructor we set the ```yPos``` so the item will start off screen, then randomise the ```xPos``` so it will start somewhere within the width of the screen. The size of the item is also randomised (note the use of the openFrameworks ```ofRandom()``` method makes getting random numbers easy!!) and influences the number of points an item is worth (smaller ones are worth more).

Finally we also randomise the ```r```, ```g``` and ```b``` variables which will be used to set the colour of the item and mean we will have different coloured items to collect. Note with the use of ```ofRandom``` you can set the min and max values for the random number that is returned. For the ```r```, ```g```, and ```b``` values we limit this to between 10 (don’t start at zero as we don’t want the colour to be black as our background will be black) and 255 (the max of the ```rgb``` range).

&nbsp;
&nbsp;

#### update()

```C++
void Item::update(){
    yPos+=5; //increment y position
}
```

Whilst the game is in progress we want to ensure the items can move down the screen. The update method simply increments the ```yPos``` of the item so it will eventually move off the screen.

&nbsp;
&nbsp;

#### draw()

```C++
void Item::draw(){
    ofSetColor(r, g, b); //set item colour
    ofDrawCircle(xPos, yPos, size); //draw item circle
}
```

As noted above for this demo our items are just going to be basic circles so our draw method is quite simple. We set the colour of the circle using the ```r```, ```g``` and ```b``` values, then draw the circle with the relevant openFrameworks method and pass in the ```xPos```, ```yPos``` and ```size``` values.

&nbsp;
&nbsp;

### ofApp.cpp

Now we have created our ```hero``` and ```item``` classes any errors we had in the ```ofApp``` header file should now be gone and we can go ahead and implement our ```ofApp``` class in the ```ofApp.cpp``` file. The class will control our game so the bulk of our code will reside in this file. Below the full code for this file is presented first. We will then take a look at it step by step.

```C++
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    state = MAIN; //set state to MAIN
}

//--------------------------------------------------------------
void ofApp::update(){
    if(state == PLAY){ //only do this if state is in PLAY
        hero.update(); //call update on hero

        float secondTick = ofGetElapsedTimef() - secondsTimer; //get tick every frame
        if(secondTick > 1){//if 1 second has passed
            seconds--; //decrement seconds variable
            secondsTimer = ofGetElapsedTimef(); //reset seconds timer
        }

        float itemTick = ofGetElapsedTimef() - itemTimer; //get tick every frame
        if(itemTick > 2){ //if 3 seconds have passed
            Item newItem; //instantiate new object from Item class
            items.push_back(newItem); //push item into vector
            itemTimer = ofGetElapsedTimef(); //rest item timer
        }

        for(int i = 0; i < items.size(); i++){ //for loop runs through items vector
            items.at(i).update(); //update each item
            if(items.at(i).xPos > hero.xPos && items.at(i).xPos < hero.xPos+50 && items.at(i).yPos > hero.yPos && items.at(i).yPos < hero.yPos+50){ //check if item is colliding with hero object
                score+=items.at(i).points; //increment score
                items.erase(items.begin()+i); //remove item from vector
            }
            if(items.at(i).yPos > 780){//check if item is off screen
                items.erase(items.begin()+i); //remove item from vector
            }
        }
        if(seconds < 0){ //check if time is up
            items.clear(); //clear vector of objects
            state = MAIN; //set state to MAIN
        }

    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(state == MAIN){ //only draw this if state is MAIN
        ofBackground(68, 78, 81); //set background colour
        ofSetColor(255, 255, 255); //set text colour
        ofDrawBitmapString("Welcome to my Game", 10, 10); //draw title
        ofDrawBitmapString("Hit P to Play", 10, 30); //draw instructions
    }else if(state == PLAY){ //only draw this if state is PLAY
        ofBackground(0, 0, 0); //set background colour
        ofSetColor(255, 255, 255); //set text colour
        ofDrawBitmapString("Playing Game", 10, 10); //draw title
        gameInfo.str(""); //clear info string on each frame
        gameInfo << "Seconds: " << seconds << "     Score: " << score; //insert current time and score into string stream
        ofDrawBitmapString(gameInfo.str(), 140, 10); //draw game info to screen
        ofDrawBitmapString("Hit M to exit", 10, 30); //draw instructions to screen
        for(int i = 0; i < items.size(); i++){ //run through items vector
            items.at(i).draw(); //draw item to screen
        }
        hero.draw(); //draw hero to screen
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(state == MAIN){
        switch(key){ //evaluate which key was pressed
            case 'P':
            case 'p':
                secondsTimer = ofGetElapsedTimef(); //init seconds timer
                itemTimer = ofGetElapsedTimef(); //init item timer
                seconds = 30; score = 0; //set seconds and score to starting values
                hero.setup(); //setup hero
                state = PLAY; //set state to PLAY
                break;
        }
    }
    if(state == PLAY){
        switch(key){ //evaluate which key was pressed
            case 'M':
            case 'm':
                items.clear(); //ensure items vector is cleared
                state = MAIN; //set state to MAIN
                break;
            case OF_KEY_LEFT:
                hero.direction = Hero::LEFT; //set hero direction to left
                break;
            case OF_KEY_RIGHT:
                hero.direction = Hero::RIGHT; //set hero direction to right
            break;
        }
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(state == PLAY){
        switch(key){
            case OF_KEY_RIGHT:
            case OF_KEY_LEFT:
                hero.direction = Hero::NONE; //if keys released set hero direction to none
                break;
        }
    }
}
```

The code kicks of with an include ```#include "ofApp.h"```, this gives us access to the header file with the ofApp class declarations. Next we have the definition of the setup method...

&nbsp;
&nbsp;

#### setup()

```C++
void ofApp::setup(){
    state = MAIN; //set state to MAIN
}
```

The setup method of the main openFrameworks class gets called just once when the program launches. This makes it a good place to initialise variables and load in any assets required by the program. In our case the setup method is very simple and sets our ```state``` ```enum``` to ```MAIN```. This means the program knows we want to display the main screen when we first launch.

&nbsp;
&nbsp;

#### update()

The update method in the main openFrameworks class gets called constantly (60 times per second by default). This makes it the ideal place to do any updating of variables. In our game we want to frequently update our hero character and the items we need to collect, thus this is the method to do that. Let’s break down what is happening in this method....

##### Check enum state

```
if(state == PLAY){ //only do this if state is in PLAY
```

We only require constant updating when our ```enum``` is in the ```PLAY``` state, therefore we use an ```IF``` statement to check whether the ```enum``` is equal to play and include all our update code within this ```IF``` statement.

##### Update Hero

```C++
hero.update(); //call update on hero
```

When we created our hero class we included an ```update``` method that checked the direction it should be moving and updated the hero x position accordingly. We want to run this method whilst the game is in play. So this line of code calls the hero’s update method.

##### Update timers

```C++
float secondTick = ofGetElapsedTimef() - secondsTimer; //get tick every frame
if(secondTick > 1){//if 1 second has passed
    seconds--; //decrement seconds variable
    secondsTimer = ofGetElapsedTimef(); //reset seconds timer
}
```

Earlier in the workbook was an example of how to create timers in openFrameworks. We will be using this technique to create two different timers. The first is a countdown timer to reduce the number of seconds left in the game.

This timer subtracts the time at which the game started (stored in ```secondsTimer```) from the current elapsed time. ```ofGetElapsedTime``` returns the amount of seconds passed since the application launched. As ```secondTick``` is constantly assigned this value, the result of the subtraction will increase on each call of the update method.  Once the result is more than one 1 we know a second has passed so we reduce our seconds variable and reset ```secondsTimer``` to the new current elapsed time.


```C++
float itemTick = ofGetElapsedTimef() - itemTimer; //get tick every frame
if(itemTick > 2){ //if 2 seconds have passed
    Item newItem; //instantiate new object from Item class
    items.push_back(newItem); //push item into vector
    itemTimer = ofGetElapsedTimef(); //rest item timer
}
```

Our second timer is very similar but runs every two seconds (note the change of value in the if statement). We use this timer to instantiate a new ```item``` object into our game every two seconds (```Item newItem```) and push this item into the ```items``` ```vector``` (```items.push_back(newItem)```). At the end of the ```IF``` statement we reset ```itemTimer```.


##### Update each item

```C++
for(int i = 0; i < items.size(); i++){ //for loop runs through items vector
    items.at(i).update(); //update each item
    if(items.at(i).xPos > hero.xPos && items.at(i).xPos < hero.xPos+50 && items.at(i).yPos > hero.yPos && items.at(i).yPos < hero.yPos+50){ //check if item is colliding with hero object
        score+=items.at(i).points; //increment score
        items.erase(items.begin()+i); //remove item from vector
    }else if(items.at(i).yPos > 780){//check if item is off screen
        items.erase(items.begin()+i); //remove item from vector
    }
}
```

The next block of code in our ```update``` method is a for loop that is used to update each of our items. The for loop itself is set to run through all the ```item``` objects that have been pushed into the ```items``` ```vector```. This is done by checking the for loop counting variable (```i```) against the ```vector``` size (```items.size()```)

```C++
items.at(i).update(); //update each item
```

The first thing we do inside the for loop is call the ```update``` method from the ```item``` class on each ```item``` object. This update method moves the items down the screen by updating the ```y``` position.

```C++
if(items.at(i).xPos > hero.xPos && items.at(i).xPos < hero.xPos+50 && items.at(i).yPos > hero.yPos && items.at(i).yPos < hero.yPos+50){ //check if item is colliding with hero object
    score+=items.at(i).points; //increment score
    items.erase(items.begin()+i); //remove item from vector
}
```
Next we have this rather long if statement. This uses the basic collision detection technique described earlier in the workbook (go back for full description). What this does is check whether the item is within the same coordinates as the hero character. If they are then we know they are colliding. If an item is colliding with the hero we want to increase the ```score``` variable based on the ```points``` value of the ```item```, then erase that ```item``` from the ```items``` ```vector```. We do this by calling the ```erase``` method on the ```vector``` and erasing the object that corresponds to the number of items through the ```vector``` we are based on the for loop counter (```i```)

```C++
else if(items.at(i).yPos > 780){//check if item is off screen
    items.erase(items.begin()+i); //remove item from vector
}
```

The final part of this for loop is an ```else if``` that checks each ```item``` position to see if they have gone off the screen. If the ```item``` position exceeds the height of the screen we erase the ```item``` from the ```items``` ```vector``` using the same method as before.


##### Check Timer

```C++
if(seconds < 0){ //check if time is up
   items.clear(); //clear vector of objects
   state = MAIN; //set state to MAIN
}
```

The final part of the update method is to check whether any seconds remain. If the ```seconds``` variable goes below 0 we completely empty the ```items``` ```vector``` by calling the ```clear``` method, then set the  ```enum``` ```state``` back to ```MAIN``` so when we run out of time we go back to the main screen.

&nbsp;
&nbsp;

#### draw()

```C++
void ofApp::draw(){
    if(state == MAIN){ //only draw this if state is MAIN
        ofBackground(68, 78, 81); //set background colour
        ofSetColor(255, 255, 255); //set text colour
        ofDrawBitmapString("Welcome to my Game", 10, 10); //draw title
        ofDrawBitmapString("Hit P to Play", 10, 30); //draw instructions
    }else if(state == PLAY){ //only draw this if state is PLAY
        ofBackground(0, 0, 0); //set background colour
        ofSetColor(255, 255, 255); //set text colour
        ofDrawBitmapString("Playing Game", 10, 10); //draw title
        gameInfo.str(""); //clear info string on each frame
        gameInfo << "Seconds: " << seconds << "     Score: " << score; //insert current time and score into string stream
        ofDrawBitmapString(gameInfo.str(), 140, 10); //draw game info to screen
        ofDrawBitmapString("Hit M to exit", 10, 30); //draw instructions to screen
        for(int i = 0; i < items.size(); i++){ //run through items vector
            items.at(i).draw(); //draw item to screen
        }
        hero.draw(); //draw hero to screen
    }
}
```
The draw method in the main openFrameworks class gets called immediately after update and is used to draw things to the graphics window. Any drawing to the screen must be done from an openFrameworks draw method, or called from the draw method. The ```draw``` method for our game is separated into blocks by an ```IF``` statement that checks which state the game is in based on the ```enum``` value. This is so we can draw different things depending on whether we want the main menu or the play screen. Let’s take a look at each block.

##### Main Menu

```C++
if(state == MAIN){ //only draw this if state is MAIN
    ofBackground(68, 78, 81); //set background colour
    ofSetColor(255, 255, 255); //set text colour
    ofDrawBitmapString("Welcome to my Game", 10, 10); //draw title
    ofDrawBitmapString("Hit P to Play", 10, 30); //draw instructions
}
```

The first ```IF``` block draws our main screen. Here we set the background colour to a dark grey. Next we set the drawing colour to white so the text that follows will be drawn in the colour. We then use the basic bitmap text method ```ofDrawBitmapString``` to include a simple title and instructions message on the screen. The ```ofDrawBitmapString``` method takes the ```string``` you would like to draw and the ```x``` and ```y``` positions as parameters.

##### Play Screen

```C++
else if(state == PLAY){ //only draw this if state is PLAY
    ofBackground(0, 0, 0); //set background colour
    ofSetColor(255, 255, 255); //set text colour
    ofDrawBitmapString("Playing Game", 10, 10); //draw title
    gameInfo.str(""); //clear info string on each frame
    gameInfo << "Seconds: " << seconds << "     Score: " << score; //insert current time and score into string stream
    ofDrawBitmapString(gameInfo.str(), 140, 10); //draw game info to screen
    ofDrawBitmapString("Hit M to exit", 10, 30); //draw instructions to screen
    for(int i = 0; i < items.size(); i++){ //run through items vector
        items.at(i).draw(); //draw item to screen
    }
    hero.draw(); //draw hero to screen
}
```

The second ```IF``` block draws the play screen, let’s break it down...

```C++
ofBackground(0, 0, 0); //set background colour
ofSetColor(255, 255, 255); //set text colour
ofDrawBitmapString("Playing Game", 10, 10); //draw title
```

First we set the background colour to black, then set the draw colour to white for our text. A simple playing game message is then drawn using the ```ofDrawBitmapString``` method.

```C++
gameInfo.str(""); //clear info string on each frame
gameInfo << "Seconds: " << seconds << "     Score: " << score; //insert current time and score into string stream
ofDrawBitmapString(gameInfo.str(), 140, 10); //draw game info to screen
```

Next we make use of the ```stringstream``` object ```gameInfo```. First we clear its current contents so we can insert new values. These new values are inserted on the next line. Remember information can be inserted into a ```stringstream``` just like ```cout```, so we insert message labels alongside the integer values for ```seconds``` and ```score``` into the ```stringstream```. A ```stringstream``` is used here as it can take both string and numeric values.

We can access the entire string value stored in a ```stringstream``` object by calling the ```.str``` method and not pass this any parameters. We use this as the first parameter of a ```ofDrawBitmapString``` call to display the seconds and score info to the screen.

```C++
ofDrawBitmapString("Hit M to exit", 10, 30); //draw instructions to screen
```

After we have drawn our ```stringstream``` text to the screen we draw a simple instructions message underneath it.

```C++
for(int i = 0; i < items.size(); i++){ //run through items vector
        items.at(i).draw(); //draw item to screen
}
hero.draw(); //draw hero to screen
```

The last part of our play screen drawing is to draw our ```items``` and ```hero``` character to the screen. To draw each ```item``` object we use a for loop to run through the ```items``` ```vector``` and call ```draw``` on each ```item``` object. For the ```hero``` we just have one ```hero``` object so can just call the ```draw``` method for this object.


&nbsp;
&nbsp;

#### keyPressed()

```C++
void ofApp::keyPressed(int key){
    if(state == MAIN){
        switch(key){ //evaluate which key was pressed
            case 'P':
            case 'p':
                secondsTimer = ofGetElapsedTimef(); //init seconds timer
                itemTimer = ofGetElapsedTimef(); //init item timer
                seconds = 30; score = 0; //set seconds and score to starting values
                hero.setup(); //setup hero
                state = PLAY; //set state to PLAY
                break;
        }
    }
    if(state == PLAY){
        switch(key){ //evaluate which key was pressed
            case 'M':
            case 'm':
                items.clear(); //ensure items vector is cleared
                state = MAIN; //set state to MAIN
                break;
            case OF_KEY_LEFT:
                hero.direction = Hero::LEFT; //set hero direction to left
                break;
            case OF_KEY_RIGHT:
                hero.direction = Hero::RIGHT; //set hero direction to right
            break;
        }
    }
}
```

The ```keyPressed``` method in the main openFrameworks class is an extremely useful method for determining what keys are being pressed by the user. This can be done by evaluating the value of the ```key``` parameter of the method. Our ```keyPressed``` is separated into blocks by an ```IF``` statement (just like the ```draw``` method) that checks which state the game is in based on the ```enum``` value. Let’s take a look at each ```IF``` block…

##### Main Screen

```C++
if(state == MAIN){
    switch(key){ //evaluate which key was pressed
        case 'P':
        case 'p':
           secondsTimer = ofGetElapsedTimef(); //init seconds timer
           itemTimer = ofGetElapsedTimef(); //init item timer
           seconds = 30; score = 0; //set seconds and score to starting values
           hero.setup(); //setup hero
           state = PLAY; //set state to PLAY
           break;
    }
}
```

The first block listens for key presses on the main screen. When on the main screen we just want to check if the user presses the ```P``` key. We do this using a switch statement that groups together cases for both upper and lower case values. If the user does press ```P``` we want to launch into the game and ensure all game variables and objects are reset. We then switch the ```state``` ```enum``` to ```PLAY```.

##### Play Screen

```C++
if(state == PLAY){
    switch(key){ //evaluate which key was pressed
        case 'M':
        case 'm':
            items.clear(); //ensure items vector is cleared
            state = MAIN; //set state to MAIN
            break;
        case OF_KEY_LEFT:
            hero.direction = Hero::LEFT; //set hero direction to left
            break;
        case OF_KEY_RIGHT:
            hero.direction = Hero::RIGHT; //set hero direction to right
        break;
    }
}
```

Our next block handles key presses for the play screen. First we check if the user has pressed the ```M``` key by grouping the lower and upper case values for this key together. If they have pressed ```M``` it means they want to switch back to the main screen so we clear the ```items``` ```vector``` of any ```item``` objects that might have been added then switch the ```enum``` back to ```MAIN```.

Next we want to check the arrow keys. openFrameworks has some built in ```enum``` name values for many of the keyboard keys including the arrow keys which are represented by ```OF_KEY_LEFT``` and ```OF_KEY_RIGHT``` (I’ll leave it to you to guess what up and down might be). If either of these keys are pressed we want to move the ```hero``` character accordingly. We do this my setting the ```direction``` ```enum``` inside the ```hero``` class to ```LEFT``` or ```RIGHT``` respectively. Note that when setting the value we need to scope to the ```hero``` class (Hero::) as this is where ```LEFT``` and ```RIGHT``` are declared, otherwise the compiler will look for the ```LEFT``` and ```RIGHT``` values in the ```ofApp``` class.

&nbsp;
&nbsp;

#### keyReleased()

```C++
void ofApp::keyReleased(int key){
    if(state == PLAY){
        switch(key){
           case OF_KEY_RIGHT:
           case OF_KEY_LEFT:
               hero.direction = Hero::NONE; //if keys released set hero direction to none
               break;
        }
    }
}
```

The ```keyReleased``` method in the main openFrameworks class does the opposite to ```keyPressed``` and checks which keys are being released by the user. This can be done by evaluating the value of the ```key``` parameter of the method. We only want to check ```keyReleased``` during the play state so we use an ```IF``` statement to determine this. Inside the ```IF``` statement we use a ```switch``` to evaluate the key being released. If either the left or right arrow keys are released we want to reset the ```hero``` ```direction``` ```enum``` back to none. This is done so that the hero will stop moving if no key is pressed.

## Extending the Game

That’s it, we're done. You should now have a very simple 2D game created in openFrameworks. However, this game could be made much better. Use your coding skill and creativity to take this game forward. Here are some suggestions

* Use custom fonts instead of the bitmap text
* Use custom graphics rather than simple shapes for the hero character and items
* Implement a gameover screen that the game goes to at the end rather than just switching back to the main menu
* Add a background image
* Add sounds
* Add different collectible items
* Add a score rating system
* Plus any other elements you can think of to enhance this simple game...

*The full source code can be found in the Source Code folder*
