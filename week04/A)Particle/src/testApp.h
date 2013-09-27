#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "Bomb.h"


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
    
    void addParticle(ofVec2f pos, float velMult, float hue);
    vector<Particle> myParticle;
    vector<Bomb>myBomb;

    
    
    
};



// OWEN HELPED ME BIG TIME!!!!!
