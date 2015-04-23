/**
*\file Player.cpp
*\author Alexandre Chouinard
*\brief definition de la class Player qui gere les mouvement du joueur
*\date 15/04/2015
*\version 1.0
*/

#include "Player.h"

//setup du joueur
void Player::setup(ofVec3f playerPosition, ofVec3f playerLookAt)
{
	resetPlayer(playerPosition, playerLookAt);
}

//reset le joueur
void Player::resetPlayer(ofVec3f playerPosition, ofVec3f playerLookAt)
{
	m_speed = 0;
	m_yaw = 0;
	m_pitch = 0;
	m_roll = 0;
	m_player.setPosition(playerPosition);
	m_player.lookAt(playerLookAt, ofVec3f(0, 1, 0));
}

//dessine le joueur
void Player::draw()
{
	ofPushMatrix();

	m_player.rotate(m_yaw, 1.0, 0.0, 0.0); //yaw
	m_player.rotate(m_pitch, 0.0, 1.0, 0.0);//pitch
	m_player.roll(2 * m_roll); //roll
	m_player.dolly(-1 * m_speed); //speed

	ofPopMatrix();

	m_roll = 0;
}


//gere les entrers
void Player::keyPressed(int key)
{
	switch (key)
	{
		//roll
	//case OF_KEY_LEFT: m_roll = 1; break;
	//case OF_KEY_RIGHT: m_roll = -1; break;

		//acceleration
	case OF_KEY_UP: if (m_speed < Player::PLAYER_MAX_SPEED) {
						m_speed += Player::PLAYER_ACCELERATION / ofGetFrameRate();
	}
					break;

					//deceleration
	case OF_KEY_DOWN: if (m_speed > -1 * Player::PLAYER_MAX_SPEED) {
						  m_speed -= (2 * Player::PLAYER_ACCELERATION) / ofGetFrameRate(); //deceleration plus rapide
	}
					  break;
	}
}

//for control mouvement (x, y) must be put in mouseMoved()
void Player::mouseMoved(int x, int y)
{
	float midleWinX = ofGetWindowWidth() / 2;
	float midleWinY = ofGetWindowHeight() / 2;

	//controle en pitch
	if (x < midleWinX)
	{
		m_pitch = (midleWinX - x) / midleWinX;
	}
	else if (x > midleWinX)
	{
		m_pitch = -1 * ((x - midleWinX) / midleWinX);
	}
	else if (x = midleWinX)
	{
		m_pitch = 0;
	}

	//controle en yaw
	if (y < midleWinY)
	{
		m_yaw = (midleWinY - y) / midleWinY;
	}
	else if (y > midleWinY)
	{
		m_yaw = -1 * ((y - midleWinY) / midleWinY);
	}
	else if (y = midleWinY)
	{
		m_yaw = 0;
	}

}

const float Player::getSpeed() const
{
	return m_speed;
}

const float Player::getPitch() const
{
	return m_pitch;
}
const float Player::getYaw() const
{
	return m_yaw;
}
const float Player::getRoll() const
{
	return m_roll;
}
ofVec3f Player::getOrientation() const
{
	return m_player.getOrientationEuler();
}
ofVec3f Player::getPosition() const
{
	return m_player.getPosition();
}
ofNode* Player::getPlayerNode()
{
	return &m_player;
}
