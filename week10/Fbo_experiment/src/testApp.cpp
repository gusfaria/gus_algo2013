#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    mirrorFbo.allocate( ofGetWidth() / 2 , ofGetHeight() / 2 ) ;
   
    color.setHsb(ofRandom(255), 245, 255);
    
    for (int i = 0; i < 50; i++) {
        Particles p;
        particleList.push_back(p);
//        particleList[i].setParams(ofRandomWidth(), ofRandomHeight(), ofRandom(-1,1),ofRandom(-1,1), color);
        particleList[i].setParams(ofRandomWidth(), ofRandomHeight(), sin(ofGetElapsedTimef() * 4) * 5,ofRandom(-1,1), color);

    }
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].addAttractionForce(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 500, 0.006);
        particleList[i].addRepulsionForce(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 500, 0.001);
        particleList[i].update();
        
        if (particleList[i].pos.x > ofGetWindowWidth() || particleList[i].pos.x <= 0) {
            particleList[i].vel.x *= -0.9;
        }
        
        if (particleList[i].pos.y > ofGetWindowHeight() || particleList[i].pos.y <= 0) {
            particleList[i].vel.y *= -0.9;
        }
    }
    
    mirrorFbo.begin();
        ofClear(0, 0, 0);
    mirrorFbo.end();

}

//--------------------------------------------------------------
void testApp::draw(){
    
    mirrorFbo.begin();{
        ofPushMatrix();{
            ofBackground(0);
            ofColor color;

            for (int i = 0; i < particleList.size(); i++) {
                color.setHsb(ofRandom(255), 255, 250);
                particleList[i].draw();
            }
            ofScale (.5f,.5f, 3);
        }ofPopMatrix();
    }mirrorFbo.end();
    
    
    // FIRST QUADRANT
    ofPushMatrix();{
//        ofTranslate(0, 0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
        ofRotateZ(180);
        ofSetRectMode(OF_RECTMODE_CORNER);
//        ofScale(1, 1, 1);
//        ofSetColor(ofColor::saddleBrown);
        ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
        mirrorFbo.draw(0 , 0) ;
    }ofPopMatrix();
    
    //SECOND QUADRANT
    ofPushMatrix();{
        ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
        ofScale( 1 , -1 , 1 );
//        ofSetColor(ofColor::seaGreen);
        ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
        mirrorFbo.draw( 0 , 0 ) ;
    }ofPopMatrix();

    // THIRD QUADRANT
    ofPushMatrix();{
        ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
        ofScale( -1 , 1 , 1 );
//        ofSetColor(ofColor::sandyBrown);
        ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
        mirrorFbo.draw( 0 , 0 ) ;
    }ofPopMatrix();
    
    // FORTH QUADRANT
    ofPushMatrix();{
        ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
        ofScale( 1 , 1 , -1 );
//        ofSetColor(ofColor::salmon);
        ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
        mirrorFbo.draw( 0 , 0 ) ;
    }ofPopMatrix();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
