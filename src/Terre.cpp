#include "Terre.h"

void Terre::setup(guiVoyageurEspace* gui){
	_gui = gui;
	model.setRadius(gui->getEarthRadius());
	model.setResolution(gui->getEarthResolution());

	materiel.setSpecularColor(0);

	texture.loadImage("texture_earth_clouds.jpg");
	angleOrbite = 0;
}

void Terre::draw(){
	if (angleOrbite >= 365){
		angleOrbite -= 365;
	}
	
	ofPushMatrix();
	texture.getTextureReference().bind();
	model.mapTexCoordsFromTexture(texture.getTextureReference());

	materiel.begin();

	model.setRadius(_gui->getEarthRadius());
	
	model.setResolution(_gui->getEarthResolution());

	model.rotate(_gui->getEarthRotation(), 0, 1, 0);

	ofVec3f p(0, 0, _gui->getEarthOrbiteRadius());
	p += _gui->getSunCenter();
	model.setPosition(p);
	model.rotateAround(angleOrbite, ofVec3f(0, 1, 0), _gui->getSunCenter());

	model.draw();

	materiel.end();

	texture.getTextureReference().unbind();
	ofPopMatrix();
	angleOrbite += _gui->getEarthOrbite();

	_gui->setEarthPosition(model.getPosition());
}
