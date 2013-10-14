#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
//    ofBackground(0);
    ofBackground(100);
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetCircleResolution(100);
    
    
    // make 50 particles up front!
    for( int i=0; i<50; i++ ){
        addParticle();
    }
    
    myPos.y = ofGetWindowHeight();
    myVel.y = -5;

    img.loadImage("nyc.jpeg");
    w = img.getWidth();
    h = img.getHeight();
    
}


//--------------------------------------------------------------
void testApp::update(){

    for( vector<Particle>::iterator it=pList.begin(); it!=pList.end(); ){
        it->update();
        
        if( it->bIsDead ){
            it = pList.erase(it);
        }else {
            it++;
        }
    }
    
    if (myPos.y <= ofRandom(100,500)) {
        myVel.y = 0;
    } else {
        myPos.y += myVel.y;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackgroundGradient(ofColor(0), ofColor(90), OF_GRADIENT_LINEAR);
    img.draw(0,0);
    
    for( vector<Particle>::iterator it = pList.begin(); it!=pList.end(); it++){
        it->draw();
    }

    for( int i=0; i<20; i++ ){
        addParticle();
    }

}


//--------------------------------------------------------------
void testApp::addParticle(){
        Particle p;
        ofVec2f rVel = ofVec2f( ofRandom(1.0), ofRandom(1.0) ) * 10.0 - 5.0;
        p.setup( rVel );
        pList.push_back( p );
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
