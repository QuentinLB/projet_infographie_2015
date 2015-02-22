#pragma once
#include "guiVoyageurEspace.h"

class Soleil
{
public:
	void setup(guiVoyageurEspace gui);
	void draw(guiVoyageurEspace gui);
private:
	ofSpherePrimitive model;
	ofImage texture;
	ofMaterial materiel;
};

