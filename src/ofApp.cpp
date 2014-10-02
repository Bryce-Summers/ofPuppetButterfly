#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // Initialize the mesh.
    mesh.load("hand-2014-151v-R.ply");

    // Setup its original texture coordinates.
    int len = mesh.getNumVertices();
    for(int i = 0; i < len; i++)
    {
        ofVec2f vec = mesh.getVertex(i);
        mesh.addTexCoord(vec);
    }
    
    // Initialize the puppet.
    puppet.setup(mesh);
    puppet.setControlPoint(0);
    puppet.setControlPoint(1);
    
    
    
    updateSubdivisionMesh();
    
    
    // Load the hand texture into the mesh.
    ofImage image;
    image.loadImage("hand-R.png");
    texture = image.getTextureReference();
    bShowWireframe = false;
    
  
}

//--------------------------------------------------------------
void ofApp::update()
{
    ofShowCursor();
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
    
    ofSetColor(255);
    ofBackground(0);
	//puppet.drawWireframe();

    // Adapt the subdivided mesh to teh puppet's deformation.
    butterfly.fixMesh(puppet.getDeformedMesh(), subdivided);
    
    
    texture.bind();
    
    // Draw the corect mesh.
    subdivided.drawFaces();

    texture.unbind();
    
    //----------------
    if (bShowWireframe){
        glLineWidth(1.0);
        subdivided.drawWireframe();
    }
    
  	puppet.drawControlPoints();
    
    int xMargin = 10;
    ofSetColor(ofColor::wheat);
    ofDrawBitmapString("# Subdivisions: " + ofToString(subs), xMargin, 30);
    ofDrawBitmapString("Press <Right Arrow> to increase the edge subdivisions", xMargin, 50);
    ofDrawBitmapString("Press <Left  Arrow> to decrease the edge subdivisions", xMargin, 70);
    ofDrawBitmapString("Press 'w' to show wireframe", xMargin, 90);
                       
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
        updateSubdivisionMesh();
    }

    // Less subdividing.
    if((key == 'l' || key == OF_KEY_LEFT) && subs > 0)
    {
        subs--;
        updateSubdivisionMesh();
    }
    
    if (key == 'w'){
        bShowWireframe = !bShowWireframe;
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

void ofApp::updateSubdivisionMesh()
{
    butterfly.topology_start(mesh);

    for(int i = 0; i < subs; i++)
    {
        butterfly.topology_subdivide_boundary();
    }
    
    subdivided = butterfly.topology_end();
    
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
