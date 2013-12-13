#pragma once

#include "ofMain.h"
#include "ofxCv.h"
using namespace ofxCv;
using namespace cv;

#include "ofxFaceTracker.h"
#include "ofxBox2d.h"
#include "Particles.h"
class Eyeball {
public:
    ofPoint pos, mousePos;
    float angle;
    
    void draw() {
        ofPushMatrix();{
            ofTranslate( pos );
            ofScale(0.5, 0.5);
            float dx = mousePos.x - pos.x;
            float dy = mousePos.y - pos.y;
            
            angle = atan2( dy , dx );
            
            ofRotate( ofRadToDeg(angle) );
            
            ofSetColor( 0 );
            
            // outline
            ofSetColor(255);
            ofCircle(0, 0, 40);
            
            // pupil
            ofFill();
            ofSetColor(0);
            ofCircle(25, 0, 15);
            
        }ofPopMatrix();
        
    }
};

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void character(float x,float y);
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
    float calories;
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
