#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    box2d.init();
    box2d.createBounds();
    box2d.setGravity(0,10);
    
    ofxBox2dRect b1, b2, b3;
    
    b1.setPhysics(1, 0.5, 1.0);
    b2.setPhysics(1, 0.5, 1.0);
    b3.setPhysics(1, 0.5, 1.0);
    
    b1.setup( box2d.getWorld(), 800, ofGetHeight() - 100, 15, 80);
    b2.setup( box2d.getWorld(), 900, ofGetHeight() - 100, 15, 80);
    b3.setup( box2d.getWorld(), 850, ofGetHeight() - 160, 100, 15);
    
    rectList.push_back( b1 );
    rectList.push_back( b2 );
    rectList.push_back( b3 );
    
    
    ofBackground(0);
    
}


//--------------------------------------------------------------
void testApp::update(){
    box2d.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i = 0; i < rectList.size(); i++){
        rectList[i].draw();
    }
    
    for(int i = 0; i < birdList.size(); i++){
        birdList[i].draw();
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
    ofxBox2dCircle bird;
    bird.setPhysics(1.0, 0.5, 1.0);
    bird.setup(box2d.getWorld(), x, y, 15);
    
    bird.addForce(ofVec2f(200,0), ofRandom(20,20));
    
    birdList.push_back (bird);
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
