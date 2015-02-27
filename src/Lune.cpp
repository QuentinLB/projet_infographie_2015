#include "Lune.h"

void Lune::setup(guiVoyageurEspace* gui){
	_gui = gui;
	model.setRadius(_gui->getMoonRadius());
	model.setResolution(_gui->getMoonResolution());

	materiel.setSpecularColor(0);

	texture.loadImage("texture_moon.jpg");
	angleOrbite = 0;
}

void Lune::draw(){
	if (angleOrbite >= 365){
		angleOrbite -= 365;
	}
	
	ofPushMatrix();
	texture.getTextureReference().bind();
	model.mapTexCoordsFromTexture(texture.getTextureReference());

	materiel.begin();

	model.setRadius(_gui->getMoonRadius());
	
	model.setResolution(_gui->getMoonResolution());

	model.rotate(_gui->getMoonRotation(), 0, 1, 0);

	ofVec3f p(0, 0, _gui->getMoonOrbiteRadius());
	p += _gui->getEarthPosition();
	model.setPosition(p);
	model.rotateAround(angleOrbite, ofVec3f(0, 1, 0), _gui->getEarthPosition());

	model.draw();

	materiel.end();

	texture.getTextureReference().unbind();
	ofPopMatrix();
	angleOrbite += _gui->getMoonOrbite();
}
