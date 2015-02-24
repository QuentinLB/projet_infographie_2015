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

class guiVoyageurEspace 
{
public:
	void setup();
	void draw();

	float getSunRadius();
	int getSunResolution();
	ofColor getSunColor();
	ofVec3f getSunCenter();
	float getSunRotation();

	ofVec3f getCamLocation();

	float getEarthRadius();
	int getEarthResolution();
	float getEarthRotation();
	float getEarthOrbite();
	float getEarthOrbiteRadius();

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
	// camera
	ofxVec3Slider camLoc;
	
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