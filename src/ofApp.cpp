#include <string>
#include "ofApp.h"
#include "guiVoyageurEspace.h"
#include "GrapheScene.h"
#include "GrapheSceneNode.h"
#include "Soleil.h"
#include "Terre.h"
#include "Lune.h"
#include "CubeMap.h"
#include "modele3D.h" // Modele 3D
#include "firstPersonneCam.h"
#include "PerspectiveCam.h"


std::string XN = "cubemap_left2.png";
std::string XP = "cubemap_right1.png";
std::string YN = "cubemap_bottom4.png";
std::string YP = "cubemap_top3.png";
std::string ZN = "cubemap_back6.png";
std::string ZP = "cubemap_front5.png";

IElementDessinable* gui;
GrapheScene* graphe_scene;
IElementDessinable* sun;
IElementDessinable* earth;
IElementDessinable* moon;
ofLight light;
IElementDessinable* cubemap;
ofCamera cam;
firstPersonneCam fp_cam;
PerspectiveCam pers_cam;

bool CAMERA_TRACKING = false;
bool fp_cam_enabled = false;

//Modele 3D
modele3D *vaisseau;

//--------------------------------------------------------------
void ofApp::setup(){
	cubemap = new CubeMap();
	((CubeMap*) cubemap)->setup(XP,YP,ZP,XN,YN,ZN);

	gui = new guiVoyageurEspace();
	((guiVoyageurEspace*) gui)->setup();

	sun = new Soleil();
	((Soleil*)sun)->setup((guiVoyageurEspace*) gui);
	earth = new Terre();
	((Terre*)earth)->setup((guiVoyageurEspace*) gui);
	moon = new Lune();
	((Lune*)moon)->setup((guiVoyageurEspace*) gui);



	//construction du graphe de scene
	GrapheSceneNode racine(cubemap);
	racine.addDescendant(new GrapheSceneNode(sun));
	racine.addDescendant(new GrapheSceneNode(earth));
	racine.addDescendant(new GrapheSceneNode(moon));
	graphe_scene = new GrapheScene(&racine);

	// Command OpenGL qui utilise l'information de profondeur pour l'occlusion
	// au lieu de dessiner des objets qui sont cachées par d'autres par dessus
	glEnable(GL_DEPTH_TEST); 

	fp_cam.setup();
	pers_cam.setup();
	//Modele 3D
	//vaisseau = new modele3D("turbosonic.obj", (float)ofGetWidth()*0.75, (float)ofGetHeight()*0.65, 0, 0.5, 0.5, 0.5);
	//vaisseau->setup();

	ofRectangle orientedViewport = ofGetNativeViewport();
	float eyeX = ofGetWidth() / 2;
	float eyeY = ofGetHeight() / 2;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::gray);
	if (fp_cam_enabled){
		fp_cam.draw();
		fp_cam.begin();
	}
	else{
		gui->draw();
		pers_cam.draw();
		pers_cam.begin();
	}
	
	
	//cubemap->draw();

	light.setPosition(((guiVoyageurEspace*) gui)->getSunCenter());
	light.setDiffuseColor(((guiVoyageurEspace*) gui)->getSunColor());

	ofEnableDepthTest();
	ofEnableLighting();
	light.enable();

	/*sun.draw();
	earth.draw();
	moon.draw();*/
	graphe_scene->render();

	//Modele 3D
	//vaisseau->draw();
	if (fp_cam_enabled){
		fp_cam.end();
	}
	else{
		pers_cam.end();
	}
	ofDisableLighting();
	ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 15);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_TAB){
		fp_cam_enabled = !fp_cam_enabled;
	}
	else if (fp_cam_enabled){
		fp_cam.keyPressed(key);
	}
	
	/*ofVec3f pos = cam.getPosition();
	if(key == 'z' || key == 'w' || key == OF_KEY_UP)
		pos.z = pos.z - CAMERA_VIT;
	else if(key == 's' || key == OF_KEY_DOWN)
		pos.z = pos.z + CAMERA_VIT;
	else if(key == 'q' || key =='a' || key == OF_KEY_LEFT)
		pos.x = pos.x - CAMERA_VIT;
	else if(key == 'd' || key == OF_KEY_RIGHT)
		pos.x = pos.x + CAMERA_VIT;
	else if(key == ' ')
		pos.y = pos.y + CAMERA_VIT;
	else if(key == OF_KEY_CONTROL)
		pos.y = pos.y - CAMERA_VIT;
	cam.setPosition(pos);*/
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch (key)
	{
	case OF_KEY_ALT:
		CAMERA_TRACKING != CAMERA_TRACKING;
	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (fp_cam_enabled){
		fp_cam.mouseMoved(x, y);
	}
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
