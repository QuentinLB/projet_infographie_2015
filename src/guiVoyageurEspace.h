/**
*\file guiVoyageur.h
*\author Alexandre Chouinard
*\brief declaration de la class guiVoyageurEspace qui gere l'interface de l'application
*\date 17/02/2015
*\version 1.0
*/

#ifndef GUI_VOYAGEUR_ESPACE
#define GUI_VOYAGEUR_ESPACE

#include "ofMain.h"
#include "ofxGui.h"
#include "IElementDessinable.h"

class guiVoyageurEspace : public IElementDessinable
{
public:
	void setup();
	void draw();

	float getSunRadius();
	int getSunResolution();
	ofColor getSunColor();
	ofVec3f getSunCenter();
	float getSunRotation();

	float getEarthRadius();
	int getEarthResolution();
	float getEarthRotation();
	float getEarthOrbite();
	float getEarthOrbiteRadius();
	ofVec3f getEarthPosition();
	void setEarthPosition(ofVec3f pos);

	float getMoonRadius();
	int getMoonResolution();
	float getMoonRotation();
	float getMoonOrbite();
	float getMoonOrbiteRadius();

	int getMeteorNumber();
	float getMeteorRadius();
	int getMeteorResolution();
	float getMeteorSpeed();

private:
	
	//sun
	ofxFloatSlider sunRadius;
	ofxIntSlider sunResolution;
	ofxColorSlider sunColor;
	ofxVec3Slider sunCenter;
	ofxFloatSlider sunRotation;

	//terre
	ofxFloatSlider earthRadius;
	ofxIntSlider earthResolution;
	ofxFloatSlider earthRotation;
	ofxFloatSlider earthOrbite;
	ofxFloatSlider earthOrbiteRadius;
	ofVec3f earthPosition;

	//lune
	ofxFloatSlider moonRadius;
	ofxIntSlider moonResolution;
	ofxFloatSlider moonRotation;
	ofxFloatSlider moonOrbite;
	ofxFloatSlider moonOrbiteRadius;

	//meteor
	ofxIntSlider meteorNumber;
	ofxFloatSlider meteorRadius;
	ofxIntSlider meteorResolution;
	ofxFloatSlider meteorSpeed;

	ofxPanel guiCam;
	ofxPanel guiSun;
	ofxPanel guiEarth;
	ofxPanel guiMoon;
	ofxPanel guiMeteor;
};

#endif