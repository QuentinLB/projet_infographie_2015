#pragma once
#include "guiVoyageurEspace.h"
#include "IElementDessinable.h"

class Soleil : public IElementDessinable
{
public:
	void setup(guiVoyageurEspace* gui);
	void draw();
private:
	ofSpherePrimitive model;
	ofImage texture;
	ofMaterial materiel;
	guiVoyageurEspace* _gui;
};

