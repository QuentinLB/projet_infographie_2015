/**
*\file firstPersonneCam.cpp
*\author Alexandre Chouinard
*\brief definition de la class firstPersoneCam qui gere la camera premiere personne
*\date 17/02/2015
*\version 1.0
*/

#include "PerspectiveCam.h"

//setup cam (put in setup())
void PerspectiveCam::setup()
{
	cam.setFarClip(10000);
}

//move the cam ( must be put in draw)
void PerspectiveCam::draw()
{
	ofPushMatrix();
	
	ofRectangle orientedViewport = ofGetNativeViewport();
	float eyeX = ofGetWidth() / 2;
	float eyeY = ofGetHeight() / 2;


	cam.setPosition(ofVec3f(ofGetWidth()*.5, ofGetHeight()*.75, 500.0f));
	cam.lookAt(ofVec3f(ofGetWidth()*.5, ofGetHeight()*.5, 0), ofVec3f(0, 1, 0));
		
	ofPopMatrix();
}

//for projectio nmatrix put in gening of draw
void PerspectiveCam::begin()
{
	cam.begin();
}

//for projectio nmatrix put in gening of draw
void PerspectiveCam::end()
{
	cam.end();
}

ofVec3f PerspectiveCam::getPosition()
{
	return cam.getPosition();
}

