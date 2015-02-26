/**
*\file firstPersonneCam.h
*\author Alexandre Chouinard
*\brief declaration de la class firstPersoneCam qui gere la camera premiere personne
*\date 17/02/2015
*\version 1.0
*/

#ifndef FIRST_PERSPECTIVE_CAM
#define FIRST_PERSPECTIVE_CAM

#include "ofMain.h"

class PerspectiveCam
{
public:
	void setup();
	void draw();
	void begin();
	void end();

	ofVec3f getPosition();

private :

	ofCamera cam;

};

#endif

