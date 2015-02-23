#include "Lune.h"

void Lune::setup(guiVoyageurEspace gui){
	model.setRadius(gui.getMoonRadius());
	model.setResolution(gui.getMoonResolution());

	materiel.setSpecularColor(0);

	texture.loadImage("texture_moon.jpg");
	angleOrbite = 0;
}

void Lune::draw(guiVoyageurEspace gui, ofVec3f positionTerre){
	if (angleOrbite >= 365){
		angleOrbite -= 365;
	}
	
	ofPushMatrix();
	texture.getTextureReference().bind();
	model.mapTexCoordsFromTexture(texture.getTextureReference());

	materiel.begin();

	model.setRadius(gui.getMoonRadius());
	
	model.setResolution(gui.getMoonResolution());

	model.rotate(gui.getMoonRotation(), 0, 1, 0);

	ofVec3f p(0, 0, gui.getMoonOrbiteRadius());
	p += positionTerre;
	model.setPosition(p);
	model.rotateAround(angleOrbite, ofVec3f(0, 1, 0), positionTerre);

	model.draw();

	materiel.end();

	texture.getTextureReference().unbind();
	ofPopMatrix();
	angleOrbite += gui.getMoonOrbite();
}
