/**
*\file ReactorParticlel.h
*\author Alexandre Chouinard
*\brief definition de la class ReactorParticlel qui gere les particules de type pingpong appliquer une texture
*					Cette classe s'inspire du code des exemples de gpuExemple de openFramework
*\date 23/04/2015
*\version 1.0
*/

#include "ReactorParticle.h"


/**
*\method setup()
*\bief prepare toute les information pour la texture et les particles
*/
void ReactorParticle::setup(){
	particleSize = 25.0f;  //grandeur pixel
	timeStep = 1 / ofGetFrameRate(); //nb de clacul ici baser sur frame rate
	numParticles = 100; //nombre de particle

	//grandeur de la texture (carrer de preference)
	width = 50;
	height = 50;
	
	//nom du fichier ou sont les shaders
	string shadersFolder = "shaders";

	// loading shaders
	updateShaderPos.load("", shadersFolder + "/posUpdate.frag");// shader pour updater les texture qui sauvegarde la position sur un canal RG 
	updateShaderVel.load("", shadersFolder + "/velUpdate.frag");//  shader pour updater les texture qui sauvegarde la position sur un canal RG 

	// Frag, Vert and Geo shaders pour le processus de rendu de la texture loader
	updateShaderRender.setGeometryInputType(GL_POINTS);
	updateShaderRender.setGeometryOutputType(GL_TRIANGLE_STRIP);
	updateShaderRender.setGeometryOutputCount(6);
	updateShaderRender.load(shadersFolder + "/render.vert", shadersFolder + "/render.frag", shadersFolder + "/render.geom");

	// Set la textures avec les future informations( position and velocity )
	textureRes = (int)sqrt((float)numParticles);
	numParticles = textureRes * textureRes;

	// 1. Fait un tableau avec des valeurs aleatoir pour la position de depart (central)
	float * pos = new float[numParticles * 3];
	for (int x = 0; x < textureRes; x++){
		for (int y = 0; y < textureRes; y++){
			int i = textureRes * y + x;

			pos[i * 3 + 0] = ofRandom(0.495, 0.505);	//position de depart x entre 0-1
			pos[i * 3 + 1] = ofRandom(0.495, 0.505);	//position de depart y entre 0-1
			pos[i * 3 + 2] = 0.0; //pas de z texture 2d
		}
	}

	//envoi les information sur le buffer de particule position
	posParticleBuffer.allocate(textureRes, textureRes, GL_RGB32F);
	posParticleBuffer.src->getTextureReference().loadData(pos, textureRes, textureRes, GL_RGB);
	posParticleBuffer.dst->getTextureReference().loadData(pos, textureRes, textureRes, GL_RGB);
	delete[] pos;    //suppirme le tableau


	// 2. faire un tableau avec la des antier pour la velocity des particles (random pour avoir plusieur direction du centre ver l'exterieur
	float * vel = new float[numParticles * 3];
	for (int i = 0; i < numParticles; i++){
		vel[i * 3 + 0] = ofRandom(-1.0, 1.0);	//propagation x entre -1 et 1 
		vel[i * 3 + 1] = ofRandom(-1.0, 1.0);	//propagation y entre -1 et 1 
		vel[i * 3 + 2] = 0.0; //pas de z texture en 2d
	}
	// envoie les information sur le buffer de particles de velocity
	velParticleBuffer.allocate(textureRes, textureRes, GL_RGB32F);
	velParticleBuffer.src->getTextureReference().loadData(vel, textureRes, textureRes, GL_RGB);
	velParticleBuffer.dst->getTextureReference().loadData(vel, textureRes, textureRes, GL_RGB);
	delete[] vel; //suppirme le tableau

	// load la texture en mermoire et sa resolution
	sparkImg.loadImage("spark.png");
	imgWidth = sparkImg.getWidth();
	imgHeight = sparkImg.getHeight();

	// allocation au bufferRendue
	bufferRendue.allocate(width, height, GL_RGB32F);
	bufferRendue.begin();
	ofClear(0, 0, 0, 255);
	bufferRendue.end();


	//ajoute des vertice pour l'application de la texture
	mesh.setMode(OF_PRIMITIVE_POINTS);
	for (int x = 0; x < textureRes; x++){
		for (int y = 0; y < textureRes; y++){
			mesh.addVertex(ofVec3f(x, y));
			mesh.addTexCoord(ofVec2f(x, y));
		}
	}
}

