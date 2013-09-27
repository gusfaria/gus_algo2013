#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(255);
    
//    myParticle.setParams(300, 300, ofRandom(-1,1), ofRandom(-1,1));
    
    
    for(int i = 0; i < 1000; i++){
        addParticle();
    }
    
}

//--------------------------------------------------------------
void testApp::addParticle(){
    Particle tmp;
    
//    float circleValue = ofRandom(TWO_PI);
//    float vx = cos( circleValue ) * ofRandom(0,4);
//    float vy = sin( circleValue) * ofRandom(0,4);
    
    float vx = ofRandom(-4,4); //looks like a square supposily
    float vy = ofRandom(-4,4);
    tmp.setParams(300, 300, vx, vy);
    particleList.push_back(tmp);
    
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].resetForces();
        particleList[i].addForce(ofVec2f(0,0.1));
        particleList[i].addDampingForce();
        particleList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(ofColor::seaGreen);
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].draw();
    }
    
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
   
    for (int i = 0; i < particleList.size(); i++) {
        Particle tmp;
//        float vx = ofRandom(-4,4);
//        float vy = ofRandom(-4,4);
        
        float circleValue = ofRandom(TWO_PI);
        float vx = cos( circleValue ) * ofRandom(0,4);
        float vy = sin( circleValue) * ofRandom(0,4);
        tmp.setParams(x, y, vx, vy);
        particleList.push_back(tmp);

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
