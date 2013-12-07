#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    box2d.init();
    box2d.createBounds();
//    box2d.createGround();
    box2d.setFPS(60);
    box2d.setGravity(0, 0);
    box2d.registerGrabbing();
    
//    ofxBox2dRect b1;
//    b1.setPhysics(1, 0.5, 1);
//    b1.setup( box2d.getWorld(), 800, ofGetHeight()-100, 15, 80 );
//    
//    ofxBox2dRect b2;
//    b2.setPhysics(1, 0.5, 1);
//    b2.setup( box2d.getWorld(), 900, ofGetHeight()-100, 15, 80 );
//    
//    ofxBox2dRect b3;
//    b3.setPhysics(1, 0.5, 1);
//    b3.setup( box2d.getWorld(), 850, ofGetHeight()-160, 100, 15 );
//    
//    rectList.push_back( b1 );
//    rectList.push_back( b2 );
//    rectList.push_back( b3 );
    
    for (int i = 0; i < 100; i++) {
        ofxBox2dRect food;
        food.setPhysics(1,0.2,1);
        pos.x = ofRandomWidth();
        pos.y = ofRandomHeight();
        food.setup(box2d.getWorld(), ofRandomWidth(), ofRandomHeight(), 10, 30 );
        food.addForce( ofVec2f(ofRandom(-30,30), ofRandom(-30,30)), 20.0);
        foodlist.push_back( food );
    }
    
    
    
    ofSetVerticalSync(true);
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    box2d.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for( int i=0; i<rectList.size(); i++ ){
        rectList[i].draw();
    }
    
    for( int i=0; i<birdList.size(); i++ ){
        birdList[i].draw();
    }
    
    for( int i=0; i<foodlist.size(); i++ ){
        ofColor color;
        color.setHsb(ofRandom(255), 100, 100);
        foodlist[i].draw();
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
    bird.setPhysics(1.0, 0.5, 0.1);
    bird.setup( box2d.getWorld(), x, y, 30 );
    
    bird.addForce( ofVec2f(200,0), 20.0);       // a force, and then a scale
    
    birdList.push_back( bird );
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
