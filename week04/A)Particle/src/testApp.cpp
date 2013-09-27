#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetCircleResolution(100);
    ofSetBackgroundAuto(false);
    
    

}


//--------------------------------------------------------------
void testApp::update(){
    if (ofGetElapsedTimeMillis() % 20 == 0) {
        Bomb tmp;
        myBomb.push_back( tmp );
    }
    
    
    for( vector<Particle>::iterator it = myParticle.begin(); it!=myParticle.end();){
        
        it->update();
        
        if ( it->bIsDied() ) {
            it = myParticle.erase(it);
        }
        else {
            it++;
        }
    }
    
    float velX = (sin(ofGetElapsedTimef()*ofRandom(10,20))*ofRandom(0.5,0.9));

    for ( int i = 0; i < myBomb.size(); i++ ) {
        myBomb[i].update(velX);
        
        if (myBomb[i].bExploded()) {
            for ( int k = 0; k < 100; k ++ ) {
                addParticle(myBomb[i].pos, myBomb[i].initVel, myBomb[i].color.getHue());
            }
            
            myBomb.erase(myBomb.begin() + i);
        }
    }
    


}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0, 0, 0,50);
    ofRect(0,0,ofGetWindowWidth(), ofGetWindowHeight());
    ofDrawBitmapStringHighlight(ofToString(myParticle.size()), ofPoint(30,50));
    
    for( vector<Particle>::iterator it = myParticle.begin(); it!=myParticle.end(); it++){
        it->draw();
    }
    
    for( int i = 0; i < myBomb.size(); i++){
        myBomb[i].draw();
    }

}


//--------------------------------------------------------------
void testApp::addParticle(ofVec2f pos, float velMult, float hue){

    Particle tmp;
    tmp.setup(pos, velMult, hue);
    myParticle.push_back( tmp );

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
//    Bomb tmp;
//    myBomb.push_back( tmp );
    
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
