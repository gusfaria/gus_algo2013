#pragma once

#include "ofMain.h"
#include "ofxCv.h"
using namespace ofxCv;
using namespace cv;

#include "ofxFaceTracker.h"
#include "ofxBox2d.h"
#include "ofxXmlSettings.h"
#include "Particles.h"
#include "Burgers.h"
#include "ofxCenteredTrueTypeFont.h"

class Eyeball {
public:
    ofPoint pos, mousePos;
    float angle;
    
    void draw() {
        ofPushMatrix();{
            ofTranslate( pos );
            ofScale(0.5f,0.5f);
            float dx = mousePos.x - pos.x;
            float dy = mousePos.y - pos.y;
            
            angle = atan2( dy , dx );
            
            ofRotate( ofRadToDeg(angle) );
            
            // outline
            ofSetColor( 255 );
            ofCircle(0, 0, 55);
            
            // pupil
            ofSetColor( 0 );
            ofCircle(25, 0, 20);
        }ofPopMatrix();
    }
    
};


class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    void character(float x,float y);
    void trackerupdate();
    void trackerdraw();

	
	ofVideoGrabber cam;
	ofxFaceTracker tracker;
	ofVec2f position;
	float scale;
	ofVec3f orientation;
	ofMatrix4x4 rotationMatrix;
    
    vector<Particles> particleList;
    vector<Burger> burgerList;
    
    ofVec2f myPos;
    float fat;
    float calories;
    float mouthRadius;
    ofVec2f prevMouth;
    float mouth_width;
    float mouth_height;
    
    //game mechanics
    int score;
    int counter;
    int gamestate;
    string username;
    bool startedNameEntry;
    bool bFirst;
    //debug
    bool bCam;
    float frameRate;
    
    Eyeball leftEye, rightEye;
    ofVec2f eyePos;
    
    ofxCenteredTrueTypeFont font16, font30, font22, fonttitle;
    
    
    ofxXmlSettings highScores;
    void loadXMLData();
    int numberOfSavedScores;
    vector<string> savedNames;
    vector<float> savedScores;
    vector<string> sortedNames;
    vector<float> sortedScores;
    void sortScores();
};
