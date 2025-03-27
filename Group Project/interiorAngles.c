//sebastian solorzano --cscn71020 w25 -- group project
//implementation for interior angle functions

#include <stdio.h>
//#define _USE_MATH_DEFINES // for C
#include <math.h>
#include "interiorAngles.h"


void calcAngles(float l1, float l2, float l3) {
	//assumes lengths are already validated to form a triangle.
	// 
		// cosine law
		//	  A = cos^-1( (b^2 + c^2 - a^2) / 2bc)
	float a1 = acos((pow(l2, 2) + pow(l3, 2) - pow(l1, 2)) / (2.0 * l2 * l3));
	float a2 = acos((pow(l1, 2) + pow(l3, 2) - pow(l2, 2)) / (2.0 * l1 * l3));
	float a3 = acos((pow(l1, 2) + pow(l2, 2) - pow(l3, 2)) / (2.0 * l1 * l2));

	//convert to deg
	a1 = a1 * (180 / M_PI);
	a2 = a2 * (180 / M_PI);
	a3 = a3 * (180 / M_PI);

	//option 1: simply print values to screen
	printf("the triangles angles are: %f degrees, %f degrees, and %f degrees.\n", a1, a2, a3);

}
