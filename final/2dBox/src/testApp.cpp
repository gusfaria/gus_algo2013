#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    box2d.init();
    box2d.createBounds();
    box2d.setGravity(0,0);
    
    
    ofBackground(0);

    
    for (int i = 0; i < 40; i ++){
        ofxBox2dRect r;
        r.setPhysics(1, 0.5, 1);
        r.addForce(ofVec2f(10,-10), ofRandom(10,-10));
        r.setup(box2d.getWorld(), ofRandomWidth(), ofRandomHeight(), 20,60);
        foodlist.push_back (r);

    }
    
    
    
}


//--------------------------------------------------------------
void testApp::update(){
    box2d.update();
//    
//    for(int k=0; k < particleList.size(); k++){
//        particleList[k].update();
//    }
//    for (int i = 0; i < circleList.size(); i ++){
//        
////        circleList[i].addForce(ofVec2f frc, float scale);
//    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i = 0; i < foodlist.size(); i++){
        foodlist[i].draw();
    }
    
//    for(int i = 0; i < birdList.size(); i++){
//        birdList[i].draw();
//    }
    
//    for (int k = 0; k < particleList.size(); k++){
//        particleList[k].draw();
//    }
    
    for (int i = 0; i < foodlist.size(); i ++){
        ofSetColor(0, 0, 255);
        foodlist[i].draw();
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
    ofxBox2dCircle bird;
    bird.setPhysics(1.0, 0.5, 1.0);
    bird.setup(box2d.getWorld(), x, y, 15);
    
    bird.addForce(ofVec2f(200,0), ofRandom(20,20));
    
    birdList.push_back (bird);
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
