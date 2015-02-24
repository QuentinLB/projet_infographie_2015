#pragma once
#include <string>
#include "IElementDessinable.h"
#include "guiVoyageurEspace.h"


using namespace std;

class CubeMap : public IElementDessinable
{
private:
	unsigned int _textureID;
	ofShader cubeshader;
public:
	CubeMap(void);
	~CubeMap(void);
	void setup( string pos_x, string pos_y, string pos_z, string neg_x,string neg_y,string neg_z);
	void draw(){};
	void draw(ofCamera cam);
	void Draw_Skybox(float x, float y, float z, float width, float height, float length);
};
