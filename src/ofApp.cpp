#include "ofApp.h"
#include "guiVoyageurEspace.h"
#include "Soleil.h"
#include "Terre.h"
#include "Lune.h"

guiVoyageurEspace gui;
Soleil sun;
Terre earth;
Lune moon;
ofLight light;

ofCamera cam;

//--------------------------------------------------------------
void ofApp::setup(){

	gui = *new guiVoyageurEspace();

	gui.setup();
	sun.setup(gui);
	earth.setup(gui);
	moon.setup(gui);

	ofBackground(ofColor::black);

	ofRectangle orientedViewport = ofGetNativeViewport();
	float eyeX = ofGetWidth() / 2;
	float eyeY = ofGetHeight() / 2;

	cam.setPosition(gui.getCamLocation());
	cam.lookAt(ofVec3f(ofGetWidth()*.5, ofGetHeight()*.5, 0), ofVec3f(0, 1, 0));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	gui.draw();

	cam.setPosition(gui.getCamLocation());
	cam.lookAt(ofVec3f(ofGetWidth()*.5, ofGetHeight()*.5, 0), ofVec3f(0, 1, 0));

	light.setPosition(gui.getSunCenter());
	light.setDiffuseColor(gui.getSunColor());

	ofEnableDepthTest();
	ofEnableLighting();
	light.enable();
	cam.begin();

	
	sun.draw(gui);
	ofVec3f positionTerre = earth.draw(gui);
	moon.draw(gui, positionTerre);

	cam.end();
	ofDisableLighting();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
