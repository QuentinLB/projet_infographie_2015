#include <string>
#include "ofApp.h"
#include "guiVoyageurEspace.h"
#include "GrapheScene.h"
#include "GrapheSceneNode.h"
#include "Soleil.h"
#include "Terre.h"
#include "Lune.h"
#include "CubeMap.h"
#include "modele3D.h"
#include "firstPersonneCam.h"
#include "PerspectiveCam.h"

// CONSTANTES
const std::string ofApp::XN = "cubemap_left2.png";
const std::string ofApp::XP = "cubemap_right1.png";
const std::string ofApp::YN = "cubemap_bottom4.png";
const std::string ofApp::YP = "cubemap_top3.png";
const std::string ofApp::ZN = "cubemap_back6.png";
const std::string ofApp::ZP = "cubemap_front5.png";

//--------------------------------------------------------------
void ofApp::setup(){
	fp_cam_enabled = false;

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

	//Modele 3D
	vaisseau = new modele3D("turbosonic.obj", (float)ofGetWidth()*0.75, (float)ofGetHeight()*0.65, 0, 0.1, 0.1, 0.1);
	((modele3D*)vaisseau)->setup();


	//construction du graphe de scene
	GrapheSceneNode* racine = new GrapheSceneNode(cubemap);

	GrapheSceneNode* sun_node = new GrapheSceneNode(sun);
	sun_node->addDescendant(new GrapheSceneNode(earth));
	sun_node->addDescendant(new GrapheSceneNode(moon));

	racine->addDescendant(sun_node);
	racine->addDescendant(new GrapheSceneNode(vaisseau));

	graphe_scene = new GrapheScene(racine);

	// Commande OpenGL qui utilise l'information de profondeur pour l'occlusion
	// au lieu de dessiner des objets qui sont cachées par d'autres par dessus
	ofEnableDepthTest(); 

	fp_cam.setup();
	pers_cam.setup();
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

	ofEnableLighting();
	light.enable();
	light.setPosition(((guiVoyageurEspace*) gui)->getSunCenter());
	light.setDiffuseColor(((guiVoyageurEspace*) gui)->getSunColor());

	graphe_scene->render();

	if (fp_cam_enabled){
		fp_cam.end();
	}
	else{
		pers_cam.end();
	}
	ofDisableLighting();
	ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 15);
}

void ofApp::exit()
{
	delete graphe_scene;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_TAB){
		fp_cam_enabled = !fp_cam_enabled;
		//gui_node->switchVisibility();
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