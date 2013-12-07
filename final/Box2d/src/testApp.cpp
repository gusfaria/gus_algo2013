#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(200);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    

    
    //box2d
    box2d.init();
    box2d.setFPS(30);
    box2d.setGravity(0,0);
    box2d.createBounds();
    
    for (int i = 0; i < 30; i ++) {
        
        ofSetColor(color);
        ofxBox2dRect r;
        //    r.setPhysics(float density, float bounce, float friction)
        r.setPhysics(5, 0.53, 0.31);
        rectPos.x = ofRandomWidth();
        rectPos.y = ofRandomHeight();
        r.setup(box2d.getWorld(), rectPos.x, rectPos.y, 30,50);

        rectlist.push_back( r );
    }
}

//--------------------------------------------------------------
void testApp::update(){
    box2d.update();
    for (int i = 0; i < rectlist.size(); i++) {
        rectlist[i].addForce(ofVec2f(10,10), 2);
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){

    for (int i = 0; i < rectlist.size(); i++) {
        rectlist[i].draw();
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
