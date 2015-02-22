/**
*\file guiVoyageur.cpp
*\author Alexandre Chouinard
*\brief definition de la class guiVoyageurEspace qui gere l'interface de l'application
*\date 17/02/2015
*\version 1.0
*/


#include "guiVoyageurEspace.h"

/**
*\fonction setup()
*\brief initialise les interfaces utilisateur et leurs contenus. La fonction doit etre appeler lors du setup de openframework
*/
void guiVoyageurEspace::setup()
{
	guiSun.setup("Soleil");
	guiSun.add(sunRadius.setup("rayon", 100, 10, 300)); //rayon du soleil default, min, max
	guiSun.add(sunCenter.setup("position", ofVec3f(ofGetWidth()*.5, ofGetHeight()*.5, 100.0f), ofVec3f(0.0f, 0.0f, 0.0f), ofVec3f(ofGetWidth(), ofGetHeight(), 500.0f)));
	guiSun.add(sunColor.setup("couleur", ofColor(255, 255, 255, 255), ofColor(0, 0, 0, 0), ofColor(255, 255, 255, 255)));
	guiSun.add(sunResolution.setup("resolution", 45, 2, 99));
	guiSun.add(sunRotation.setup("Rotation", 0.20, 0.0, 1.0));

	guiEarth.setup("Terre");
	guiEarth.add(earthRadius.setup("rayon", 20, 10, 300)); //rayon du soleil default, min, max
	guiEarth.add(earthResolution.setup("resolution", 45, 2, 99));
	guiEarth.add(earthRotation.setup("Rotation", 0.10, 0.0, 1.0));
	guiEarth.add(earthOrbite.setup("vitesse d'Orbite", 0.20, 0.0, 10.0));
	guiEarth.add(earthOrbiteRadius.setup("rayon d'Orbite", 150, 10, 300));

	guiCam.setup("Camera");
	guiCam.add(camLoc.setup("position", ofVec3f(ofGetWidth()*.5, ofGetHeight()*.75, 500.0f), ofVec3f(0.0f, 0.0f, 0.0f), ofVec3f(ofGetWidth(), ofGetHeight(), 500.0f)));

	guiMeteor.setup("Meteor");
	guiMeteor.add(meteorNumber.setup("nombre", 20, 0, 99));
	guiMeteor.add(meteorRadius.setup("rayon", 15, 0.01, 50));
	guiMeteor.add(meteorResolution.setup("resolution", 25, 2, 99));
	guiMeteor.add(meteorSpeed.setup("vitesse", 0.20, 0.0, 1.0));
}

/**
*\fonction draw()
*\brief affiche les interfaces utilisateur et leurs contenus. La fonction doit etre appeler lors du draw de openframework
*/
void guiVoyageurEspace::draw()
{
	guiSun.setPosition(ofPoint(0, 0)); //reposition pour eviter le d/placement de l'utilisateur
	guiSun.draw();

	guiEarth.setPosition(ofPoint(0, 275)); //reposition pour eviter le d/placement de l'utilisateur
	guiEarth.draw();

	guiCam.setPosition(ofPoint(0, 400)); //reposition pour eviter le d/placement de l'utilisateur
	guiCam.draw();

	guiMeteor.setPosition(ofPoint(0, 550));
	guiMeteor.draw();
}

/**
*\fonction getCamLocation()
*\brief retourne le vecteur correspondant au centre afficher a l'interface
*\return ofVec3f (float x, float y, float z)
*/
ofVec3f guiVoyageurEspace::getCamLocation()
{
	return camLoc;
}

/**
*\fonction getSunRadius()
*\brief retourne le rayon afficher a l'interface
*\return float (10-300)
*/
float guiVoyageurEspace::getSunRadius()
{
	return sunRadius;
}

/**
*\fonction getSunResolution()
*\brief retourne la resolution afficher a l'interface
*\return integer (2-99)
*/
int guiVoyageurEspace::getSunResolution()
{
	return sunResolution;

}

/**
*\fonction getSunColor()
*\brief retourne la couleur afficher a l'interface
*\return ofColor (int r,int g,int b,int a)
*/
ofColor guiVoyageurEspace::getSunColor()
{
	return sunColor;
}

/**
*\fonction getSunCenter()
*\brief retourne le vecteur correspondant au centre afficher a l'interface
*\return ofVec3f (float x, float y, float z)
*/
ofVec3f guiVoyageurEspace::getSunCenter()
{
	return sunCenter;
}

/**
*\fonction getSunRotation()
*\brief retourne la vitesse de rotation afficher a l'interface
*\return float (0.0-1.0)
*/
float guiVoyageurEspace::getSunRotation()
{
	return sunRotation;
}

/**
*\fonction getSunRadius()
*\brief retourne le rayon afficher a l'interface
*\return float (10-300)
*/
float guiVoyageurEspace::getEarthRadius()
{
	return earthRadius;
}

/**
*\fonction getSunResolution()
*\brief retourne la resolution afficher a l'interface
*\return integer (2-99)
*/
int guiVoyageurEspace::getEarthResolution()
{
	return earthResolution;

}

/**
*\fonction getEarthRotation()
*\brief retourne la vitesse de rotation afficher a l'interface
*\return float (0.0-1.0)
*/
float guiVoyageurEspace::getEarthRotation()
{
	return earthRotation;
}

/**
*\fonction getEarthOrbite()
*\brief retourne la vitesse d'orbite avec le soleil affiche a l'interface
*\return float (0.0-1.0)
*/
float guiVoyageurEspace::getEarthOrbite()
{
	return earthOrbite;
}

/**
*\fonction getEarthOrbite()
*\brief retourne le rayon d'orbite avec le soleil affiche a l'interface
*\return float (0.0-1.0)
*/
float guiVoyageurEspace::getEarthOrbiteRadius()
{
	return earthOrbiteRadius;
}

/**
*\fonction getMeteorNumber()
*\brief retourne le nombre de meteor afficher a l'interface
*\return int (0-99)
*/
int guiVoyageurEspace::getMeteorNumber()
{
	return meteorNumber;
}

/**
*\fonction getMeteorRadius()
*\brief retourne le rayon afficher a l'interface
*\return float (0.1, 50)
*/
float guiVoyageurEspace::getMeteorRadius()
{
	return meteorRadius;
}

/**
*\fonction getMeteorResolution()
*\brief retourne le rayon afficher a l'interface
*\return int (2-99)
*/
int guiVoyageurEspace::getMeteorResolution()
{
	return meteorResolution;
}

/**
*\fonction getMeteorSpeed()
*\brief retourne la vitesse afficher a l'interface
*\return float (0.0-1.0)
*/
float guiVoyageurEspace::getMeteorSpeed()
{
	return meteorSpeed;
}

