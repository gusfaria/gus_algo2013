#pragma once

#include "ofMain.h"
#include "ofxCv.h"
using namespace ofxCv;
using namespace cv;

#include "ofxFaceTracker.h"
#include "Particles.h"


class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	
	ofVideoGrabber cam;
	ofxFaceTracker tracker;
	ofVec2f position;
	float scale;
	ofVec3f orientation;
	ofMatrix4x4 rotationMatrix;
	
	Mat translation, rotation;
	ofMatrix4x4 pose;
	
	ofEasyCam easyCam;
    
    vector<Particles> particleList;
    
    ofVec2f eatterPos;
    float eatterRadius;
    ofVec2f prevMouth;
    float mouth_width;
    float mouth_height;
    
    int score;
    
};


// if(the size of the mouth is small than the previous size of the mouth && the particle is in side the radius (range) ){ the particle disapears }

// make the frog move
// make it as pointers
// toggle facemask
// design
// add shaders