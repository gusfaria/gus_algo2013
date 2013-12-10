#include "testApp.h"

using namespace ofxCv;

//--------------------------------------------------------------
void testApp::setup() {
    
    
    ofBackground( 255 );
//	ofSetVerticalSync(true);
//    ofSetFrameRate(60);
    ofEnableAlphaBlending();
	ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
    ofSetCircleResolution(60);

    ofSetLogLevel(OF_LOG_NOTICE);
    
    //    box2d
    box2d.init();
	box2d.setGravity(10, 0);
	box2d.setFPS(30.0);
    box2d.enableGrabbing();
    
    //pizza
    for ( int i = 0; i < 30; i ++ ) {
        float r = 30;
		Particle p;
		p.setPhysics(10, 0.1, 0.1);
		p.setup(box2d.getWorld(), ofRandom(ofGetWindowWidth()), ofRandom(50), r);
        p.color.set(250);
//        p.setPosition(ofRandomWidth(), ofRandomHeight());
        
//        ofVec2f veltemp;
//        float neg = (int)ofRandom(2);
//        if (neg == 1)   veltemp.set(ofRandom(-4, -2), ofRandom(-4, -3)) ;
//        else veltemp.set(ofRandom(1, 2), ofRandom(1, 2));
//        p.setVelocity(veltemp);
//        p.setDamping(1.0);
		particles.push_back(p);
    }
//    
//    circle.setPhysics(10, 0.5, 0.5);
//    circle.setup(box2d.getWorld(), 200, 200, 30);
	
	cam.initGrabber(320, 240);
	
	tracker.setup();
    
    eatterPos.x = ofGetWindowWidth()/2;
    eatterPos.y = ofGetWindowHeight()/2;
    eatterRadius = 40;
    
    score = 0;
    
    bCam = false;
}

//--------------------------------------------------------------
void testApp::update() {
    
    

    
    cam.update();
	if(cam.isFrameNew()) {
		tracker.update(toCv(cam));
		position = tracker.getPosition();
		scale = tracker.getScale();
		orientation = tracker.getOrientation();
		rotationMatrix = tracker.getRotationMatrix();
	}
    
    prevMouth.x = mouth_width;
    prevMouth.y = mouth_height;
    
    mouth_width = tracker.getGesture(ofxFaceTracker::MOUTH_WIDTH) * 10;
    mouth_height = tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT) * 20;
    
    float facedireciton = tracker.getOrientation().x;

    ofVec2f myPos;
    ofVec2f trackerPos;
    trackerPos.set(tracker.getPosition());
    
    myPos.x = ofMap(tracker.getPosition().x, 0, 350, 0, ofGetWindowWidth());
    myPos.y = ofMap(tracker.getPosition().y, 0, 250,0, ofGetWindowHeight());
    eatterPos.x = myPos.x;
    eatterPos.y = myPos.y;
    
    
    //PIZZA
//    for( int i=0; i<particles.size(); i++ ){
//        ofVec2f tempVel = particles[i].getVelocity();
//        ofVec2f tempPos = particles[i].getPosition();
//        
//        if (tempPos.x < 0 ) particles[i].setPosition(ofGetWindowWidth(), tempPos.y);
//        if (tempPos.y < 0 ) particles[i].setPosition(tempPos.x, ofGetWindowHeight());
//        if (tempPos.x > ofGetWindowWidth() ) particles[i].setPosition(0, tempPos.y);
//        if (tempPos.y > ofGetWindowHeight() ) particles[i].setPosition(tempPos.x, 0);
//        
//        particles[i].setVelocity( tempVel );
//    }
    
    
    
}

//--------------------------------------------------------------
void testApp::draw() {
//    ofBackgroundGradient(ofColor(233,225,199), ofColor(169,179,172));
	ofSetColor(255,0,0);
	if(bCam == true) cam.draw(0, 0, 640, 480);
    
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
	
	
    if(tracker.getFound()) {
		ofSetLineWidth(1);
        ofFill();
		tracker.draw();
	}

    ofPushMatrix();{
//        ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
        ofSetColor(255, 0, 0);
        ofEllipse(eatterPos.x, eatterPos.y, mouth_width, mouth_height);
        ofSetColor(ofColor::blue,30);
        ofEllipse(eatterPos.x, eatterPos.y, prevMouth.x, prevMouth.y);

    }ofPopMatrix();
    
    ofDrawBitmapStringHighlight("Score: "+ofToString(score), ofPoint(10,20));
    
    
//    circle.draw();
    
    for(int i=0; i<particles.size(); i++) {
        particles[i].draw();
	}
    
    cout << particles.size() << endl;
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
	if(key == 'r') {
		tracker.reset();
	} else if(key == 'c') bCam = !bCam;
}