#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
//    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    ofBackground(0);
    
    box2d.init();
    box2d.setGravity(0, 10);
    box2d.setFPS(30.0); //the velocity it will update!
    
    box2d.createGround(); //draw a floor to the composition
    box2d.createBounds();
    box2d.registerGrabbing();
    
    boxCircle.setPhysics(1.0, 0.5, 1.0);
    boxCircle.setup(box2d.getWorld(), 200, 200, 20);
    
    anchor.setPhysics(3.0, 0.53, 0.1);;
    anchor.setup(box2d.getWorld(), ofGetWindowWidth()/2, 20, 10);
    
    for (int i = 0; i<5; i++) {
        ofxBox2dCircle circle;
        circle.setPhysics(3.0, 0.53, 0.1);
        circle.setup(box2d.getWorld(), ofGetWindowWidth()/2, 100+(i*20), 10);
        circleList.push_back( circle );
    }
    
    for(int i =0; i<circleList.size(); i++){
        ofxBox2dJoint joint;
        
        if (i ==0 ){
            joint.setup( box2d.getWorld(), anchor.body, circleList[i].body );
        } else {
            joint.setup( box2d.getWorld(), circleList[i-1].body, circleList[i].body );
        }
        
        joint.setLength(25);
        jointList.push_back( joint );
    }

}

//--------------------------------------------------------------
void testApp::update(){
//    ofSetColor(0,80);
//    ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    ofSetColor(ofColor::aquamarine);
    box2d.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    boxCircle.draw();
    
    anchor.draw();
    
    for (int i = 0; i<circleList.size(); i++) {
        circleList[i].draw();
    }
    
    for (int i = 0; i<jointList.size(); i++) {
        jointList[i].draw();
    }
    

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    if( key == 'n'){
        ofxBox2dCircle circle;
        circle.setPhysics(3.0, 0.53, 0.1);
        circle.setup(box2d.getWorld(), circleList.back().getPosition().y, circleList.back().getPosition().y, 10);
        
        circleList.push_back( circle );
        
        int a = circleList.size()-2;
        int b = circleList.size()-1;
        
        // connect them with a joint
        ofxBox2dJoint joint;
        joint.setup( box2d.getWorld(), circleList[a].body, circleList[b].body );
        joint.setLength(25);
        jointList.push_back( joint );
    }
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
