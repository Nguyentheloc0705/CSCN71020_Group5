//sebastian solorzano --cscn71020 w25 -- group project
//interface for sidelengths

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "sidelengths.h"
#include "interiorAngles.h"


SIDE getSideLength(float x1, float y1, float x2, float y2) {
	SIDE s = { 0 };//init
	//line =  squareroot(   delta x^2 + delta y^2 ) 
	s.length = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	// doesnt matter if delta ends up positive or negative since it gets squared
	return s;
}


QUADRI getQuadri(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	QUADRI q = { 0 }; //init

	//side lengths
	q.AB = getSideLength(x1, y1, x2, y2);
	q.AC = getSideLength(x1, y1, x3, y3);
	q.AD = getSideLength(x1, y1, x4, y4);
	q.BC = getSideLength(x2, y2, x3, y3);
	q.BD = getSideLength(x2, y2, x4, y4);
	q.CD = getSideLength(x3, y3, x4, y4);


	//getting angles is necessary in order to determine interior vs exterior sides
	//we only need to check one set of angles
	double aBAC = getAngle(q.AB.length, q.AC.length, q.BC.length);
	double aBAD = getAngle(q.AB.length, q.AD.length, q.BD.length);
	double aCAD = getAngle(q.AC.length, q.AD.length, q.CD.length);

	//determining diagonals:
	//if two angles are equal to the third, the bigger angle is formed between the outer sides
	//the shared side between the two smaller angles must then be a diagonal
	if (aCAD == aBAC + aBAD) {
		q.AB.type == diagonal;//shared between BAC and BAD
		q.AC.type == edge;
		q.AD.type == edge;

		q.BC.type == edge;
		q.BD.type == edge;
		q.CD.type == diagonal;
		//by definition, if points A and B are opposites, then points C and D must also be opposite.
		//as such, all other sides are NOT opposite.

	}
	else if (aBAD == aBAC + aCAD) {
		q.AB.type == edge;
		q.AC.type == diagonal;
		q.AD.type == edge;

		q.BC.type == edge;
		q.BD.type == diagonal;
		q.CD.type == edge;
	}
	else if (aBAC == aBAD + aCAD) {
		q.AB.type == edge;
		q.AC.type == edge;
		q.AD.type == diagonal;

		q.BC.type == diagonal;
		q.BD.type == edge;
		q.CD.type == edge;
	}
	else if (aBAC + aBAD + aCAD == 360.0) {
		//means the shape must be concave. 
		//with four possible variations, it is impossible to determine which is 'correct'
		//as such, we will arbitrarily choose one. there is no other way
		//(this also happens with the previous if it gets the small angles of a concave shape.
		//point a will always end up being the 'head')
		q.AB.type = diagonal;
		q.CD.type = diagonal;
		//as I said, arbitrary
		q.AC.type = edge;
		q.AD.type = edge;
		q.BC.type = edge;
		q.BD.type = edge;
	}
	else {
		//if the angles don't add up to each other or 360, it means there must be some error
		fprintf(stderr, "there was an unexpected error (likely floating points).\n");
		exit(EXIT_FAILURE);
		//there's really not much I can do
	}


	return q;
}