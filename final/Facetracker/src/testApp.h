#pragma once

#include "ofMain.h"
#include "ofxCv.h"
using namespace ofxCv;
using namespace cv;

#include "ofxFaceTracker.h"
#include "ofxBox2d.h"
#include "Particles.h"


class Particle : public ofxBox2dCircle {
public:
    Particle() {
        pizza.loadImage("pizza.png");
    }
    
    
    ofColor color;
    ofImage pizza;
    
	void draw() {
		float radius = 30;
        float rotation = getRotation();
		ofPushMatrix();{
            ofTranslate(getPosition().x, getPosition().y, 0);
            ofRotate(rotation);
            
            ofSetColor(color);
            ofFill();
            pizza.draw(0,0, radius);
            ofPushStyle();
            ofTranslate(30,15);
            ofSetColor(255, 0, 0);
            ofCircle(0, 0, 30);
            ofPopStyle();
		}ofPopMatrix();
		
	}
};




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
    
    ofVec2f eatterPos;
    float eatterRadius;
    ofVec2f prevMouth;
    float mouth_width;
    float mouth_height;
    
    bool bCam;
    int score;
    
    //box2d
    ofxBox2d						box2d;
	vector		<ofxBox2dCircle>	circles;
	vector		<ofxBox2dRect>		boxes;
	vector		<Particle>      particles;

    ofxBox2dCircle circle;
    
    
};
