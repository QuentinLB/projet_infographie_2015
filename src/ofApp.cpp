#include "ofApp.h"
#include "guiVoyageurEspace.h"

guiVoyageurEspace gui;

ofSpherePrimitive planettes[3];
ofImage textures[3];
ofLight pointLight;
ofCamera cam;
ofMaterial material[3];

const int SOLEIL = 0;
const int PLANETTE = 1;
const int LUNE = 2;

//--------------------------------------------------------------
void ofApp::setup(){
	gui = *new guiVoyageurEspace();

	gui.setup();

	ofBackground(ofColor::black);

	ofRectangle orientedViewport = ofGetNativeViewport();
	float eyeX = orientedViewport.width / 2;
	float eyeY = orientedViewport.height / 2;

	cam.setPosition(ofGetWidth()*.2, ofGetHeight()*.75, 300);
	cam.lookAt(ofVec3f(eyeX, eyeY, 0), ofVec3f(0, 1, 0));

	planettes[SOLEIL].setRadius(100);
	planettes[SOLEIL].setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 0);

	material[SOLEIL].setEmissiveColor(ofFloatColor::white);

	pointLight.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 0);

	textures[SOLEIL].loadImage("texture_sun.jpg");

	planettes[PLANETTE].setRadius(20);
	planettes[PLANETTE].setPosition(ofGetWidth() / 4, ofGetHeight() / 2, 0);

	material[PLANETTE].setSpecularColor(0);

	textures[PLANETTE].loadImage("texture_earth_clouds.jpg");

	planettes[LUNE].setRadius(4);
	planettes[LUNE].setPosition(ofGetWidth() / 4 - 15, ofGetHeight() / 2, 0);

	material[LUNE].setSpecularColor(0);

	textures[LUNE].loadImage("texture_moon.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	gui.draw();

	ofEnableLighting();
	pointLight.enable();

	cam.begin();

	for (int astre = SOLEIL; astre <= LUNE; astre++)
	{
		ofPushMatrix();
		textures[astre].getTextureReference().bind();
		planettes[astre].mapTexCoordsFromTexture(textures[astre].getTextureReference());

		material[astre].begin();

		if (astre == SOLEIL)
		{
			planettes[astre].rotate(0.20, 0.0, 0.1, 0);
		}
		else
		{
			planettes[astre].rotate(0.1, 0.0, 0.1, 0); // rotate on itself
		}
		planettes[astre].draw();

		material[astre].end();

		textures[astre].getTextureReference().unbind();
		ofPopMatrix();
	}
	ofDisableLighting();
	cam.end();
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
