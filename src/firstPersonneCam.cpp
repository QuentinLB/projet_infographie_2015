/**
*\file firstPersonneCam.cpp
*\author Alexandre Chouinard
*\brief definition de la class firstPersoneCam qui gere la camera premiere personne
*\date 15/04/2015
*\version 1.0
*/

#include "firstPersonneCam.h"

//setup cam (put in setup())
void firstPersonneCam::setup(ofNode* player)
{
	m_player = player;
	m_camera.setFarClip(10000);
	setCam();
}

//reset the cam
void firstPersonneCam::setCam()
{
	m_camera.setPosition(m_player->getPosition());
	m_camera.setOrientation(m_player->getOrientationEuler());
}

//move the cam ( must be put in draw)
void firstPersonneCam::draw()
{
	ofPushMatrix();
	setCam();
	ofPopMatrix();
}

//for projectio nmatrix put in gening of draw
void firstPersonneCam::begin()
{
	m_camera.begin();
}

//for projectio nmatrix put in gening of draw
void firstPersonneCam::end()
{
	m_camera.end();
}

ofVec3f firstPersonneCam::getPosition()
{
	return m_camera.getPosition();
}
