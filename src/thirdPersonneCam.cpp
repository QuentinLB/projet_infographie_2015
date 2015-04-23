/**
*\file thirdPersonneCam.cpp
*\author Alexandre Chouinard
*\brief definition de la class firstPersoneCam qui gere la camera premiere personne
*\date 15/04/2015
*\version 1.0
*/

#include "thirdPersonneCam.h"

//setup cam (put in setup())
void thirdPersonneCam::setup(ofNode* player)
{
	m_player = player;
	m_camera.setFarClip(10000);

	m_distancePlayer = 100;
	m_pitch = 40;
	m_yawAngle = 0;
	m_zoom = 1;
	setCam();
}

//reset the cam
void thirdPersonneCam::setCam()
{
	m_camera.setPosition(calculCameraPosition(calculHorizontalD(), calculVerticalD()));
	//m_camera.setOrientation(m_player->getOrientationEuler());
	m_camera.lookAt(*m_player);
}

//move the cam ( must be put in draw)
void thirdPersonneCam::draw()
{
	ofPushMatrix();
	setCam();
	ofPopMatrix();
}

//for projectio nmatrix put in gening of draw
void thirdPersonneCam::begin()
{
	m_camera.begin();
}

//for projectio nmatrix put in gening of draw
void thirdPersonneCam::end()
{
	m_camera.end();
}

/*void thirdPersonneCam::mouseRoll(float x)
{
	m_zoom = x * 0.1;
	m_distancePlayer += m_zoom;
}*/

void thirdPersonneCam::mouseDragged(int x, int y, int button)
{
	//contole non efficace doit etre mis dans mouseMouve mais prendre en consideeration le bouton 2 de la sourie
	/*if (button == 2) //right mouse presse
	{
		float midleWinX = ofGetWindowWidth() / 2;
		float midleWinY = ofGetWindowHeight() / 2;
		float difAngleX = 0;
		float difAngleY = 0;

		//controle en pitch
		if (x < midleWinX)
		{
			if (m_yawAngle < 90) { difAngleX = ((midleWinX - x) / midleWinX); }
		}
		else if (x > midleWinX)
		{
			if (m_yawAngle > -90)  { difAngleX = (-1 * ((x - midleWinX) / midleWinX)); }
		}

		//controle en yaw
		if (y < midleWinY)
		{
			if (m_pitch < 90) { difAngleY = ((midleWinY - y) / midleWinY); }
		}
		else if (y > midleWinY)
		{
			if (m_pitch > -90) { difAngleY = (-1 * ((y - midleWinY) / midleWinY)); }
		}

		m_yawAngle += difAngleX;
		m_pitch += difAngleY;

	}*/
}

float thirdPersonneCam::calculHorizontalD()
{
	float angleX = -1*(m_player->getOrientationEuler().x);
	return m_distancePlayer * cos((m_pitch + angleX)*DEG_TO_RAD);
}

float thirdPersonneCam::calculVerticalD()
{
	float angleX = -1*(m_player->getOrientationEuler().x);
	return m_distancePlayer * sin((m_pitch + angleX)*DEG_TO_RAD);
}

ofVec3f thirdPersonneCam::calculCameraPosition(float xDistance, float yDistance)
{
	ofVec3f position = m_player->getPosition();
	ofVec3f angle = m_player->getOrientationEuler();

	float theta = angle.y + m_yawAngle;
	float offSetX = xDistance * sin(theta*DEG_TO_RAD);
	float offSetZ = xDistance * cos(theta*DEG_TO_RAD);

	position.x += offSetX;
	position.y += yDistance;
	position.z += offSetZ;
	
	return position;
}

const float thirdPersonneCam::getDistancePlayer()const
{
	return m_distancePlayer;
}

const float thirdPersonneCam::getPitch() const
{
	return m_pitch;
}
const float thirdPersonneCam::getYaw() const
{
	return m_yawAngle;
}

const float thirdPersonneCam::getZoom() const
{
	return m_zoom;
}

ofVec3f thirdPersonneCam::getPosition()
{
	return m_camera.getPosition();
}

