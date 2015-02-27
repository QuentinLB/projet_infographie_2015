#pragma once
#include "guiVoyageurEspace.h"
#include "IElementDessinable.h"

class Lune : public IElementDessinable
{
public:
	void setup(guiVoyageurEspace* gui);
	void draw();
private:
	guiVoyageurEspace* _gui;
	ofSpherePrimitive model;
	ofImage texture;
	ofMaterial materiel;
	float angleOrbite;
};

