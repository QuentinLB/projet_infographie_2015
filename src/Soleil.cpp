#include "Soleil.h"


void Soleil::setup(guiVoyageurEspace* gui){
	_gui = gui;
	model.setRadius(gui->getSunRadius());
	model.setPosition(gui->getSunCenter());
	model.setResolution(gui->getSunResolution());

	materiel.setEmissiveColor(gui->getSunColor());
	texture.loadImage("texture_sun.jpg");
}

void Soleil::draw(){
	ofPushMatrix();
	texture.getTextureReference().bind();
	model.mapTexCoordsFromTexture(texture.getTextureReference());

	materiel.begin();

	model.setRadius(_gui->getSunRadius());
	model.setPosition(_gui->getSunCenter());
	model.setResolution(_gui->getSunResolution());

	materiel.setEmissiveColor(_gui->getSunColor());
	model.rotate(_gui->getSunRotation(), 0.0, 0.1, 0);


	model.draw();

	materiel.end();

	texture.getTextureReference().unbind();
	ofPopMatrix();
}
