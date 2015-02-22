#include "Soleil.h"


void Soleil::setup(guiVoyageurEspace gui){
	model.setRadius(gui.getSunRadius());
	model.setPosition(gui.getSunCenter());
	model.setResolution(gui.getSunResolution());

	materiel.setEmissiveColor(gui.getSunColor());
	texture.loadImage("texture_sun.jpg");
}

void Soleil::draw(guiVoyageurEspace gui){
	ofPushMatrix();
	texture.getTextureReference().bind();
	model.mapTexCoordsFromTexture(texture.getTextureReference());

	materiel.begin();

	model.setRadius(gui.getSunRadius());
	model.setPosition(gui.getSunCenter());
	model.setResolution(gui.getSunResolution());

	materiel.setEmissiveColor(gui.getSunColor());
	model.rotate(gui.getSunRotation(), 0.0, 0.1, 0);


	model.draw();

	materiel.end();

	texture.getTextureReference().unbind();
	ofPopMatrix();
}
