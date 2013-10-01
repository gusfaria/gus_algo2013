#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    
    
    for (int i = 0; i < 5; i++){
        addParticle();
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < particleList.size(); i++){
        particleList[i].resetForces();
        particleList[i].addForce(ofVec2f( sin(ofGetElapsedTimef()*3)*0.02, -0.1 ));
        particleList[i].addDampingForce();
        particleList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    ofSetColor(255);
    for (int i=0; i < particleList.size(); i++){
        particleList[i].draw();
    }
    
    ofDrawBitmapStringHighlight(ofToString(particleList.size()), 10,10);
}

//--------------------------------------------------------------
void testApp:: addParticle(){
    Particle myParticle;
    
//    float vx = ofRandom(-4,4);
//    float vy = ofRandom(-4,4);
//    myParticle.setParams(300,300,vx, vy);
    float vel = sin(ofGetElapsedTimef());
    myParticle.setParams(mouseX, mouseY, vel, vel * 3);
    particleList.push_back(myParticle);
    
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
//    float vel = sin(ofGetElapsedTimef() * 3);
//    myParticle.setParams(x, y, vel, vel * -3);

    for (int i = 0; i < particleList.size(); i++){
        float circVal = ofRandom(PI);
        float vx = cos( circVal ) * ofRandom(0,4);
        float vy = sin( circVal ) * ofRandom(0,4);
//        float vx = ofRandom(0,4);
//        float vy = ofRandom(0,4);
		particleList[i].setParams(mouseX,mouseY,vx, vy);
        
	}
    
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
