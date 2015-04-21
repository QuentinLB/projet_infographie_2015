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
#include "thirdPersonneCam.h"
#include "Player.h"

// CONSTANTES
const std::string ofApp::XN = "cubemap_left2.png";
const std::string ofApp::XP = "cubemap_right1.png";
const std::string ofApp::YN = "cubemap_bottom4.png";
const std::string ofApp::YP = "cubemap_top3.png";
const std::string ofApp::ZN = "cubemap_back6.png";
const std::string ofApp::ZP = "cubemap_front5.png";

int xMeteoreDestination;
int yMeteoreDestination;
int boutonSouris;

//--------------------------------------------------------------
void ofApp::setup(){
	fp_cam_enabled = false;
	td_cam_enabled = false;

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

	player_fp.setup(ofVec3f(ofGetWidth()*.5, ofGetHeight()*.75, 500.0f), ofVec3f(ofGetWidth()*.5, ofGetHeight()*.5, 0));
	fp_cam.setup(player_fp.getPlayerNode());

	player_td.setup(ofVec3f(ofGetWidth()*.5, ofGetHeight()*.75, 600.0f), ofVec3f(ofGetWidth()*.5, ofGetHeight()*.5, 0));
	td_cam.setup(player_td.getPlayerNode());
	vaisseau->setElement(player_td.getPlayerNode());

	projector.setSpotlight(20.0F);
	
	pers_cam.setup();

}

//--------------------------------------------------------------
void ofApp::update(){
	//Déplacement du météor selon la position de pointage de la souris
	meteore.moveTo(xMeteoreDestination, yMeteoreDestination);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::gray);
	if (fp_cam_enabled  || td_cam_enabled)
	{
		ofEnableLighting();
		ofHideCursor();
		if (fp_cam_enabled)
		{
			player_fp.draw();
			fp_cam.draw();
			fp_cam.begin();
		}
		else if (td_cam_enabled)
		{
			player_td.draw();
			td_cam.draw();
			td_cam.begin();
			vaisseau->setElement(player_td.getPlayerNode());
			projector.enable();
			projector.setPosition(player_td.getPosition());
			projector.setOrientation(player_td.getOrientation());
		}
	}
	else{
		gui->draw();
		ofShowCursor();
		pers_cam.draw();
		pers_cam.begin();
	}

	light.enable();
	light.setPosition(((guiVoyageurEspace*) gui)->getSunCenter());
	light.setDiffuseColor(((guiVoyageurEspace*) gui)->getSunColor());

	graphe_scene->render();

	if (fp_cam_enabled){
		fp_cam.end();
	}
	else if (td_cam_enabled){
		td_cam.end();
	}
	else{
		pers_cam.end();
	}
	
	//Dessiner le météore (soit une sphère ou un cone)
	if (boutonSouris == 0)
	{
		meteore.drawIcosphere();
	}
	if (boutonSouris == 2)
	{
		meteore.drawCone();
	}

	ofDisableLighting();
	ofDrawBitmapString("TAB : Camera Perspective	1 : Camera Premiere personne	2 : Camera Troisieme Personne			FPS : ", 10, 15);
	ofDrawBitmapString(ofToString(ofGetFrameRate()), ofGetWidth() - 75, 15);
}

void ofApp::exit()
{
	delete graphe_scene;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == '1'){
		td_cam_enabled = false;
		fp_cam_enabled = true;
		//gui_node->switchVisibility();
	}
	if (key == '2'){
		fp_cam_enabled = false;
		td_cam_enabled= true;
	}
	if (key == OF_KEY_TAB)
	{
		fp_cam_enabled = false;
		td_cam_enabled = false;
	}
	if (fp_cam_enabled){ 
		player_fp.keyPressed(key);
	}
	if (td_cam_enabled){
		player_td.keyPressed(key);
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
		player_fp.mouseMoved(x, y);
	}
	if (td_cam_enabled){
		player_td.mouseMoved(x, y);
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	xMeteoreDestination = x;
	yMeteoreDestination = y;
	boutonSouris = button;
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
