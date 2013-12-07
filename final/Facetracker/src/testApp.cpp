#include "testApp.h"

using namespace ofxCv;

void testApp::setup() {
    ofBackground( 0 );
	ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
	ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
	
	cam.initGrabber(320, 240);
	
	tracker.setup();
    
    for (int i = 0 ; i < 400; i++) {
        Particles p;
        p.pos.x = ofRandomWidth();
        p.pos.y = ofRandomHeight();
        particleList.push_back( p );
        particleList[i].addAttractionForce(ofRandomWidth(), ofRandomHeight(), 1000, 0.5);
        particleList[i].addRepulsionForce(ofRandomWidth(), ofRandomHeight(), 100, 0.2);
    }
    
    eatterPos.x = ofGetWindowWidth()/2;
    eatterPos.y = ofGetWindowHeight()/2;
    eatterRadius = 40;
    
    score = 0;
}

void testApp::update() {
	cam.update();
	if(cam.isFrameNew()) {
		tracker.update(toCv(cam));
		position = tracker.getPosition();
		scale = tracker.getScale();
		orientation = tracker.getOrientation();
		rotationMatrix = tracker.getRotationMatrix();
	}
    


    for (auto &p : particleList) {
//    for (int i = 0; i<particleList.size(); i++) {
//        particleList[i].addAttractionForce(mouseX, mouseY, 1000, 0.1);
//        particleList[i].addRepulsionForce(mouseX, mouseY, 100, 0.5);
//        particleList[i].update();
        p.addAttractionForce(ofRandomWidth(), ofRandomHeight(), 1000, 0.9);
        p.addRepulsionForce(mouseX, mouseY, 100, 0.5);
        p.update();
        
        if ( p.pos.x > 0 || p.pos.x < ofGetWindowWidth() ) {
            p.vel.x * -1;
        }
        
        if ( p.pos.y > 0 || p.pos.y < ofGetWindowHeight()) {
            p.vel.y * -1;
        }
        
    }
    
    prevMouth.x = mouth_width;
    prevMouth.y = mouth_height;
    
    mouth_width = tracker.getGesture(ofxFaceTracker::MOUTH_WIDTH) * 10;
    mouth_height = tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT) * 20;
    
    float facedireciton = tracker.getOrientation().x;
    
//    if (facedireciton >= 0.2f) {
//        eatterPos.x ++;
//    } else if(facedireciton <= -0.1f){
//        eatterPos.x --;
//    }

    cout << "get orientation:: " << tracker.getOrientation().x << endl;
    
}

void testApp::draw() {
	ofSetColor(255);
//	cam.draw(0, 0);
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
	
	
    if(tracker.getFound()) {
		ofSetLineWidth(1);
        ofFill();
		tracker.draw();
        
		//easyCam.begin();
//		ofSetupScreenOrtho(640, 480, OF_ORIENTATION_UNKNOWN, true, -1000, 1000);
//		ofTranslate(640 / 2, 480 / 2);
//		applyMatrix(rotationMatrix);
//		ofScale(5,5,5);
//		ofDrawAxis(scale);
//		tracker.getObjectMesh().drawWireframe();
		//easyCam.end();
	}

    ofPushMatrix();{
//        ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
        ofSetColor(255, 0, 0);
        ofEllipse(eatterPos.x, eatterPos.y, mouth_width, mouth_height);
        ofSetColor(ofColor::blue,30);
        ofEllipse(eatterPos.x, eatterPos.y, prevMouth.x, prevMouth.y);

    }ofPopMatrix();
    for (int i = 0; i < particleList.size(); i++) {
        float distance = ofDist(eatterPos.x, eatterPos.y, particleList[i].pos.x, particleList[i].pos.y);
        if (distance < eatterRadius && prevMouth.y + 10 < mouth_height) {
            ofSetColor(ofColor::lime);
            particleList.erase(particleList.begin()+i);
            score ++;

        } else {
            ofSetColor(ofColor::magenta);
        }
        particleList[i].draw();
    }
    
    ofDrawBitmapStringHighlight("Score: "+ofToString(score), ofPoint(10,20));

    
    
}

void testApp::keyPressed(int key) {
	if(key == 'r') {
		tracker.reset();
	}
}