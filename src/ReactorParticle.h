/**
*\file ReactorParticlel.h
*\author Alexandre Chouinard
*\brief definition de la class ReactorParticlel qui gere les particules de type pingpong appliquer une texture
*					Cette classe s'inspire du code des exemples de gpuExemple de openFramework
*\date 23/04/2015
*\version 1.0
*/

#pragma once

#include "ofMain.h"



/**
*\struct particleBuffer
*\ brief buffer pour les particules utilisant la theorie du pingpong qui utilise deux frame buffer de OF (ofFbo)
*		un frame buffer est utilise pour la position actuel un autre pour la prochaine destinion et il suffit
*		d'appliquer un swap() pour changer la position
*  
*/
struct particleBuffer {
public:
	void allocate(int _width, int _height, int _internalformat = GL_RGBA, float _dissipation = 1.0f)
	{
		// Allocation de la memoire au grandeur de la texture passer en parametre
		for (int i = 0; i < 2; i++){
			frameBufferO[i].allocate(_width, _height, _internalformat);
			frameBufferO[i].getTextureReference().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
		}

		// initionalisation a 0 des buffer
		clear();
		flag = 0;
		swap();
		flag = 0;
	}

	void swap()
	{
		src = &(frameBufferO[(flag) % 2]);
		dst = &(frameBufferO[++(flag) % 2]);
	}

	void clear()
	{
		for (int i = 0; i < 2; i++){
			frameBufferO[i].begin();
			ofClear(0, 255);
			frameBufferO[i].end();
		}
	}

	//operateur [] pour l'utilisation en tableau
	ofFbo& operator[](int n){ return frameBufferO[n]; }

	ofFbo   *src;       // Source		:	Ping (0)
	ofFbo   *dst;       // Destination  :	Pong (1)
private:
	ofFbo   frameBufferO[2];    // Adresses des buffer src/des ofFbo 
	int     flag;       // Flag pour les swap flag%2 = 0 || 1
};

/**
*\class ReactorParticle
*\ brief class qui creer une texture avec des particules annimer et l'affiche a l'ecran a l'endroit d'essirer
*		cette classe utilise des shaders de openFrameworks "posUpdate.frag" "render.frag" "render.geom" "render.vert" et "velUpdate.frag"
*		qui gere la creation et le deplacement des particule ici les shader ajoute 6 vertice pour 2 TRIANGLE_STRIP qui fait une frame pour l'ajout de la texure
*		loader en memoire
*
*/
class ReactorParticle
{
public:
	void setup();
	void update();
	void draw(ofPoint posOnScreen);
	
private:
	ofShader    updateShaderPos;
	ofShader    updateShaderVel;
	ofShader    updateShaderRender;

	particleBuffer posParticleBuffer;
	particleBuffer velParticleBuffer;

	ofFbo   bufferRendue;

	ofImage sparkImg;

	float   timeStep;
	float   particleSize;

	int     width, height;
	int     imgWidth, imgHeight;
	int     numParticles;
	int     textureRes;


	ofVboMesh mesh;
};

