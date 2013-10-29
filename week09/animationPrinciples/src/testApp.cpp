#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);

    color2.setHsb(200,244,255);
    
    
  
  
    
    counter = 0;
    startTime = 0;
    time = 0;

    Element tmp;
    tmp.setup( );
    Elements.push_back( tmp );
    
    
}

//--------------------------------------------------------------
void testApp::update(){


    
    if(time > 5) {
        for(int k = 0; k <  200; k ++){
            Elements[2].increment -= 0.5;
        }
        
    }
    if(time >= 7){
        Elements[2].increment = 100;
        startTime = ofGetElapsedTimef();
    }
    
    for (int i = 0; i < Elements.size(); i++) {
        Elements[i].update();
        
        if(time > 6) {
            Elements[i].reset();
            counter = 0;
            Elements.erase(Elements.begin());
            
            
//            if(bBg){
//                ofBackground(0);
//            } else {
//                ofBackground(230, 230, 230);
//            }

        }
    }
    

    
    if (counter < 52) counter++;
    if (counter % 10 == 0 && counter < 50) {
        Element tmp;
        color.setHsb(200,244,255);
        tmp.setup( );
        Elements.push_back( tmp );
    }

    
    time = ofGetElapsedTimef() - startTime;


}

//--------------------------------------------------------------
void testApp::draw(){


    for (int i = 0; i < Elements.size(); i++) {

        cout << Elements[2].increment << endl;
        Elements[i].pos.x = 480 + 110*i ;
        Elements[i].draw( );
        
    }
    
    ofSetColor(255, 255, 255);
    ofDrawBitmapString(ofToString(counter), 30, 30);
    ofSetColor(255, 255, 255);
    ofDrawBitmapString(ofToString(startTime), 30, 45);
    ofSetColor(255, 255, 255);
    ofDrawBitmapString(ofToString(time), 30,60);

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
