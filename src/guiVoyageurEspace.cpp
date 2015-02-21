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
	guiSun.add(sunColor.setup("couleur", ofColor(55, 200, 200, 255), ofColor(0, 0, 0, 0), ofColor(255, 255, 255, 255)));
	guiSun.add(sunResolution.setup("resolution", 45, 2, 99));
	guiSun.add(sunSpeed.setup("vitesse", 20, 0.0, 1.0));


	guiMeteor.setup("Meteor");
	guiMeteor.add(meteorNumber.setup("nombre", 20, 0, 99));
	guiMeteor.add(meteorRadius.setup("rayon", 15, 0.01, 50));
	guiMeteor.add(meteorResolution.setup("resolution", 25, 2, 99));
	guiMeteor.add(meteorSpeed.setup("vitesse", 20, 0.0, 1.0));
}

/**
*\fonction draw()
*\brief affiche les interfaces utilisateur et leurs contenus. La fonction doit etre appeler lors du draw de openframework
*/
void guiVoyageurEspace::draw()
{
	guiSun.setPosition(ofPoint(0, 0)); //reposition pour eviter le d/placement de l'utilisateur
	guiSun.draw();

	guiMeteor.setPosition(ofPoint(0, 275));
	guiMeteor.draw();
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
*\fonction getSunSpeed()
*\brief retourne la vitesse de rotation afficher a l'interface
*\return float (0.0-1.0)
*/
float guiVoyageurEspace::getSunSpeed()
{
	return sunSpeed;
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

