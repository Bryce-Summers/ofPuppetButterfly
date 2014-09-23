#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // Choose the data file in the bin directory to visualize.
    mesh.load("triangle.ply");
    puppet.setup(mesh);
    puppet.setControlPoint(0);
    puppet.setControlPoint(1);
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
	//puppet.drawWireframe();
	puppet.drawControlPoints();
    //butterfly.subdivideLinear(puppet.getDeformedMesh(), subs).drawWireframe();
    //butterfly.subdividePascal(puppet.getDeformedMesh(), subs).drawWireframe();
    butterfly.subdivideButterfly(puppet.getDeformedMesh(), subs).drawWireframe();
    //butterfly.subdivideBoundary(puppet.getDeformedMesh(), 1.5, subs).drawWireframe();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    
    // More subdividing.
    if(key == 'm' || key == OF_KEY_RIGHT)
    {
        subs++;
    }

    // Less subdividing.
    if((key == 'l' || key == OF_KEY_LEFT) && subs > 0)
    {
        subs--;
    }
    
    /* 
     * Below code may be used if you wish to subdivide the puppet's source mesh
     * instead of just subdividing its output mesh.
     * If this is used then the subdivided point may be used as control point in the puppeteering.
     */
    
     /*      
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
        
    }*/
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
// Allows the user to drag files into the window.
void ofApp::dragEvent(ofDragInfo info)
{
    
   if(info.files.size() > 0)
   {
       mesh.load(info.files.at(0));
       puppet.setup(mesh);
   }
    
}
