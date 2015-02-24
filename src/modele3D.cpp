/**
*\file modele3D.cpp
*\author Ghislain Cléris
*\brief Definition de la classe modele3D qui permet de générer un objet 3D à partir d'un fichier modèle importé au format OBJ.
*\date 2015/02/22
*\version 1.0
*/

#include "modele3D.h"

modele3D::modele3D(std::string pathFile, float posX, float posY, float posZ, float scaleX, float scaleY, float scaleZ){
	cheminFichier = pathFile;
	mod3DposX = posX;
	mod3DposY = posY;
	mod3DposZ =	posZ;
	mod3DscaleX = scaleX;
	mod3DscaleY = scaleY;
	mod3DscaleZ = scaleZ;
}

void modele3D::setup(){
	model.loadModel(cheminFichier);
	model.setPosition(mod3DposX, mod3DposY, mod3DposZ);
	model.setScale(mod3DscaleX,mod3DscaleY,mod3DscaleZ);
	model.setRotation(0,0, 45, 45,45);
}

void modele3D::update(){
	
}

void modele3D::draw(){
	ofPushMatrix();
	model.drawFaces();
	ofPopMatrix();
}
