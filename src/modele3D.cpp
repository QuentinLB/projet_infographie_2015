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
	mod3DposZ = posZ;
	mod3DscaleX = scaleX;
	mod3DscaleY = scaleY;
	mod3DscaleZ = scaleZ;
	mod3DrotationX = 0;
	mod3DrotationY = 0;
	mod3DrotationZ = 0.0;
}
void modele3D::setup(){
	model.loadModel(cheminFichier);
	setModel();
	model.setScale(mod3DscaleX,mod3DscaleY,mod3DscaleZ);
}

void modele3D::setElement(ofNode* aNode)
{
	ofVec3f pos = aNode->getGlobalPosition();

	mod3DposX = pos.x;
	mod3DposY = pos.y;
	mod3DposZ = pos.z;

	
	ofVec3f orientation = aNode->getOrientationEuler();
	mod3DrotationX = orientation.x;//x
	mod3DrotationY = orientation.y;//z
	mod3DrotationZ = orientation.z ;//y
	
	//std::cout << "orientationX : " << orientation.x << endl;
	//std::cout << "orientationY : " << orientation.y << endl;
	//std::cout << "orientationZ : " << orientation.z << endl;
}

void modele3D::update(){
	
}

void modele3D::draw(){
	ofPushMatrix();
	setModel();
	model.drawFaces();
	ofPopMatrix();
}

void modele3D::setModel()
{
	model.setPosition(mod3DposX, mod3DposY, mod3DposZ);
	//model.setRotation(0, , -1, 0, 0); //x		le modele n'est pas sur la bonne base ortho normal
	//model.setRotation(1, 180, 0, 1, 0); //z

	model.setRotation(2, mod3DrotationX + 60, -1, 0, 0); //x 
	model.setRotation(3, mod3DrotationY, 0, 0, -1); //y
	model.setRotation(4, 180, 0, 1, 0); //z
}
