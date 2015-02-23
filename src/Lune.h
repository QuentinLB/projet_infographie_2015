#pragma once
#include "guiVoyageurEspace.h"

class Lune
{
public:
	void setup(guiVoyageurEspace gui);
	void draw(guiVoyageurEspace gui, ofVec3f positionTerre);
private:
	ofSpherePrimitive model;
	ofImage texture;
	ofMaterial materiel;
	float angleOrbite;
};

