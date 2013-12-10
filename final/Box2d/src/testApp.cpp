#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAlphaBlending();
	ofSetVerticalSync(true);
//	ofBackgroundHex(0xfdefc2);
    ofBackgroundHex(0);
	ofSetLogLevel(OF_LOG_NOTICE);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
	box2d.init();
	box2d.setGravity(0, 0);
	box2d.setFPS(30.0);
    box2d.enableGrabbing();
//    box2d.createBounds();
    //pizza
    for ( int i = 0; i < 5; i ++ ) {
        float r = 30;
		Particle p;
		p.setPhysics(10, 0.1, 0.1);
		p.setup(box2d.getWorld(), ofRandom(ofGetWindowWidth()), ofRandom(50), r);
        p.color.set(250);
        p.setPosition(ofRandomWidth(), ofRandomHeight());

        ofVec2f veltemp;
        float neg = (int)ofRandom(2);
        if (neg == 1)   veltemp.set(ofRandom(-4, -2), ofRandom(-4, -3)) ;
        else veltemp.set(ofRandom(1, 2), ofRandom(1, 2));
        p.setVelocity(veltemp);
//        p.setDamping(1.0);
		particles.push_back(p);
        
    }
    //hotdog
    for (int i = 0; i < 3; i ++ ) {
        RectParticle r;
        ofVec2f rectSize;
        rectSize.x = 95;
        rectSize.y = 47;
        
        r.setPhysics(15, 0.53, 0.1);
        r.setup(box2d.getWorld(), ofRandom(ofGetWindowWidth()), ofRandom(50),rectSize.x,rectSize.y);
        r.setPosition(ofRandomWidth(), ofRandomHeight());
        ofVec2f veltemp;
        float neg = (int)ofRandom(2);
        if (neg == 1)   veltemp.set(ofRandom(-4, -2), ofRandom(-4, -3)) ;
        else veltemp.set(ofRandom(1, 2), ofRandom(1, 2));
        r.setVelocity(veltemp);
        r.setDamping(1.0);
        rectlist.push_back( r );
    }
    //burger
    for (int k=0; k <10; k++){
        SquareParticle s;
        int sqSize = 55;
        s.setPhysics(20, 0.53, 0.1);
        s.setup(box2d.getWorld(), ofRandom(ofGetWindowWidth()), ofRandom(50),sqSize,sqSize);
        s.setPosition(ofRandomWidth(), ofRandomHeight());
        ofVec2f veltemp;
        float neg = (int)ofRandom(2);
        if (neg == 1)   veltemp.set(ofRandom(-10, -2), ofRandom(-8, -3)) ;
        else veltemp.set(ofRandom(1, 2), ofRandom(1, 2));
        s.setVelocity(veltemp);
        s.setDamping(1.0);
        sqrlist.push_back( s );
    }
}

//--------------------------------------------------------------
void testApp::update(){
    box2d.update();

    //PIZA
    for( int i=0; i<particles.size(); i++ ){
        ofVec2f tempVel = particles[i].getVelocity();
        ofVec2f tempPos = particles[i].getPosition();
        
        if (tempPos.x < 0 ) particles[i].setPosition(ofGetWindowWidth(), tempPos.y);
        if (tempPos.y < 0 ) particles[i].setPosition(tempPos.x, ofGetWindowHeight());
        if (tempPos.x > ofGetWindowWidth() ) particles[i].setPosition(0, tempPos.y);
        if (tempPos.y > ofGetWindowHeight() ) particles[i].setPosition(tempPos.x, 0);
        
//        particles[i].addRepulsionForce(particles[i].getPosition().x, particles[i].getPosition().y, 0.2);
        particles[i].setVelocity( tempVel );
    }
    //HOTDOGS
    for( int i=0; i<rectlist.size(); i++ ){
        ofVec2f tempVel = rectlist[i].getVelocity();
        ofVec2f tempPos = rectlist[i].getPosition();
        if (tempPos.x < 0 ) rectlist[i].setPosition(ofGetWindowWidth(), tempPos.y);
        if (tempPos.y < 0 ) rectlist[i].setPosition(tempPos.x, ofGetWindowHeight());
        if (tempPos.x > ofGetWindowWidth() ) rectlist[i].setPosition(0, tempPos.y);
        if (tempPos.y > ofGetWindowHeight() ) rectlist[i].setPosition(tempPos.x, 0);
        rectlist[i].setVelocity( tempVel );
        
        // FORCE TO AVOID THE CENTER!!!
//        rectlist[i].addRepulsionForce(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 2.0f);
    }
    //BURGERS
    for( int i=0; i<sqrlist.size(); i++ ){
        ofVec2f tempVel = sqrlist[i].getVelocity();
        ofVec2f tempPos = sqrlist[i].getPosition();
        if (tempPos.x < 0 ) sqrlist[i].setPosition(ofGetWindowWidth(), tempPos.y);
        if (tempPos.y < 0 ) sqrlist[i].setPosition(tempPos.x, ofGetWindowHeight());
        if (tempPos.x > ofGetWindowWidth() ) sqrlist[i].setPosition(0, tempPos.y);
        if (tempPos.y > ofGetWindowHeight() ) sqrlist[i].setPosition(tempPos.x, 0);
        sqrlist[i].setVelocity( tempVel );
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackgroundGradient(ofColor(233,225,199), ofColor(169,179,172));
    
    for(int i=0; i<particles.size(); i++) {
        particles[i].draw();
	}
    
    for (int i = 0; i < rectlist.size(); i++) {
        rectlist[i].draw();
    }
    
    for (int i = 0; i < sqrlist.size(); i++) {
        sqrlist[i].draw();
        
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 't') ofToggleFullscreen();

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
