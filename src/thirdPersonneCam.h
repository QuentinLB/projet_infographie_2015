/**
*\file thirdPersonneCam.h
*\author Alexandre Chouinard
*\brief declaration de la class firstPersoneCam qui gere la camera premiere personne
*\date 15/04/2015
*\version 1.0
*/

#ifndef THIRD_PERSONNE_CAM
#define THIRD_PERSONNE_CAM

#include "ofMain.h"

class thirdPersonneCam
{

public:
	void setup(ofNode* player);
	void setCam();
	void draw();
	void begin();
	void end();
	//void mouseRoll(float x);
	void mouseDragged(int x, int y, int button);

	ofVec3f getPosition();
	const float getDistancePlayer()const;
	const float getYaw()const;
	const float getPitch()const;
	const float getZoom()const;

private:

	ofCamera m_camera;
	ofNode* m_player;
	float m_distancePlayer;
	float m_yawAngle;
	float m_pitch;
	float m_zoom;

	float calculHorizontalD();
	float calculVerticalD();
	ofVec3f calculCameraPosition(float xDistance, float yDistance);
};

#endif

