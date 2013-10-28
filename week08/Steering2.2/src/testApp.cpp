#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSeedRandom();
//    ofSetBackgroundAuto(false);
    
    ofSetVerticalSync(true);
    ofBackground(0);

    dest1.set(ofRandomWidth(),ofRandomHeight());
    dest2.set(ofRandomWidth(),ofRandomHeight());
    
    pos = ofGetWindowSize() / 2;
    car1.setParam( pos, ofVec2f(10, -5) );
    car2.setParam( pos, ofVec2f(10, 5) );
    

}

//--------------------------------------------------------------
void testApp::update(){

    car1.seek( dest1 );
    car2.seek( dest2 );
    
    if( car1.pos.distance( car2.pos ) < 200 ){
        car1.addRepulsionForce(car2.pos);
        car2.addRepulsionForce(car1.pos);
        color1.set(ofColor::red);
        color2.set(ofColor::red);
        
    } else {
        color1.set(ofColor::magenta);
        color2.set(ofColor::lime);
    }
    
    car1.update();
    car2.update();
    
    
    if( car1.pos.distance(dest1) < 5){ //where is the distance coming from???
        dest1 = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car2.pos.distance(dest2) < 5){ //where is the distance coming from???
        dest2 = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    }
    
//    if( car1.pos.distance( car2.pos ) < 200 ){
//        car1.color = ofColor(255,0,0);
//        car2.color = ofColor(255,0,0);
//        
//        car1.addRepulsionForce( car2.pos );
//        car2.addRepulsionForce( car1.pos );
//    }else{
//        car1.color = ofColor(0,255,0);
//        
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor( color1 );
    car1.draw();
    ofCircle(dest1, 10);
    
    ofSetColor( color2 );
    car2.draw();
    ofCircle(dest2, 10);
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
