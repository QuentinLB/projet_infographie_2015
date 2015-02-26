/**
*\file firstPersonneCam.cpp
*\author Alexandre Chouinard
*\brief definition de la class firstPersoneCam qui gere la camera premiere personne
*\date 17/02/2015
*\version 1.0
*/

#include "firstPersonneCam.h"

//setup cam (put in setup())
void firstPersonneCam::setup()
{
	resetCam();
	cam.setFarClip(10000);
}

//reset the cam
void firstPersonneCam::resetCam()
{
	camSpeed = 0.0;
	camDirection = ofVec3f(0.0, 0.0, 0.0);
	cam.setPosition(0.0, 0.0, 1000.0);
	cam.setOrientation(ofVec3f(0.0, 0.0, 0.0));
}

//move the cam ( must be put in draw)
void firstPersonneCam::draw()
{
	ofPushMatrix();
	
	cam.rotate(0.5, camDirection.y, 0.0, 0.0); //axe des x
	cam.rotate(0.5, 0.0, camDirection.x, 0.0);//axe des y
	cam.roll(4 * camDirection.z); //axe des z
	cam.dolly(-1 * camSpeed);

	camDirection.z = 0.0;//reset z direction to stop de roll
	
		
	ofPopMatrix();
}

//for projectio nmatrix put in gening of draw
void firstPersonneCam::begin()
{
	cam.begin();
}

//for projectio nmatrix put in gening of draw
void firstPersonneCam::end()
{
	cam.end();
}

float firstPersonneCam::getSpeed()
{
	return camSpeed;
}

ofVec3f firstPersonneCam::getPosition()
{
	return cam.getPosition();
}

//for control (speed + roll) must be put in keypressed()
void firstPersonneCam::keyPressed(int key)
{
	switch (key)
	{
		//roll
	case OF_KEY_LEFT: camDirection.z = 1; break;
	case OF_KEY_RIGHT: camDirection.z = -1; break;

		//acceleration
	case OF_KEY_UP: if (camSpeed < CAM_MAX_SPEED) {
						camSpeed += CAM_ACCELERATION / ofGetFrameRate();
	}
					break;

					//deceleration
	case OF_KEY_DOWN: if (camSpeed > -1 * CAM_MAX_SPEED) {
						  camSpeed -= CAM_ACCELERATION / ofGetFrameRate();
	}
					  break;
	}
}

//for control mouvement (x, y) must be put in mouseMoved()
void firstPersonneCam::mouseMoved(int x, int y)
{
	float midleWinX = ofGetWindowWidth() / 2;
	float midleWinY = ofGetWindowHeight() / 2;

	//controle en x
	if (x < (midleWinX + CAM_DEAD_ZONE) && x >(midleWinX - CAM_DEAD_ZONE))
	{
		camDirection.x = 0.0;
	}
	else if (x < (midleWinX + CAM_CONTROLE_ZONE) && x >(midleWinX - CAM_CONTROLE_ZONE))
	{
		camDirection.x = (x > (midleWinX)) ? -1 : 1;
	}
	else
	{
		camDirection.x = 0;
	}

	//controle en y
	if (y < (midleWinY + CAM_DEAD_ZONE) && y >(midleWinY - CAM_DEAD_ZONE))
	{
		camDirection.y = 0.0;
	}
	else if (y < (midleWinY + CAM_CONTROLE_ZONE) && y >(midleWinY - CAM_CONTROLE_ZONE))
	{
		camDirection.y = (y > midleWinY) ? -1 : 1;
	}
	else
	{
		camDirection.y = 0.0;
	}
}
