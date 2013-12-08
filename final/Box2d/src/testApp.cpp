#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
//	ofBackgroundHex(0xfdefc2);
    ofBackgroundHex(0);
	ofSetLogLevel(OF_LOG_NOTICE);
	
	box2d.init();
	box2d.setGravity(0, 0);
	box2d.setFPS(30.0);
    box2d.enableGrabbing();
//    box2d.createBounds();

    for ( int i = 0; i < 50; i ++ ) {
        float r = ofRandom(5, 10);		// a random radius 4px - 20px
		Particle p;
		p.setPhysics(3, 0.53, 0.31);
		p.setup(box2d.getWorld(), ofRandom(ofGetWindowWidth()), ofRandom(50), r);
//		p.color.r = ofRandom(20, 100);
//		p.color.g = 0;
//		p.color.b = ofRandom(150, 255);
        p.color.setHsb(10, ofRandom(200), 250);
        p.setPosition(ofRandomWidth(), ofRandomHeight());
        ofVec2f veltemp;
        float rand = ofRandom(4,6);
        float neg = (int)ofRandom(2);

        if (neg == 1)   veltemp.set(ofRandom(-4, -2), ofRandom(-4, -3)) ;
        else veltemp.set(ofRandom(1, 2), ofRandom(1, 2));
        
        p.setVelocity(veltemp);
        p.setDamping(1.0);
		particles.push_back(p);
    }
    
    for (int i = 0; i < 40; i ++ ) {
        RectParticle r;
        ofVec2f rectSize;
        rectSize.set(30,10);
        r.setPhysics(10, 0.53, 0.1);
        r.setup(box2d.getWorld(), ofRandom(ofGetWindowWidth()), ofRandom(50),10,30);
        r.color.setHsb(250, ofRandom(200), 250);
        r.setPosition(ofRandomWidth(), ofRandomHeight());
        r.setVelocity(-3, 3);
        r.setDamping(1.0);
        rectlist.push_back( r );
    }
}

//--------------------------------------------------------------
void testApp::update(){
    box2d.update();
    
    for( int i=0; i<particles.size(); i++ ){
        ofVec2f tempVel = particles[i].getVelocity();
        ofVec2f tempPos = particles[i].getPosition();
        
        if (tempPos.x < 0 ) particles[i].setPosition(ofGetWindowWidth(), tempPos.y);
        if (tempPos.y < 0 ) particles[i].setPosition(tempPos.x, ofGetWindowHeight());
        if (tempPos.x > ofGetWindowWidth() ) particles[i].setPosition(0, tempPos.y);
        if (tempPos.y > ofGetWindowHeight() ) particles[i].setPosition(tempPos.x, 0);
        
        particles[i].addRepulsionForce(particles[i].getPosition().x, particles[i].getPosition().y, 0.2);
        particles[i].setVelocity( tempVel );
    }
    
    for( int i=0; i<rectlist.size(); i++ ){
        ofVec2f tempVel = rectlist[i].getVelocity();
        ofVec2f tempPos = rectlist[i].getPosition();
        
        if (tempPos.x < 0 ) rectlist[i].setPosition(ofGetWindowWidth(), tempPos.y);
        if (tempPos.y < 0 ) rectlist[i].setPosition(tempPos.x, ofGetWindowHeight());
        if (tempPos.x > ofGetWindowWidth() ) rectlist[i].setPosition(0, tempPos.y);
        if (tempPos.y > ofGetWindowHeight() ) rectlist[i].setPosition(tempPos.x, 0);
        
        rectlist[i].setVelocity( tempVel );

    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i=0; i<particles.size(); i++) {
		ofSetColor(255, 0, 0);
        particles[i].draw();
        
	}
    
    for (int i = 0; i < rectlist.size(); i++) {
        rectlist[i].draw();
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
