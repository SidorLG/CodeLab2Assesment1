# openFrameworks - GUIs & APIs

* [Installing openFrameworks](#installing-openFrameworks)
* [What is openFrameworks](#what-is-openframeworks)
* [openFrameworks Structure](#openFrameworks-structure)
* [Creating an openFrameworks Project](#creating-an-openframeworks-project)
* [Opening Example Projects](#opening-example-projects)
* [openFrameworks Setup](#openframeworks-setup)
* [Key openFrameworks Methods](#key-openframeworks-methods)
* [openFrameworks Useful Events](#openFrameworks-useful-events)
* [Drawing in openFrameworks](#drawing-in-openFrameworks)
* [Drawing Shapes](#drawing-shapes)
* [Loading Media Content](#loading-media-content)
  * [Example Drawing an Image](#example-drawing-an-image)
  * [Example Using Custom Fonts](#example-using-custom-fonts)
* [Dynamically Positioning Text](#dynamically-positioning-text)
* [Preventing Window Resizing](#preventing-window-resizing)
* [Useful openFrameworks Methods](#useful-openframeworks-methods)
* [Exercises](#exercises)
* [Examples: Simple Buttons](#examples-simple-buttons)
* [Examples: Text Wrapping](#examples-text-wrapping)
* [Further Learning](#further-learning)

## Installing openFrameworks

To work with openFrameworks you must first install it onto your computer. You can download openFrameworks using the following links

- [Windows VSCode](https://github.com/openframeworks/openFrameworks/releases/download/0.12.1/of_v0.12.1_msys2_mingw64_release.zip) 
- [Windows Visual Studio](https://github.com/openframeworks/openFrameworks/releases/download/0.12.1/of_v0.12.1_vs_64_release.zip)
- [Mac OSX](https://github.com/openframeworks/openFrameworks/releases/download/0.12.1/of_v0.12.1_osx_release.tar.gz)

You can find setup guides for your particular platform and code editor here: https://openframeworks.cc/download/

On Windows the setup for using VSCode requires additional steps detailed here: https://openframeworks.cc/setup/msys2/

Further guidance is provided on Ultra. If you are unsure, or are struggling to get everything setup please reach out to your module tutor for assistance. 



&nbsp;
&nbsp;

## What is openFrameworks

openFrameworks is an open source creative coding toolkit that provides a simple and intuitive framework for creating graphics based applications. You can build a variety of programs with openFrameworks, from mobile apps through to games or experimental art projects.

openFrameworks comes with many popular C++ libraries preinstalled which provides functionality for graphics, audio, networking and more. There is also a host of community built addons that extend its functionality further.

openFrameworks is one of the only C++ frameworks that offers the ability to create graphical user interfaces that can be built on both Windows, Mac & Linux and programs be deployed to these platforms as well as iOS and Android. This is a key reason why it is used over other frameworks in CodeLab. In addition openFrameworks is flexible and can be used for a variety of creative computing applications including interactive art, software apps and games.

&nbsp;
&nbsp;

## openFrameworks Structure

The openFrameworks install comes with a bunch of different folders. Some of these you might never touch and just contain all the libraries that openFrameworks uses to provide all the functionality it offers. The main folders that you do need to be concerned about are listed below:

* **Root:** This just means the base folder of the installation which everything else is located in. When setting up projects you may need to locate this folder
* **Project Generator:** Contains a small application that makes generating projects easy
* **Apps → myApps:** This is where you should save your projects. If a myApps folder doesn’t exist inside your apps folder create one.
* **Examples:** This contains example projects that demo different functionality. Explore these to learn about what is possible. These examples can be loaded via the project generator.
* **Addons:** You can add additional functionality to openFrameworks. Addons you download should be ‘installed’ in this folder.

&nbsp;
&nbsp;

## Creating an openFrameworks Project

The easiest way to create a new openFrameworks project is with the project generator, which will automatically create an empty project template. This can be found in the projectGenerator folder. Go to this folder and launch the application named projectGenerator that can be found inside.

The first time you launch this application you may be greeted with a screen that says the openFrameworks path is wrong. To fix this issue we need to set the openFrameworks path to the root folder of your openFrameworks installation. This is the folder that contains all the other folders such as addons, libs, apps, projectGenerator etc.

* Click the :mag: icon on the openFrameworks path input box.
* Browse to the root openFrameworks folder
* Click ```open```

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/of-root.png">
</p>

If set correctly the error message should be gone. Now click the ```create/update``` tab at the top of the projectGenerator window. You should now see the following screen. Each time you open the projectGenerator in the future you will be taken to this screen (unless an error occurs again with the path e.g. you move the openFrameworks folder).

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/of-generator.png">
</p>

This screen contains all the options you need to generate a project template. It includes the following options

* **Project Name:** Name for your project, this will default to mySketch or similar. You want to change this to an appropriate name for the project you are creating
* **Project Path:** This is where the project will be saved. By default it will save into the apps/myApps folder in the openFrameworks folder. Usually there is no need to change this.  
* **Addons:** openFrameworks is an open source toolkit and many third party developers have created addons that enhance its functionality. There are also several official addons that come with openFrameworks and are found in the addons folder. These addons cover everything from social networking functionality to augmented reality and machine learning. Many of these addons can be found at: http://ofxaddons.com/categories. One note of warning is that if downloading an addon do check how long ago it was updated as some may be quite a few years old and no longer work with updated versions of openFrameworks.
* **Platforms:** This is the platform which the project template will be built for. You should select the code editor you wish to use (e.g. VS Code, Visual Studio or Xcode).

To create a project give it a name, add any addons you wish to use (leave empty for a simple project with no addons) and click ```Generate```.

Once you have clicked generate the projectGenerator will start creating the files and folders for your project. Depending on whether you included any addons this may take a moment, so be patient. You will know when the project has been generated as you will see a screen similar to the below.

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/of-project-success.png">
</p>

If you are using Xcode or Visual Studio to open the project click ```Open in IDE```

If you are using VS Code, click `Open Folder` then open the `.code-workspace` file.

&nbsp;
&nbsp;

> **Visual Studio Note** - When opening an openFrameworks project you may be presented with a warning about opening projects from trustworthy sources. This is fine, just click to accept. You may also be presented with a popup asking if you would like to retarget the project. You should also accept and retarget the project if asked.

&nbsp;
&nbsp;

## Opening Example Projects

openFrameworks comes with many example projects. These can be useful for learning how certain things are done. The examples are included in the examples folder. Many of the addons also come with examples that can be found inside the folder for the respective addon.

To open one of these example projects you can make use of the projectGenerator which will create the program files needed to open the project on Visual Studio or Xcode.

To open an example project launch the project generator and then click the ```import``` button that is located next to the ```Project name``` input field

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/of-import.png">
</p>

Next browse to the project you wish to open, (e.g. ```examples → graphics → fontsExample```) and click ```open```.

Now click ```update``` and the projectGenerator will build the required files. Once it's ready, you will see the success message. 

If you are using Xcode or Visual Studio to open the project click ```Open in IDE```

If you are using VS Code, click `Open Folder` then open the `.code-workspace` file.

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/of-example.png">
</p>



You can use this same approach to open projects where you just have a bin and src folder containing assets and code but not the project files for your platform (e.g Visual Studio or Xcode files).

&nbsp;
&nbsp;

## openFrameworks Setup

Once a project has been generated you will notice there are three files included in a src folder of the project. These are:

* ```main.cpp``` - Sets up the openGL graphics window and launches the main application class (ofApp)
* ```ofApp.h``` - Header file that sets up main app class (ofApp) and includes all of the method, variable and object declarations required by the program
* ```ofApp.cpp``` - Main class file that includes the method definitions, which outline the tasks required for the app to operate.

Thus, we can see that openFrameworks operates on a class based system, with the core app functionality included in different openFrameworks classes and run through the ofApp class that controls the main functionality of the program.

Within the `ofApp.h` you will notice some methods are already declared with empty definitions included in the `ofApp.cpp`. These are some of the core openFrameworks events that allow you to easily handle certain functionality within your apps.

&nbsp;
&nbsp;

## Key openFrameworks Methods

openFrameworks has three key methods:

* ```setup()``` - Setup gets called once when the program first runs. Typically this is where variables and objects declared in ofApp.h get initialised. It’s also a good place to load in any assets such as image of font files.
* ```update()``` - Update is called in an infinite loop until the program finishes. Update is used to update the state of the application and modify and variables and objects.
* ```draw()``` - Draw is where any drawing to the screen occurs. It also gets called in an infinite loop, immediately after update. Anything you want to draw to the screen must be included here, or called from this method.

&nbsp;
&nbsp;

## openFrameworks Useful Events

There are several other methods that will be present in the ```ofApp.h / ofApp.cpp``` files when you start a project from the project generator. The most useful are the ones related to keyboard and mouse input.

* ```keyPressed(int key)``` - determine which key has been pressed
* ```keyReleased(int key)``` - determine which key has been released
* ```mousePressed(int x, int y, int button)``` - determine what position a mouse click occurred and which button was clicked (e.g. left / right)
* ```mouseReleased(int x, int y, int button)``` - determine what position a mouse release occurred and which button was clicked (e.g. left / right)
* ```mouseMoved(int x, int y)``` - determine where the mouse cursor is as it moves
* ```mouseDragged(int x, int y)``` - determine where the mouse cursor is as it clicks down and moves

&nbsp;
&nbsp;

## Drawing in openFrameworks

As noted above all drawing to the screen should be placed in the draw function. openFrameworks comes with lots of inbuilt methods for drawing things to the screen. All openFrameworks methods are prefixed with ``of``. Some of the main drawing ones are covered here

* ```ofBackground( r, g, b)``` - This method sets the background screen colour. The method accepts r, g and b values as its parameters. For example ofBackground(255, 255, 255) would colour the background white.
* ```ofSetColour(r, g, b)``` - Sets the drawing colour, any objects or text drawn after this will be coloured with the specified colour. This method also accepts r, g, b values as its parameters.
* ```ofDrawBitmapString(“Text to Draw”, x, y)``` - This is the basic inbuilt text drawing method. The method accepts the string you want to draw followed by the x and y values where it should be drawn

#### Example

```C++
void ofApp::draw(){
    ofBackground(255,255,255); //set background to white
    ofSetColor(50, 50, 50); //set colour to grey
    ofDrawBitmapString("oooh look some text on the screen", 10, 30);
    // ^^ draw text to screen near top left ^^
}
```

<p align="center">
  <img width="50%" style="border: 1px solid black;" src="https://jakehobbs.co.uk/markdown_images/of-text.png">
</p>

One important thing to remember about drawing in openFrameworks is that like all our code the commands get executed in order. Therefore, the command that comes last in the draw function will be drawn on the uppermost layer. Also remember the draw function gets called continuously and the screen is redrawn every frame (typically 60 times a second). This means the function loops back round and if you use ```ofSetColor()``` as your last command in the function this will be the colour applied to the first object in the function on the next iteration unless another ```ofSetColor()``` is specified. Thus, if you find yourself in a situation where you think the wrong colours are being applied run through the logic of your statements.

&nbsp;
&nbsp;

## Drawing Shapes

openFrameworks has many different methods for drawing shapes to the screen, from simple 2D shapes through to 3D shapes. As you will notice as you begin working with openFrameworks these are all obviously named.

* ```ofDrawRectangle(x, y, width, height)``` - Draws rectangle / square. Takes `x`, `y`, `width` and `height` as arguments.
* ```ofDrawCircle(x, y, radius)``` - Draws circle. Takes `x`, `y` and `radius` as arguments (remember `radius` is half the diameter, so `50` would result in a circle of `100px`).
* ```ofDrawTriangle(x1, y1, x2, y2, x3, y3)``` - Draws triangle. Takes the `x` and `y` values for the three points of the triangle; `x1`, `y1`, `x2`, `y2`, `x3`, `y3`.
* ```ofDrawLine(x1, y1, x2, y2)``` - Draws a line. Takes the start and end `x` and `y` values for the line; `x1`, `y1`, `x2`, y`2.
* ```ofDrawBox(x, y, z, width, height, depth)``` - Draws 3D box. Takes `x`, `y`, `z` values to position the box, then `width`, `height` and dep`th to size the box.
* ```ofDrawSphere(x, y, radius)``` - Draws 3D sphere. Takes `x`, y` and `radius` values as arguments.

#### Example

```C++
void ofApp::draw(){
    ofFill(); //set fill to be true
    ofSetColor(255, 0, 0); //set colour to red
    ofDrawRectangle(150, 50, 200, 200); //draw square
    ofSetColor(0, 255, 0); //set colour to red
    ofDrawCircle(150, 500, 100); //
    ofSetColor(0, 0, 255); //set colour to blue
    ofDrawTriangle(350, 500, 450, 700, 350, 700);//draw triangle

    ofSetColor(255,255,255); //set colour to white
    ofDrawLine(550, 700, 550, 80); //draw line

    ofSetColor(0,0,0);//set colour to black
    ofNoFill();//set no fill
    ofDrawBox(750, 250, 0, 100, 150, 100); //draw 3d box
    ofDrawSphere(750, 600, 100); //draw 3d sphere
}
```

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/of-shapes.png">
</p>

&nbsp;
&nbsp;

## Loading Media Content

In openFrameworks you can load images, fonts, videos and sounds into your project using the following class types.

* ```ofImage```
* ```ofVideoPlayer```
* ```ofSoundPlayer```
* ```ofTrueTypeFont```

The assets you want to load in to use with these class objects should be saved inside the ```bin → data``` folder located inside your project.

### Example Drawing an Image

*ofApp.h*

```C++
#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    ofImage myCatImg; //declare image object
};
```

You should always declare your objects in the header file of the class you are working in. For this example we just have the core ```ofApp``` class so we declare the image object in the ```ofApp.h``` header file. Declaring the image object is the same as standard variables, specify the type (`ofImage`) then give the object a unique name.


*ofApp.cpp*
```C++
#include "ofApp.h"

//--------------------------------------
void ofApp::setup(){
    myCatImg.load("catimage.jpg");
}

//---------------------------------------
void ofApp::update(){

}

//---------------------------------------
void ofApp::draw(){
    myCatImg.draw(10, 10, 350, 350);
}
```

Once the image has been declared in the header file you can implement it in the `.cpp` file. Typically you would use the ```setup``` method to load in the image. This can be done using the ```load()``` method and passing in the file name of the image as a `string`.

To draw the image you should call ```draw() ```on the image object inside the draw method. For images the ```draw()``` method takes a `x`, `y`, `width` and `height` value.

If you wish to modify the image (e.g. change the `x` and `y` values to move it on screen) typically this would be done inside the update function.

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/of-image-drawing.png">
</p>

&nbsp;
&nbsp;

### Example Using Custom Fonts

*ofApp.h*

```C++
#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    ofTrueTypeFont myFont; //declare font object
};
```

The basic ```ofDrawBitmapString```  in openFrameworks has a basic appearance and lacks customisation options. Therefore, it is useful to load in custom fonts to use for text. This is what the ```ofTrueTypeFont``` object can be used for. To use declare a ```ofTrueTypeFont``` object in the header file (similar to declaring an ofImage object). You can download custom fonts from [https://dafont.com](dafont.com)

*ofApp.cpp*
```C++
#include "ofApp.h"

//--------------------------------------
void ofApp::setup(){
    myFont.load("font.ttf", 25);
}

//---------------------------------------
void ofApp::update(){

}

//---------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0);
    myFont.drawString("CodeLab is Great", 100, 300);
}
```

Once the font has been declared in the header file you can implement the font in the ```.cpp``` file. Typically you would use the ```setup``` function to load in the font. This can be done using the ```load()``` method and passing in the file name of the font as a string, followed by the size you want for the font.

To actually draw the font you should place a drawString call inside the draw function. The ```drawString()``` method takes the `string` you would like to draw followed by `x` and `y` values as arguments.

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/of-custom-font.png">
</p>

&nbsp;
&nbsp;

## Dynamically Positioning Text

In the above example we ‘hard coded’ the text position. However there may be instances where you don’t know the exact values to position the text (e.g. you are designing for multiple screen sizes and want the text to be responsive).

To dynamically position the text instead we can make use of some openFrameworks methods

* ```ofGetWidth()``` - returns width of screen
* ```ofGetHeight()``` - returns height of screen
* ```stringWidth()``` - returns height of specified string
* ```stringHeight()``` - returns width of specified string.

When using ```stringWidth()``` or ```stringHeight()``` the string you want to get the width or height from must be passed in as a argument to the method. If the `string` is quite long it can often be useful to store this `string` in a variable which can be passed to the method instead to improve readability.

Let’s say you want to position text from the bottom right:

To do so you can get the max ```x``` and ```y``` positions using ```ofGetWidth``` and ```ofGetHeight``` and then subtract the ```stringWidth``` and ```stringHeight``` respectively to move the `string` the desired distance away from these values.

Alternatively If you wanted to center text you could divide ```ofGetWidth``` and ```ofGetHeight``` by `2` to get the center point of the screen. Similarly dividing ```stringWidth()``` and ```stringHeight()``` by `2` will get you the center point of the text. Therefore, by subtracting the ```stringWidth``` from ```ofGetWidth``` for the ```drawString``` ```x``` value, and subtracting ```stringHeight``` from ```ofGetHeight``` for the ```drawString``` ```y``` value will center text on the screen.

```C++
//---------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0);
    string text = "The Text You Want To Draw";
    //slightly away from bottom right
    myFont.drawString(text, ofGetWidth() - (myFont.stringWidth(text)+16), ofGetHeight() - myFont.stringHeight(text));
    //centered text
    myFont.drawString(text, ofGetWidth()/2 - myFont.stringWidth(text)/2, ofGetHeight()/2 - myFont.stringHeight(text)/2);
}
```
<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/of-text-positioning.png">
</p>

&nbsp;
&nbsp;

## Preventing Window Resizing

By default the openFrameworks window can be resized by dragging the corners of the window. To prevent this modify the `main.cpp` to the following code (changing the size values to your desired dimensions).

```C++
#include "ofMain.h"
#include "ofApp.h"

//============================================
int main(){
    ofGLFWWindowSettings settings;
    settings.resizable = false;
    settings.setSize(800, 600);
    ofCreateWindow(settings);
    return ofRunApp(new ofApp);
}
```

&nbsp;
&nbsp;

## Useful openFrameworks Methods

The following is a list of useful methods included in the openFrameworks toolkit. This list only scratches the surface, so explore the documentation to discover more.

* ```ofRandom(min, max)``` - returns a random number between values specified
* ```mouseX``` - returns mouse x position
* ```mouseY``` - returns mouse y position
* ```ofDist(x1, y1, x2, y2)``` - calculate the distance between objects
* ```ofToggleFullscreen()``` - switches full screen on/off
* ```ofToUpper(string)``` - converts string to uppercase
* ```ofToLower(string)``` - converts string to lowercase
* ```ofUTF8Append(string, key)``` - adds inputted key value to string when used in keyPressed function

The full documentation for openFrameworks can be found here: https://openframeworks.cc/documentation/

&nbsp;
&nbsp;

## Exercises

### Shape Drawing

Create a project that draws to screen a circle, rectangle, triangle and a square. Each one should be at different positions and be drawn in a different colour.


### Shape Moving

Create a project that draws to a square on the screen. The square should start in the top left and then move in a loop to each corner in order:

```
Top left → Top Right → Bottom Right → Bottom Left
```

### Shape Moving Keyboard

Modify the previous project so the square responds to user input on the arrow keys

### Mouse Click

Create a program that draws a smiley face emoji image onto the screen. When the user clicks the screen the image should change to an unhappy face emoji

&nbsp;
&nbsp;

## Examples: Simple Buttons

By combining an ```ofImage``` object and an object from the openFrameworks ```ofRectangle``` class we can create simple buttons in openFrameworks. The ```ofRectangle``` class is useful here as it has a method called ```.inside()``` which checks to see if the mouse is inside the rectangle. Therefore, we can use this method to see if the user is clicking on our button. We use the ```ofImage``` object so we can add images of our own buttons. The following example takes you through the steps required to create some simple buttons.

&nbsp;
&nbsp;

### Step 1 - ofApp.h

```C++
#pragma once
#include "ofMain.h"
class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);

    ofImage btnImg;
    ofRectangle btn1, btn2;
};
```

To start we need to declare the variables and methods we require in our `ofApp` header file.

We want to keep the core functions: ```setup()```, ```update()```, ```draw()``` plus we’ll use the ```mousePressed()``` method.

We also want to declare an ```ofImage``` object and two ```ofRectangle``` objects, which we’ll use to create the buttons.

&nbsp;
&nbsp;

### Step 2 - ofApp.cpp setup()
```C++
//------------------------------------
void ofApp::setup(){
    //load in button image
    btnImg.load("button.png");

    //set position and size for 2 rectangles
    //values are x, y, width and height
    btn1.set(20, 100, 200, 100);
    btn2.set(250, 100, 50, 50);
}
```

In the ```setup``` method we want to do the initial setup on our image and rectangle objects. This involves loading in the button image we want to use and assumes you have added an image to the ```bin → data``` folder of your project. For the rectangle objects we want to set their positions and size. We do this using the set method and passing in parameters for ```x```, ```y```, ```width``` and ```height```.

&nbsp;
&nbsp;

### Step 3 - ofApp.cpp draw()

```C++
//------------------------------
void ofApp::draw(){
  /* set color to white this ensures no tint is    
  placed on image which is drawn next*/
  ofSetColor(255);

  /* draw first button by drawing btnImg and pass in btn1 rectangle object to set positions and size
  btnImg.draw(btn1);

  //set color to green
  ofSetColor(0,255,0);

  // draw second button using ofDrawRectangle and Pass in btn2 rectangle object for positions and size
  ofDrawRectangle(btn2);
}
```

We will use the ```draw``` method to draw our two buttons to the screen. Each one will demonstrate two ways we can achieve the desired result.

The first button uses an image, so we draw the image by calling the ```draw``` method on the image object, but pass in one of the rectangle objects as the parameter to set the positions.

The second uses basic graphics drawing via ```ofDrawRectangle``` but again passes in a rectangle object to set positions.

We pass in the rectangle objects so we can access the ```.inside()``` method.

&nbsp;
&nbsp;

### Step 4 - ofApp.cpp mousePressed()

```C++
void ofApp::mousePressed(int x, int y, int button){
    //check whether mouse press is inside buttons
    if(btn1.inside(x, y)){
        std::cout << "Clicked button 1" << std::endl;
    }
    if(btn2.inside(x, y)){
        std::cout << "Clicked button 2" << std::endl;
    }
}
```

This is our final step, which is to use the ```mousePressed``` method to check if the user clicks on our buttons. To do this we use an IF statement that includes the ```.inside``` method on each of the rectangle objects in the condition. For the parameters of the ```.inside``` method we pass in the ```x``` and ```y``` values from the mousePressed method to check if the mouse is inside the button.

The result should look similar to the below with console output given if you click on the buttons.

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/of-simple-buttons.png">
</p>

*Note* The full source code for this example is included in the [examples folder](../Chapter-11-openFrameworks-and-APIs/Examples/simpleButtons) of this repository. To run the example copy the folder from the repository into the ```apps/myApps``` folder of your openFrameworks installation and then import the folder via the project generator.

&nbsp;
&nbsp;

## Examples: Text Wrapping

By default openFrameworks will not wrap lines of text when they reach the edge of the screen. This means if you have a long sentence that is wider than your screen width, then the sentence will disappear off the edge.

One way around this is to use a function that splits the specified text into a vector of strings and calculates each line width before returning a new string with either spaces or line breaks added in the appropriate places.  This method is introduced by Vanderlin in the openFrameworks forum https://forum.openframeworks.cc/t/text-wrapping/2953 (Vanderlin, 2012). Example code for this technique is included below.

*ofApp.h*

```C++
#pragma once

#include "ofMain.h"
#include <string>//include string header
#include <vector>//include vector header

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();

        string wrapString(string text, int width); //string wrapping function
        ofTrueTypeFont myFont; //font object
        string text; //string to hold text once wrapped
};
```


*ofApp.cpp*
```C++
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myFont.load("font.ttf",10, true, true); //load font
    myFont.setLineHeight(20.0f); //set line height of font

    string sometext = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.";

    text = wrapString(sometext, 300); //get wrapped text from function
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0,0,0);
    myFont.drawString(text, 100, 210); //draw text to screen
}

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

        int stringwidth = myFont.stringWidth(tempString); //set string width to length of line

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
*Note* The full source code for this example is included in the [examples folder](../Chapter-11-openFrameworks-and-APIs/Examples/textWrapping) of this repository. To run the example copy the folder from the repository into the ```apps/myApps``` folder of your openFrameworks installation and then import the folder via the project generator.

&nbsp;
&nbsp;


## Further Learning

What is covered here provides the basics of getting up and running with openFrameworks. You should use this as a foundation to explore more and make use of the useful links below to extend your knowledge.

&nbsp;
&nbsp;

### Interaction Demos

The examples folder includes source code for a series of interation demos which are covered in a set of video tutorials available on Minerva. These interaction demos include key functionality which will likely be useful for your Data Driven Applications. These demos include:

* [Keyboard and Mouse Interaction](../Chapter-11-openFrameworks-and-APIs/Examples/basicKeyboardMouse): Demo showing how to handling keyboard and mouse interaction
* [File Loading](../Chapter-11-openFrameworks-and-APIs/Examples/fileLoading): Demo showing how to read data from a file into class objects
* [Simple Buttons](../Chapter-11-openFrameworks-and-APIs/Examples/simpleButtons): Demo showing how to create simple buttons [(explained above)](#examples-simple-buttons).
* [Text Wrapping](../Chapter-11-openFrameworks-and-APIs/Examples/textWrapping): Demo showing how to wrap text [(explained above)](#examples-text-wrapping).
* [Text Input](.../Chapter-11-openFrameworks-and-APIs/Examples/textInput): Demo showing how to create a text input field and capture the users input

&nbsp;
&nbsp;

### Official documentation:
* https://openframeworks.cc/documentation/ - Contains information on all functions and classes available in openframeworks
* https://openframeworks.cc/learning/ - Quick reference for common questions
* https://openframeworks.cc/ofBook/chapters/foreword.html - Contains some useful explanations / tutorials on certain features

&nbsp;
&nbsp;

### Additional Projects

Additional example projects are found in the following folders, these are complete with instructions and source code.

* **Building a 2D Game** - Example project for a simple 2D game with openFrameworks
* **Building a Data Driven App** - Example project using the Animal Crossing API to create a database for fossils, fish and bugs.