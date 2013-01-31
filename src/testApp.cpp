#include "testApp.h"

void testApp::setup(){
    vidGrabber.setVerbose(false);
    vidGrabber.initGrabber(320,240);
    finder.setup("haarcascade_frontalface_default.xml");
}

void testApp::update(){
    ofBackground(100,100,100);
	vidGrabber.update();
	if (vidGrabber.isFrameNew()){
        img.setFromPixels(vidGrabber.getPixels(),320,240, OF_IMAGE_COLOR,true);
		finder.findHaarObjects(img);
	}
}

void testApp::draw(){
    img.draw(20,20);
	ofNoFill();
	ofSetColor(0xffffff);
    
	for(int i = 0; i < finder.blobs.size(); i++) {
		ofRectangle cur = finder.blobs[i].boundingRect;
		ofRect(cur.x, cur.y, cur.width, cur.height);
	}
    
	char reportStr[1024];
	if(finder.blobs.size()>0)
	{
        sprintf(reportStr, "Faces detected: %i", finder.blobs.size());
        ofDrawBitmapString(reportStr, 20, 280);
    }else{
        sprintf(reportStr, "No faces were detected.");
        ofDrawBitmapString(reportStr, 20, 280);
    }
}
