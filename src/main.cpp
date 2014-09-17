#include "ofMain.h"
#include "ofApp.h"

/*
 *
 * ofPuppetButterfly.
 *
 * Written by Bryce Summers with the support of the Carnegie Mellon University Studio for Creative Inquiry.
 *
 * Date : 9 / 17 / 2014
 *
 * Purpose : Demonstrates the interplay between ofxPuppet and ofxButterfly.
 */


//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
