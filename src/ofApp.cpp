#include "ofApp.h"
#include<map>

//--------------------------------------------------------------
void ofApp::setup()
{
    mesh.load("handmarksNew.ply");
    puppet.setup(mesh);
}

//--------------------------------------------------------------
void ofApp::update()
{
   puppet.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    /*
    ofBackground(ofColor::black);
    
    // Draw the original edges white.
    ofSetColor(ofColor::white);
    mesh.drawWireframe();
    
    // Draw the new subdivided edges in yellow.
    ofSetColor(ofColor::yellow);
    subdivided.drawWireframe();
     */
    
    ofBackground(0);
	puppet.drawWireframe();
	puppet.drawControlPoints();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    // Subdivde the mesh upon the 's' key being pressed.
    if(key == 's')
    {
        // Store control points.
        std::map<int, ofVec2f> points;
        puppet.getControlPoints(points);

        // Subdivide the mesh.
        mesh = butterfly.subdivide(mesh, 1);
        puppet.setup(mesh);
        
        // Replace the control point positions.
        for(auto iter = points.begin(); iter != points.end(); ++iter)
        {
            puppet.setControlPoint(iter -> first, iter -> second);
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
