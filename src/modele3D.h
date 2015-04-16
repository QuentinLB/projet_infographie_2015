/**
*\file modele3D.h
*\author Ghislain Cléris
*\brief Definition de la classe modele3D qui permet de générer un objet 3D à partir d'un fichier modèle importé au format OBJ.
*\date 2015/02/22
*\version 1.0
*/

#ifndef modele3D_h
#define modele3D_h

#include "ofMain.h"
#include "IElementDessinable.h"
#include "ofxAssimpModelLoader.h" // Addon modèle 3D

class modele3D : public IElementDessinable{

public:
	// Constructeur
	modele3D(std::string pathFile, float posX, float posY, float posZ, float scaleX, float scaleY, float scaleZ);

	//Méthodes
	void setup();
	void update();
	void draw();
	
private:
	//Propriétés
	std::string cheminFichier;
	float mod3DposX;
	float mod3DposY;
	float mod3DposZ;
	float mod3DscaleX;
	float mod3DscaleY;
	float mod3DscaleZ;
	ofxAssimpModelLoader model;
};
#endif
