//
//  Circle.hpp
//  classObjects
//
//  Created by Jake Hobbs on 13/08/2020.
//

#ifndef Circle_hpp
#define Circle_hpp

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

#endif /* Circle_hpp */
