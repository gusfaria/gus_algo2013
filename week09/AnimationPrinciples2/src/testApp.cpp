#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);
    bBackgroundColor = true;

    
    
    for (int i = 0;  i < 1; i++) {
        Element tmp;
//        color.setHsb(200,244,255);
        tmp.setup( );
        Elements.push_back( tmp );
    }
    
    counter = 0;
//    rectSize = 100;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < Elements.size(); i++) {
        Elements[i].update();
    }
    
    if (counter < 52) counter++;
    
    if (counter % 10 == 0 && counter < 50) {
        Element tmp;
        color.setHsb(200,244,255);
        tmp.setup( );
        Elements.push_back( tmp );
        //counter = 0;
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    

    if (bBackgroundColor) {
        ofBackground(0, 0, 0);
    } else {
        ofBackground(ofColor::magenta);
    }
    
    for (int i = 0; i < Elements.size(); i++) {
        Elements[i].pos.x = 480 + 110*i ;
        Elements[i].draw( );
        
        if(Elements[i].vel.y <= 0.1){
//            Elements[i].color.setHsb(100, 255, 255);
            for(int k = 0; k <  200; k ++){
//                Elements[2].increment -= 0.1;
                Elements[i].reset();

                
            }
            
        }
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
