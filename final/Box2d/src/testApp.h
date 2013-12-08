#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

//particles
class Particle : public ofxBox2dCircle {
public:
	Particle() {}
	ofColor color;
    
	void draw() {
		float radius = getRadius();
        float rotation = getRotation();
		ofPushMatrix();{
            ofTranslate(getPosition().x, getPosition().y, 0);
            ofRotate(rotation);
            ofSetColor(color.r, color.g, color.b);
            ofFill();
            ofCircle(0, 0, radius);
		}ofPopMatrix();
		
	}
};

class RectParticle : public ofxBox2dRect {
public:
	RectParticle() {}
	ofColor color;

	void draw() {
        float rSizeW = getWidth();
        float rSizeH = getHeight();
        float rotation = getRotation();
		ofPushMatrix();{
            ofTranslate(getPosition().x, getPosition().y, 0);
            ofRotate(rotation);
            ofSetColor(color);
            ofFill();
            ofRect(0, 0, rSizeW,rSizeH);
		}ofPopMatrix();
		
	}
};

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
	ofxBox2d						box2d;
	vector		<ofxBox2dCircle>	circles;
	vector		<ofxBox2dRect>		boxes;
	vector		<Particle>	particles;
    vector      <RectParticle> rectlist;
    
};
