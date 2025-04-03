#include <stdio.h>
#define _USE_MATH_DEFINES // for C
#define M_PI 3.14159265358979323846
//#include <math.h>

#include "TestinteriorAngles.h"


float calcAngles(float l1, float l2, float l3,int angle) {
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
	if (angle == 0) {
		return a1;
	}
	else if (angle == 1) {
		return a2;
	}
	else {
		return a3;
	}
}