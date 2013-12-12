#pragma once

#include "ofMain.h"
#include "ofxCv.h"
using namespace ofxCv;
using namespace cv;

#include "ofxFaceTracker.h"
#include "ofxBox2d.h"
#include "Particles.h"


class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
    void mousePressed(int x, int y, int button);

	
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
    
    ofVec2f myPos;
    ofVec2f trackerPosMapped, trackerPos;
    float fat;
    
    float mouthRadius;
    ofVec2f prevMouth;
    float mouth_width;
    float mouth_height;
    
    
    //game mechanics
    int score;
    int counter;
    int stage;
    
    //debug
    bool bCam;
};
