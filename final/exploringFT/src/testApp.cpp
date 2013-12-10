#include "testApp.h"

using namespace ofxCv;

void testApp::setup() {
	ofSetVerticalSync(true);
	ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
	cam.initGrabber(640, 480);
	
	tracker.setup();
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
    
    catchUpSpeed = 0.03f;

}

void testApp::draw() {
	ofSetColor(255);
	cam.draw(0, 0, 640, 480);
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
	   
	if(tracker.getFound()) {
        ofVec2f trackerPos;
        trackerPos.set(tracker.getPosition());
        ofVec2f myPos;
        ofVec2f mappedpos;
        

        mappedpos.x = ofMap(trackerPos.x, 0, 640, 0, ofGetWindowWidth());
        mappedpos.y = ofMap(trackerPos.y, 0, 480, 0, ofGetWindowHeight());
        
        myPos.x = catchUpSpeed * mappedpos.x + (1-catchUpSpeed) * myPos.x;
        myPos.y = catchUpSpeed * mappedpos.y + (1-catchUpSpeed) * myPos.y;
        
        ofPushMatrix();
            ofTranslate(myPos.x, myPos.y+40);
    //        applyMatrix(rotationMatrix);
            ofFill();
            ofSetColor(255, 0, 0);
            float mouthW = tracker.getGesture(ofxFaceTracker::MOUTH_WIDTH)*4;
            float mouthH = tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT)*6;
            ofEllipse(0, 0, mouthW, mouthH);
        ofPopMatrix();
        
        
        
        ofSetColor(255);
        ofSetLineWidth(1);
        tracker.draw();
        
//		ofSetupScreenOrtho(640, 480, OF_ORIENTATION_UNKNOWN, true, -1000, 1000);
//		ofTranslate(640 / 2, 480 / 2);
//		applyMatrix(rotationMatrix);
//		ofScale(5,5,5);
//		ofDrawAxis(scale);
//		tracker.getObjectMesh().drawWireframe();

	}
}

void testApp::keyPressed(int key) {
	if(key == 'r') {
		tracker.reset();
	} else if (key== 't') ofToggleFullscreen();
    
    
}