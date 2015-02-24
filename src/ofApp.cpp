#include <string>
#include "ofApp.h"
#include "guiVoyageurEspace.h"
#include "Soleil.h"
#include "Terre.h"
#include "Lune.h"
#include "CubeMap.h"
#include "modele3D.h" // Modèle 3D

std::string XN = "test_left2.png";
std::string XP = "test_right1.png";
std::string YN = "test_bottom4.png";
std::string YP = "test_top3.png";
std::string ZN = "test_back6.png";
std::string ZP = "test_front5.png";

guiVoyageurEspace gui;
Soleil sun;
Terre earth;
Lune moon;
ofLight light;
CubeMap cubemap;
ofCamera cam;

bool CAMERA_TRACKING = false;
int CAMERA_VIT = 5;

float SENSITIVITY = 0.1;
//Modèle 3D
modele3D *vaisseau;

//--------------------------------------------------------------
void ofApp::setup(){

	gui = *new guiVoyageurEspace();

	gui.setup();
	sun.setup(gui);
	earth.setup(gui);
	moon.setup(gui);
	//cubemap.setup(XP,YP,ZP,XN,YN,ZN);
	//Modèle 3D
	vaisseau = new modele3D("turbosonic.obj", (float)ofGetWidth()*0.75, (float)ofGetHeight()*0.65, 0, 0.5, 0.5, 0.5);
	vaisseau->setup();
	ofBackground(ofColor::gray);

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
	ofBackground(ofColor::gray);
	//cubemap.draw(cam);
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

//Modèle 3D
	vaisseau->draw();
	cam.end();
	ofDisableLighting();
	ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 15);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	ofVec3f pos = cam.getPosition();
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
	cam.setPosition(pos);
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

//ofVec3f rotateCamera(float angle, ofVec3f rotation, ofVec3f cam_orientation)
//{
//	ofQuaternion temp(
//		rotation.x * sin(angle/2),
//		rotation.y * sin(angle/2),
//		rotation.z * sin(angle/2),
//		cos(angle/2)
//	);
//
//	ofQuaternion quat_view(
//		cam_orientation.x,
//		cam_orientation.y,
//		cam_orientation.z,
//		0
//	);
//
//	ofQuaternion result = (temp * quat_view)*temp.conj();
//	
//	return ofVec3f(result.x(),result.y(),result.z());
//}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	//ofVec3f pos = cam.getPosition();
	//ofVec3f orient = cam.getOrientationEuler();
	//ofVec3f up = cam.getUpDir();

	//int middle_x = ofGetWidth() /2;
	//int middle_y = ofGetHeight() /2;

	//int centered_x = x - middle_x;
	//int centered_y = middle_y - y;
	//ofLog(OF_LOG_NOTICE,"x,y : (%d,%d)",centered_x,centered_y);
	//ofVec3f mouse_dir(0);
 //   static double CurrentRotationX = 0.0;

	//// The maximum angle we can look up or down, in radians
	//double maxAngle = 1;

	//// if the mouse hasn't moved, return without doing
	//// anything to our view
	//if(centered_x == 0 && centered_y == 0)
	//	return;

	//// otherwise move the mouse back to the middle of the screen
	//SetCursorPos(ofGetWindowPositionX()+middle_x, ofGetWindowPositionY()+middle_y);

	//mouse_dir.x = centered_x/SENSITIVITY; 
	//mouse_dir.y = centered_y/SENSITIVITY;

 //   CurrentRotationX += mouse_dir.y;
 //
	//// We don't want to rotate up more than one radian, so we cap it.
	//if(CurrentRotationX > 1)
	//{
	//	CurrentRotationX = 1;
	//	return;
	//}
	//// We don't want to rotate down more than one radian, so we cap it.
	//if(CurrentRotationX < -1)
	//{
	//	CurrentRotationX = -1;
	//	return;
	//}
	//else
	//{
	//	// get the axis to rotate around the x-axis. 
	//	ofVec3f axis = (orient - pos).cross(up).normalize();
	//	// Rotate around the y axis
	//	orient = rotateCamera(mouse_dir.y, axis, orient);
	//	// Rotate around the x axis
	//	orient = rotateCamera(mouse_dir.x, axis, orient);
	//	
	//	ofLog(OF_LOG_NOTICE, "toto");
	//	cam.lookAt(orient, up);
	//}
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
