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

    

        leftEye.pos = ofPoint(ofGetWindowWidth() - 50, ofGetWindowHeight() * 0.5 );
        rightEye.pos = ofPoint( ofGetWindowWidth() - 10, ofGetWindowHeight() * 0.5 );

    
    
}


//--------------------------------------------------------------
void testApp::update(){
    
    ofPoint mousePos( mouseX, mouseY );
    
    leftEye.mousePos = mousePos;
    rightEye.mousePos = mousePos;
    
    
    for( vector<Particle>::iterator it=pList.begin(); it!=pList.end(); ){
        it->update();
        
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
    
    ofBackgroundGradient(ofColor(170), ofColor(230), OF_GRADIENT_LINEAR);

    //put the particles in the loop?
    for( vector<Particle>::iterator it = pList.begin(); it!=pList.end(); it++){
        it->draw();
    }
    

    for( int i=0; i<20; i++ ){
        addParticle();
    }
    
    
    ofPushMatrix();{
        ofSetColor(245);
        ofCircle(ofGetWindowWidth()/2 + 230 ,ofGetWindowHeight() - 120, 100);
        ofSetColor(250);
        ofCircle(ofGetWindowWidth()/2 + 230 ,ofGetWindowHeight() - 240, 60);
    }ofPopMatrix();
    
    ofPushMatrix();{
        ofTranslate(-255 , 130);
        leftEye.draw();
        rightEye.draw();
    }ofPopMatrix();
    
}


//--------------------------------------------------------------
void testApp::addParticle(){


        Particle p;
        // we'll pick a random direction for our particle to move initially
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
