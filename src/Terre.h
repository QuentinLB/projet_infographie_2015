#pragma once
#include "guiVoyageurEspace.h"
#include "IElementDessinable.h"

class Terre : public IElementDessinable
{
public:
	void setup(guiVoyageurEspace* gui);
	void draw();
private:
	guiVoyageurEspace* _gui;
	ofSpherePrimitive model;
	ofImage textureMapImage;
	ofTexture textureMap;
	ofImage normalMapImage;
	ofTexture normalMap;
	ofImage diffuseMapImage;
	ofTexture diffuseMap;
	ofMaterial materiel;
	float angleOrbite;
	ofShader shaderDeRelief;
};

