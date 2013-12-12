#include "testApp.h"

using namespace ofxCv;

//--------------------------------------------------------------
void testApp::setup() {
    
    ofBackground( 251, 146, 64 );
	ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
	ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
    ofSetCircleResolution(60);
    
	cam.initGrabber(320, 240);
	
	tracker.setup();
    mouthRadius = 40;
    
    
    //particle
    for (int i = 0; i < 50; i++){
        Particles p;
        p.pos.set(ofRandomWidth(), ofRandomHeight());
        particleList.push_back(p);
    }

    //tracker movimentation
    fat = 0.01f;
    myPos.set(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
    
    //game mechanics
    stage = 0;
    counter = 0;
    score = 0;
    
    bCam = false;
}

//--------------------------------------------------------------
void testApp::update() {

// GAME MECHANICS
    counter = ofGetElapsedTimef();
    
// TRACKING UPDATE
    cam.update();
	if(cam.isFrameNew()) {
		tracker.update(toCv(cam));
		position = tracker.getPosition();
		scale = tracker.getScale();
		orientation = tracker.getOrientation();
		rotationMatrix = tracker.getRotationMatrix();
	}
    

// PARTICLES BOUNDARIES
    for (int i = 0; i<particleList.size(); i++) {
        particleList[i].update();
        if ( particleList[i].pos.x <= 0 || particleList[i].pos.x >= ofGetWindowWidth() ) {
            particleList[i].vel.x *= -1;
        }
        if ( particleList[i].pos.y <= 0 || particleList[i].pos.y >= ofGetWindowHeight()) {
            particleList[i].vel.y *= -1;
        }
    }
    
// MMOUTH OPENESS
    prevMouth.x = mouth_width;
    prevMouth.y = mouth_height;
    mouth_width = tracker.getGesture(ofxFaceTracker::MOUTH_WIDTH) * 10;
    mouth_height = tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT) * 20;
    
    
// CHARACTER MOVE
    fat = ofMap(score, 0, 50, 0.1, 0.03);
    float catchSpeed = fat;
    cout << fat << endl;
    trackerPos = tracker.getPosition();
    trackerPosMapped.x = ofMap(trackerPos.x, 0, 300, 0, ofGetWindowWidth());
    trackerPosMapped.y = ofMap(trackerPos.y, 0, 200,0, ofGetWindowHeight());
    //ZENO
    myPos.x = catchSpeed * trackerPosMapped.x + (1-catchSpeed) * myPos.x;
    myPos.y = catchSpeed * trackerPosMapped.y + (1-catchSpeed) * myPos.y;
}

//--------------------------------------------------------------
void testApp::draw() {
	ofSetColor(255);
    
	
// TRACKING
    if(bCam){
        ofPushMatrix();{
            ofScale(0.5, 0.5);
            cam.draw(0, 0, 640, 480);
        }ofPopMatrix();
    
        if(tracker.getFound()) {
            ofSetLineWidth(1);
            ofFill();
            tracker.draw();
        }
    }
    
// CHARACTER
    ofPushMatrix();{
        ofSetColor(255, 0, 0);
        ofEllipse(myPos.x, myPos.y, mouth_width*0.5+10, mouth_height+10);
    }ofPopMatrix();
    
// DRAWING PARTICLES
    for (int i = 0; i < particleList.size(); i++) {

// EATTING MECHANICS
        float distance = ofDist(myPos.x, myPos.y, particleList[i].pos.x, particleList[i].pos.y);
        if (distance < mouthRadius && prevMouth.y + 10 < mouth_height) {
            particleList.erase(particleList.begin()+i);
            score ++;
        }
        
        particleList[i].draw();
    }
    
//DEBUGGING
    ofDrawBitmapStringHighlight("Score: "+ofToString(score), ofPoint(10,20));
    ofDrawBitmapStringHighlight("Time: "+ofToString(counter), ofPoint(10,40));
}
//--------------------------------------------------------------

void testApp::keyPressed(int key) {
	if (key == 'r')  tracker.reset();
    if (key == OF_KEY_UP)   score ++;
    if (key == 'c')   bCam = !bCam;
    
    
}
//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){


}

