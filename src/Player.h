#pragma once

#include "ofMain.h"

class Player
{
public:
	void setup(ofVec3f playerPosition, ofVec3f playerLookAt);
	void draw();
	void keyPressed(int key);
	void mouseMoved(int x, int y);
	
	void resetPlayer(ofVec3f playerPosition, ofVec3f playerLookAt);
	const float getSpeed() const; //speed
	const float getPitch() const; //up and down (x axis)
	const float getYaw() const; //left and right (y axis)
	const float getRoll() const; //roll (z axis)
	ofVec3f getOrientation() const;
	ofVec3f getPosition() const;
	ofNode* getPlayerNode();

private:
	ofNode m_player;

	float m_speed;
	float m_pitch;
	float m_yaw;
	float m_roll;

	static const int PLAYER_MAX_SPEED = 16;
	static const int PLAYER_ACCELERATION = 2;

};

