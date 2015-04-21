#include "primitiveInMotion.h"
#include <math.h>
 
Primitive::Primitive(){
    // Set the initial color
    color.set(255, 255, 255);
 
    // Initial x position of the primitive
    x = 0;
 
    // Initial y position of the primitive
    y = 0;

	// Initial z position of thet primitive
	z = 0;
}
 
void Primitive::moveTo(int xDestiny, int yDestiny){
    x += ( xDestiny - x )*0.1;
    y += ( yDestiny - y )*0.1;
}
 
void Primitive::drawIcosphere(){
    ofSetColor(color);
    ofFill();
	ofDrawIcoSphere(x,y,z,5);
}

void Primitive::drawCone(){
    ofSetColor(color);
    ofFill();
	ofDrawCone(x,y,z,10,10);
}