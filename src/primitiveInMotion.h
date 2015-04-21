#ifndef primitiveInMotion_h
#define primitiveInMotion_h
 
#include "ofMain.h"
 
class Primitive {
private:
		//Properties
		float x;
        float y;
		float z;
		float rayon;
public:
        // Constructor
        Primitive();
 
        // Methods
        void moveTo(int xDestiny, int yDestiny);
        void drawIcosphere();
		void drawCone();
 
        // Properties
        ofColor color;
};
#endif