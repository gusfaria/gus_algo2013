#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class Particle : public ofxBox2dCircle {
public:
    Particle() {
        pizza.loadImage("pizza.png");
    }
    
    
    ofColor color;
    ofImage pizza;
    
	void draw() {
		float radius = 30;
        float rotation = getRotation();
		ofPushMatrix();{
            ofTranslate(getPosition().x, getPosition().y, 0);
            ofRotate(rotation);
            
            ofSetColor(color);
            ofFill();
            pizza.draw(0,0, radius);
            ofPushStyle();
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofSetColor(255, 0, 0);
            ofCircle(0, 0, 30);
            ofPopStyle();
		}ofPopMatrix();
		
	}
};

class RectParticle : public ofxBox2dRect {
public:
	RectParticle() {
        hotdog.loadImage("hotdog.png");
    }
    ofImage hotdog;
	void draw() {
        float rSizeW = getWidth();
        float rSizeH = getHeight();
        float rotation = getRotation();
		ofPushMatrix();{
            ofTranslate(getPosition().x, getPosition().y, 0);
            ofRotate(rotation);
            ofPushStyle();
            ofSetColor(0, 255, 0);
            ofRect(0, 0, rSizeW, rSizeH);
            ofPopStyle();
            ofSetColor(255);
            ofFill();
            hotdog.draw(0, 0, rSizeW,rSizeH);

		}ofPopMatrix();
	}
};

class SquareParticle : public ofxBox2dRect {
public:
	SquareParticle() {
        burger.loadImage("burger.png");
    }
    ofImage burger;
	void draw() {
        float squareSize = getWidth();
        float rotation = getRotation();
		ofPushMatrix();{
            ofTranslate(getPosition().x, getPosition().y, 0);
            ofRotate(rotation);
            ofPushStyle();
            ofSetColor(0, 0, 255);
            ofRect(0, 0, squareSize, squareSize);
            ofPopStyle();
            ofSetColor(255);
            burger.draw(0,0,squareSize,squareSize);
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
	vector		<Particle>      particles;
    vector      <RectParticle>  rectlist;
    vector      <SquareParticle>  sqrlist;
    
};
