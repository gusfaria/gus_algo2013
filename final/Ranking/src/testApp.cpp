#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    setGui();
    bFirst = true;
}

void testApp::exit() {
    //    gui->saveSettings("guiSettings.xml");
    //    delete gui;
}

//--------------------------------------------------------------
void testApp::onGuiEvent(ofxUIEventArgs &e) {
    string name = e.widget->getName();
    if (name == "INPUT TEXT") {
        ofxUITextInput *textinput = (ofxUITextInput *) e.widget;
        if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_ENTER)
        {
            cout << "ON ENTER: ";
            //            ofUnregisterKeyEvents((testApp*)this);
        }
        else if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_FOCUS)
        {
            cout << "ON FOCUS: ";
        }
        else if(textinput->getTriggerType() == OFX_UI_TEXTINPUT_ON_UNFOCUS)
        {
            cout << "ON BLUR: ";
            //            ofRegisterKeyEvents(this);
        }
        
        username = textinput->getTextString();
        gui->saveSettings("guiSettings.xml");
        
        cout << username << endl;
        
    }
}
//--------------------------------------------------------------
void testApp::setGui(){
    
    gui = new ofxUICanvas(ofGetWindowWidth()/2 - 150,(ofGetWindowHeight()/2) - 80, 300, 40);
    gui->setDrawBack(false);
    gui->setFontSize(OFX_UI_FONT_MEDIUM, 14);
    textBox = gui->addTextInput("INPUT TEXT", "INSERT YOUR NAME", 35);
    textBox->setAutoClear(true);
    ofAddListener(gui->newGUIEvent,this,&testApp::onGuiEvent);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofDrawBitmapString(username, ofPoint(10,10));
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
		username = username.substr(0, username.length()-1);
        
	} else if(key == OF_KEY_RETURN){
        gui->saveSettings("guiSettings.xml");
        username.clear();
    } else {
		if( bFirst && key != 2305){
			username.clear();
			bFirst = false;
		}
		username.append(1, (char)key);
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
