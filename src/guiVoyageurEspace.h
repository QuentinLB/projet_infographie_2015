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
	float getSunSpeed();

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
	ofxFloatSlider sunSpeed;

	//meteor
	ofxIntSlider meteorNumber;
	ofxFloatSlider meteorRadius;
	ofxIntSlider meteorResolution;
	ofxFloatSlider meteorSpeed;

	ofxPanel guiSun;
	ofxPanel guiMeteor;
};

#endif