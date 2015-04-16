/**
*\file firstPersonneCam.h
*\author Alexandre Chouinard
*\brief declaration de la class firstPersoneCam qui gere la camera premiere personne
*\date 15/04/2015
*\version 1.0
*/

#ifndef FIRST_PERSONNE_CAM
#define FIRST_PERSONNE_CAM

#include "ofMain.h"

class firstPersonneCam
{

public:
	void setup(ofNode* player);
	void setCam();
	void draw();
	void begin();
	void end();
	
	ofVec3f getPosition();

private :

	ofCamera m_camera;
	ofNode* m_player;
};

#endif

