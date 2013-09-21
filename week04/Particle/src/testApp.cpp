#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0);
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetCircleResolution(100);
    ofSetBackgroundAuto(true);
    
    
    // make 50 particles up front!
    for( int i=0; i<50; i++ ){
        addParticle();
    }
    
    myPos.x = ofGetWindowWidth();
    myPos.y = ofGetWindowHeight();
    myVel.y = -5;

}


//--------------------------------------------------------------
void testApp::update(){
    
    for( vector<Particle>::iterator it=pList.begin(); it!=pList.end(); ){
        it->update(myPos);
        
        if( it->bIsDead ){
            it = pList.erase(it);   // When we erase one, it returns the next particle automatically.  It's done the "it++" for us!

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

// random s**t
//    ofPoint pos;
//        pos.x = ofNoise (ofGetElapsedTimef()) * ofGetWindowWidth();
//        pos.y = ofNoise (ofGetElapsedTimef()) * ofGetWindowHeight();
//        ofCircle(pos, 10);

// bloob
//    ofPushMatrix();{
//        ofTranslate(mouseX,mouseY);
//        ofBeginShape();{
//
//            for (int i = 0; i < 100; i++) {
//                float add = ofNoise(i/20.f,ofGetElapsedTimef() * 3);
//                ofSetColor (100);
//                ofVertex((200+100*add) * cos((i/100.0)*TWO_PI), (200+100*add) * sin((i/100.0)*TWO_PI));
//            }
//            
//        }ofEndShape();
//    }ofPopMatrix();
    
    
    


        myPos.x = sin(ofGetElapsedTimef() * 10)*5;
        ofCircle(myPos.x, myPos.y, 5);
    

    //put the particles in the loop?
    for( vector<Particle>::iterator it = pList.begin(); it!=pList.end(); it++){
        it->draw();
    }
    
}


//--------------------------------------------------------------
void testApp::addParticle(){


        Particle p;
        // we'll pick a random direction for our particle to move initially
        ofVec2f rVel = ofVec2f( ofRandom(1.0), ofRandom(1.0) ) * 10.0 - 5.0;
    myPos.x = ofGetWindowWidth() /2;
    myPos.y = ofGetWindowHeight();
    myPos.y += myVel.y;
        p.setup( rVel, ofPoint(myPos) );
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
    for( int i=0; i<50; i++ ){
        addParticle();
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
