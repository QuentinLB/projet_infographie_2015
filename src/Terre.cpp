#include "Terre.h"

void Terre::setup(guiVoyageurEspace* gui){
	shaderDeRelief.load("relief.vert", "relief.frag");

	_gui = gui;
	model.setRadius(gui->getEarthRadius());
	model.setResolution(gui->getEarthResolution());

	materiel.setSpecularColor(0);

	textureMapImage.loadImage("2_no_clouds_8k.jpg");
	textureMap.allocate(1944, 972, GL_RGB, false);
	textureMap.loadData(textureMapImage.getPixels(), 1944, 972, GL_RGB);

	normalMapImage.loadImage("earth_normalmap.jpg");
	normalMap.allocate(1944, 972, GL_RGB, false);
	normalMap.loadData(normalMapImage.getPixels(), 1944, 972, GL_RGB);

	diffuseMapImage.loadImage("earth-night.jpg");
	diffuseMap.allocate(1944, 972, GL_RGB, false);
	diffuseMap.loadData(diffuseMapImage.getPixels(), 1944, 972, GL_RGB);

	angleOrbite = 0;
}

void Terre::draw(){
	if (angleOrbite >= 365){
		angleOrbite -= 365;
	}

	ofPushMatrix();
	shaderDeRelief.begin();
	shaderDeRelief.setUniformTexture("textureMap", textureMap, 0);
	shaderDeRelief.setUniformTexture("normalMap", normalMap, 1);
	shaderDeRelief.setUniformTexture("diffuseMap", diffuseMap, 2);
	shaderDeRelief.setUniform1f("alpha", 1);

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

	shaderDeRelief.end();

	ofPopMatrix();
	angleOrbite += _gui->getEarthOrbite();

	_gui->setEarthPosition(model.getPosition());
}
