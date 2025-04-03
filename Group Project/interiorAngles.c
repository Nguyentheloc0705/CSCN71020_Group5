//sebastian solorzano --cscn71020 w25 -- group project
//implementation for interior angle functions

#include <stdio.h>
#define _USE_MATH_DEFINES // for C
#include <math.h>
#include "interiorAngles.h"
#include <stdlib.h>






double getAngle(double adjs1, double adjs2, double opps) {
	if (adjs1 == 0.0 || adjs2 == 0.0) {
		printf("side lengths cannot be zero\n");
		exit(EXIT_FAILURE);
	}
	//cosine law
	// C = cos^-1(  ( a^2 + b^2 - c^2 ) / (2ab)  )
	//	  C	  cos^-1     a^2             b^2             -c^2                2ab
	double C = acos((pow(adjs1, 2) + pow(adjs2, 2) - pow(opps, 2)) / (2.0 * adjs1 * adjs2));

	//convert to deg
	C = C * (180.0 / M_PI);
	//almost certainly going to be the source of fp error at some point but I don't think there's anything I can do

	return C;
}


void calcAngles(double l1, double l2, double l3) {
	//assumes lengths are already validated to form a triangle.

	double a1 = getAngle(l2, l3, l1);
	double a2 = getAngle(l1, l3, l2);
	double a3 = getAngle(l1, l2, l3);

	printf("the triangles angles are: %lf degrees, %lf degrees, and %lf degrees.\n", a1, a2, a3);

}
