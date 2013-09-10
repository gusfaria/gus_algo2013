#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
	ofBackground(0);
    ofEnableAlphaBlending();
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofSetBackgroundAuto(false);
    
    img.allocate(768, 768, OF_IMAGE_GRAYSCALE);
    wSize = 768;
}

//--------------------------------------------------------------
void testApp::update(){
    unsigned char * pixels = img.getPixels();
    
    
    // (note: the order of these for loops doesn't matter)
    
    for (int i = 0; i < wSize; i++){
        for (int j = 0; j < wSize; j++){
            
            float dist = ofDist(mouseX, mouseY, i, j);
            
            if (dist < 100){
                pixels[ j * 768 + i ] = MIN(200, pixels[ j * 768 + i ] + ofMap(dist, 0, 100, 30, 0));
            }
        }
    }
    
    
    if (ofGetMousePressed() != true){
        
        
        for (int i = 0; i < wSize * wSize; i++){
            pixels[ i] = MAX(0,pixels[ i ]-1);
        }
        
    }
    
    
    img.update();

    
    mousePos.x = mouseX;
    mousePos.y = mouseY;
    for (int i = 0; i < myElements.size(); i++) {
        myElements[i].upload(ofRandom(0.01, 0.05), mousePos);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();{
        ofSetRectMode(OF_RECTMODE_CORNER);
        img.draw(0,0);
    }ofPopMatrix();
    
    for (int i = 0; i < myElements.size(); i++) {
        color = (mousePos, ofRandom(0,255));
        myElements[i].draw();
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
    Element tempElement;
    tempElement.setup(color);
    myElements.push_back(tempElement);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    for (int i = 0; i < myElements.size(); i++) {
        myElements.pop_back();
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
