#include "Terre.h"

float angleOrbite;

void Terre::setup(guiVoyageurEspace gui){
	model.setRadius(gui.getEarthRadius());
	model.setResolution(gui.getEarthResolution());

	materiel.setSpecularColor(0);

	texture.loadImage("texture_earth_clouds.jpg");
	angleOrbite = 0;
}

void Terre::draw(guiVoyageurEspace gui){
	if (angleOrbite >= 365){
		angleOrbite -= 365;
	}
	
	ofPushMatrix();
	texture.getTextureReference().bind();
	model.mapTexCoordsFromTexture(texture.getTextureReference());

	materiel.begin();

	model.setRadius(gui.getEarthRadius());
	
	model.setResolution(gui.getEarthResolution());

	model.rotate(gui.getEarthRotation(), 0, 1, 0);

	ofVec3f p(0, 0, gui.getEarthOrbiteRadius());
	p += gui.getSunCenter();
	model.setPosition(p);
	model.rotateAround(angleOrbite, ofVec3f(0, 1, 0), gui.getSunCenter());

	model.draw();

	materiel.end();

	texture.getTextureReference().unbind();
	ofPopMatrix();
	angleOrbite += gui.getEarthOrbite();
}
