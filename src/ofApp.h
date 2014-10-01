#pragma once

#include "ofMain.h"
#include "ofMesh.h"
#include "ofxPuppetInteractive.h"
#include "ofxButterfly.h"

//#include <Accelerate/Accelerate.h>

class ofApp : public ofBaseApp
{

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
		
    // The meshes that will be used for the subdivision and puppeteering.
    ofMesh mesh, subdivided;
    
    // The puppet class.
   	ofxPuppetInteractive puppet;
    
    ofxButterfly butterfly;
    
    /* The number of subdivisions that should be performed on the
     * deformed mesh of the puppet at every frame.
     */
    int subs = 0;
    
    ofTexture texture;
    
private:
    void updateSubdivisionMesh();
};
