#include "CubeMap.h"
#include "ofMain.h"


CubeMap::CubeMap(void)
{
}


CubeMap::~CubeMap(void)
{
}

void CubeMap::setup( string pos_x, string pos_y, string pos_z, string neg_x,string neg_y,string neg_z)
{	
	//chargement du shader
	cubeshader.load("skybox");

	// chargement des images
	ofImage images[6];	
	bool loaded1 = images[0].loadImage(pos_x);
	bool loaded2 = images[1].loadImage(neg_x);
	bool loaded3 = images[2].loadImage(pos_y);
	bool loaded4 = images[3].loadImage(neg_y);
	bool loaded5 = images[4].loadImage(pos_z);
	bool loaded6 = images[5].loadImage(neg_z);

	//creation de l'objet texture
	glGenTextures(1, &_textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, _textureID);
	
	//conteneur des donnees des image
	unsigned char * data_px, * data_nx, * data_py, * data_ny, * data_pz, * data_nz;
	
	const int img_size = images[0].getWidth();
	
	data_px = new unsigned char [img_size * img_size * 3];
	data_nx = new unsigned char [img_size * img_size * 3];
	data_py = new unsigned char [img_size * img_size * 3];
	data_ny = new unsigned char [img_size * img_size * 3];
	data_pz = new unsigned char [img_size * img_size * 3];
	data_nz = new unsigned char [img_size * img_size * 3];
	
	data_px = images[0].getPixels();
	data_nx = images[1].getPixels();
	data_py = images[2].getPixels();
	data_ny = images[3].getPixels();
	data_pz = images[4].getPixels();
	data_nz = images[5].getPixels();
	
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB, 0, 3, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_px); // postive x
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB, 0, 3, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_nx); // negative x
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB, 0, 3, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_py); // postive y
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB, 0, 3, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_ny); // negative y
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB, 0, 3, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_nz); // negative z
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB, 0, 3, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_pz); // positive z
	
	// Configuration des parametres de la texture
	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_S, GL_CLAMP );
	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_T, GL_CLAMP );
}

void CubeMap::draw()
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glEnable(GL_TEXTURE_CUBE_MAP_ARB);

	glDepthFunc(GL_LEQUAL);
	//glEnable(GL_DEPTH_TEST);
	cubeshader.begin();
	//glDisable(GL_DEPTH_TEST);
	glActiveTexture(GL_TEXTURE0);
	
	// Utilisation de la texture CubeMap
	glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, _textureID);

	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	cubeshader.setUniform1i("EnvMap", 0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	
	Draw_Skybox(0, 0, 0, 10000, 10000, 10000);

	cubeshader.end();

	glDisable(GL_TEXTURE_CUBE_MAP_ARB);

	//glDisable(GL_DEPTH_TEST);
	glPopMatrix();
}



void CubeMap::Draw_Skybox(float x, float y, float z, float width, float height, float length){

    // Center the Skybox around the given x,y,z position
	x = x - width  / 2;
	y = y - height / 2;
	z = z - length / 2;

	// Draw Front side / ZP

	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x,		  y,		z+length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,		  y+height, z+length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x+width, y+height, z+length);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x+width, y,		z+length);
	glEnd();

	// Draw Back side / ZN

	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x+width, y,		z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x+width, y+height, z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,		  y+height,	z);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x,		  y,		z);
	glEnd();

	// Draw Left side / XN

	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,		  y+height,	z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,		  y+height,	z+length);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x,		  y,		z+length);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x,		  y,		z);
	glEnd();

	// Draw Right side / XP

	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x+width, y,		z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x+width, y,		z+length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x+width, y+height,	z+length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x+width, y+height,	z);
	glEnd();

	// Draw Up side / YP

	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x+width, y+height, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x+width, y+height, z+length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,		  y+height,	z+length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,		  y+height,	z);
	glEnd();

	// Draw Down side / YN

	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x,		  y,		z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x,		  y,		z+length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x+width, y,		z+length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x+width, y,		z);
	glEnd();
}