#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"
#include "ofxCvHaarFinder.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    ofVideoGrabber 		vidGrabber;
    
    ofImage img;
    ofxCvHaarFinder finder;
};
