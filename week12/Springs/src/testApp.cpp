#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    
    bIsDragging = false;
    
    k = 0.1;
    restLenght = 200.0;
    
    anchor = ofVec2f( ofGetWindowWidth()/2, 10 );
    handle = ofVec2f( ofGetWindowWidth()/2, 310 );
    
    
}


//--------------------------------------------------------------
void testApp::update(){
    if( bIsDragging ){
        return; // exit the function here! doesnt continue ... //
    }
    
    
    ofVec2f force = handle - anchor;
    float len = force.length(); // the magnitude of this vector!
    float stretchLen = len - restLenght;
    
//    force.normalize();
    
    cout << force.normalize() << endl;
    
    force *= -1 * k * stretchLen;
    applyForce( force );
    applyForce(ofVec2f( 0, 1.0 ));
    
    //do physics stuff
    vel += acc;
    vel *= 0.95;
    
    handle += vel;
    
    acc.set( 0 );
}

//--------------------------------------------------------------
void testApp::draw(){
    ofLine( anchor, handle );
    
    ofNoFill();
    ofCircle( anchor, 10 );
    ofCircle( handle, 15 );
}

//--------------------------------------------------------------
void testApp::applyForce(ofVec2f force){
    acc += force;
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
    if( bIsDragging ){
        handle.set( x,y );
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if( ofVec2f(x,y).distance(handle) < 15 ){
        handle.set( x , y );
        vel.set(0);
        
        bIsDragging = true;
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
        bIsDragging = false;

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
