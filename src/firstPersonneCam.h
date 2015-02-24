/**
*\file firstPersonneCam.h
*\author Alexandre Chouinard
*\brief declaration de la class firstPersoneCam qui gere la camera premiere personne
*\date 17/02/2015
*\version 1.0
*/

#ifndef FIRST_PERSONNE_CAM
#define FIRST_PERSONNE_CAM

#include "ofMain.h"

const float CAM_MAX_SPEED = 15.0;
const float CAM_ACCELERATION = 1.5;
const float CAM_CONTROLE_ZONE = 450;
const float CAM_DEAD_ZONE = 50;

class firstPersonneCam
{
public:
	void setup();
	void resetCam();
	void draw();
	void begin();
	void end();
	void keyPressed(int key);
	void mouseMoved(int x, int y);

	float getSpeed();
	ofVec3f getPosition();

private :

	ofCamera cam;
	ofVec3f camDirection;
	float camSpeed;

};

#endif