/**
*\method update()
*\bief update les information sur les framebuffer dans les shader
*		de velocity, de position et de rendu
*/
void ReactorParticle::update(){
	// ********************************* Calcule de la velocity ***************************************//
	// calcule le prochain frame et envoire les informations au shader qui calcul s'il y a colision
	// si les shader trouve une colision ils vont inverser ca velocity

	velParticleBuffer.dst->begin();
	ofClear(0);
	updateShaderVel.begin();
	updateShaderVel.setUniformTexture("backbuffer", velParticleBuffer.src->getTextureReference(), 0);   // passe les information precedente the previus velocity information
	updateShaderVel.setUniformTexture("posData", posParticleBuffer.src->getTextureReference(), 1);  // passe la position au shader
	updateShaderVel.setUniform1i("resolution", (int)textureRes);  //defini la resolution au shader
	updateShaderVel.setUniform2f("screen", (float)width, (float)height); //defini la grandeur de texture
	updateShaderVel.setUniform1f("timestep", (float)timeStep); //defini le nombre de clacul au shader

	// draw dessine la velocity source sur la texture a updater
	velParticleBuffer.src->draw(0, 0);
	updateShaderVel.end();
	velParticleBuffer.dst->end(); 

	//swap le velocity buffer
	velParticleBuffer.swap();


	//**********************************************Calcul de la position****************************************************//
	//calcule la position a l'aide de buffer de velocity
	posParticleBuffer.dst->begin();
	ofClear(0);
	updateShaderPos.begin();
	updateShaderPos.setUniformTexture("prevPosData", posParticleBuffer.src->getTextureReference(), 0); // position source
	updateShaderPos.setUniformTexture("velData", velParticleBuffer.src->getTextureReference(), 1);  // position calculer avec la velosity
	updateShaderPos.setUniform1f("timestep", (float)timeStep);

	// draw la position source a etre updater
	posParticleBuffer.src->draw(0, 0);
	updateShaderPos.end();
	posParticleBuffer.dst->end();

	//swap le position buffer
	posParticleBuffer.swap();


	//*********************************************************************** Rendu ******************************************************************//
	/**
	*\1.	Envoie les vertice au shader de vertice
	*		le shader va dessiner chaque vertice qui ce trouve sur a la fois sur le fram buffer de velocity et position
	*		et l'envoie au shader de vertex
	*
	*\2.	Apres le shader de geometry va creer six vertice de plus pour faire une surface
	*
	*\3.	Ensuite les information sont envoyer au shader de fragement qui applique la texture loader a la surface creer
	*
	*/

	//passe les information au shader de rendu
	bufferRendue.begin();
	ofClear(0, 0, 0, 0);
	updateShaderRender.begin();
	updateShaderRender.setUniformTexture("posTex", posParticleBuffer.dst->getTextureReference(), 0);
	updateShaderRender.setUniformTexture("sparkTex", sparkImg.getTextureReference(), 1);
	updateShaderRender.setUniform1i("resolution", (float)textureRes);
	updateShaderRender.setUniform2f("screen", (float)50, (float)50); //grandeur texture finale
	updateShaderRender.setUniform1f("size", (float)particleSize);
	updateShaderRender.setUniform1f("imgWidth", (float)sparkImg.getWidth());
	updateShaderRender.setUniform1f("imgHeight", (float)sparkImg.getHeight());

	ofPushStyle();
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofSetColor(255);

	//dessine la surface ou sera appliquer la texture
	mesh.draw();

	ofDisableBlendMode();
	glEnd();

	updateShaderRender.end();
	bufferRendue.end();
	ofPopStyle();
}

//--------------------------------------------------------------
void ReactorParticle::draw(ofPoint posOnScreen){
	ofPushMatrix();
	ofSetColor(255, 150, 100);
	bufferRendue.draw(posOnScreen);
	ofPopMatrix();
}

