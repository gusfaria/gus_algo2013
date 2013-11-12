#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    ofSetCircleResolution(100);
    
    // 192.168.1.111 ADIEL
    mSender.setup("192.168.1.111", 9999);
    mReceiver.setup(8888);

    
    gravity.set(0,0.1);
    
    aPos.set(0,0);
//    aVel.set(10,0);
    

//    mVel.set(10,0);
    
    hit = false;
    hitTimer = 1000;
    

}

//--------------------------------------------------------------
void testApp::update(){


    
    //RECEIVB ADIELS MSGs
    while( mReceiver.hasWaitingMessages() ) {
        ofxOscMessage  m;
        mReceiver.getNextMessage( &m );
        string addr = m.getAddress();
        
        if ( addr == "/adiel/pos"){
    
            float AdielPosX = m.getArgAsInt32(0);
            float AdielPosY = m.getArgAsInt32(1);
            
            aPos.set( AdielPosX + 1024, AdielPosY );
            
        }
    }
    
//    cout << aPos.x << endl;
    
    
    ///SEND MSG TO ADIEL
    ofxOscMessage s;
    s.setAddress("/gustavo/pos");
    s.addIntArg(mPos.x);
    s.addIntArg(mPos.y);
//    m.addIntArg(mVel.x);
//    m.addIntArg(mVel.y);
    mSender.sendMessage( s );
    mPos += mVel;
    mVel += gravity;
    
    if(mPos.y > ofGetWindowHeight() || mPos.y < 0){
        mVel.y *= -1;
    }
    
    
    //collkision detection
    if (ofDist(mPos.x, aPos.x, mPos.y, aPos.y) < 100) {
        hit = true;
        hitTimer = ofGetElapsedTimef();
        hitPos.set((mPos + aPos)/2);
        mVel.set( 0, 0 );
    }
    

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255, 255, 255, 10);
    ofRect(ofGetWindowWidth()/2,ofGetWindowHeight()/2,ofGetWindowWidth(),ofGetWindowHeight());
    
    
    if(hit && ofGetElapsedTimeMillis() < hitTimer + 300){
        ofSetColor(ofColor::yellow);
        ofCircle(hitPos, 150);
    }
    
//    this is adiels
    ofPushMatrix();{
        ofTranslate(0,0);
        ofSetColor(255,0,0);
        ofCircle(aPos, 30);
    }ofPopMatrix();
    
    //this is mine
    ofPushMatrix();{
        ofTranslate(0, 0);
        ofSetColor(0, 0, 255);
        ofCircle(mPos, 30);
        ofSetColor(0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofRect(mouseX,mouseY,20, 150);
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

        mPos.set(x,y);
    mVel.set(10, -5);
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
