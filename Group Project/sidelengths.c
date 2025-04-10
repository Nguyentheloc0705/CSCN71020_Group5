//sebastian solorzano --cscn71020 w25 -- group project
//interface for sidelengths

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "sidelengths.h"
#include "interiorAngles.h"


SIDE getSideLength(double x1, double y1, double x2, double y2) {
	SIDE s = { 0 };//init
	//line =  squareroot(   delta x^2 + delta y^2 ) 
	double deltaX = x2 - x1;
	double deltaY = y2 - y1;
	s.length = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
	// doesnt matter if delta ends up positive or negative since it gets squared
	return s;
}


QUADRI getQuadri(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
	QUADRI q = { 0 }; //init

	//LENGTHS
	q.AB = getSideLength(x1, y1, x2, y2);
	q.AC = getSideLength(x1, y1, x3, y3);
	q.AD = getSideLength(x1, y1, x4, y4);
	q.BC = getSideLength(x2, y2, x3, y3);
	q.BD = getSideLength(x2, y2, x4, y4);
	q.CD = getSideLength(x3, y3, x4, y4);


	//INTERIOR/EXTERIOR
	//getting angles is necessary in order to determine interior(diagonals) vs exterior(sides)
	//we only need to check one set of angles
	double taBAC = getAngle(q.AB.length, q.AC.length, q.BC.length);
	double taBAD = getAngle(q.AB.length, q.AD.length, q.BD.length);
	double taCAD = getAngle(q.AC.length, q.AD.length, q.CD.length);
	//however, because they're floating points, nothing useful can be done with them
	//instead, we'll convert them to int and drop a few digits, since they're likely incorrect anyway
	int aBAC = trunc(taBAC * 1000.0);//drops 3 digits, im pretty sure (6 decimals are displayed when printing double)
	int aBAD = trunc(taBAD * 1000.0);
	int aCAD = trunc(taCAD * 1000.0);

	printf("%d, %d, %d\n", aBAC, aBAD, aCAD);
	//if two angles are equal to the third, the bigger angle is formed between the outer sides
	//the shared side between the two smaller angles must then be a diagonal
	int diff1 = abs(aCAD - (aBAC + aBAD)); //if equal, the difference =0, if not, =!0
	int diff2 = abs(aBAD - (aBAC + aCAD)); //cant be put directly into the if statement
	int diff3 = abs(aBAC - (aBAD + aCAD)); //since some inaccuracy still remains from the floats
	int diff360 = abs(360000 - (aBAC + aBAD + aCAD)); 
	//360000 = 360 degrees, for angles on concave shapes. for interior angles >180,
	//using the cosine law will result in the outer angle rather than the inner one.
	//as such, the three angles should be equal to a full 360 degrees
	printf("%d, %d, %d, %d(360) \n", diff1, diff2, diff3, diff360);


	if (diff1 <= 2) { 
	//if the difference is off by 2 (which represents 0.002), 
	//then it was likely from a rounding/truncation/float/rational num/irrational num error
	//which cannot be corrected for.
	//(i.e. a square with sidelenghts 1 may not result in 90 degree angles because its diagonals are irrational (sqrt2),
	//leaving the result as 89.99999999 or something
		q.AB.type = diagonal;//shared between BAC and BAD
		q.AC.type = edge;
		q.AD.type = edge;

		q.BC.type = edge;
		q.BD.type = edge;
		q.CD.type = diagonal;
		//by definition, if points A and B are opposites, then points C and D must also be opposite.
		//as such, all other sides are NOT opposite.
		printf("ab and cd should be diagonal\n");
	}
	else if (diff2 <= 2) {
		q.AB.type = edge;
		q.AC.type = diagonal;
		q.AD.type = edge;

		q.BC.type = edge;
		q.BD.type = diagonal;
		q.CD.type = edge;
		printf("ac and bd should be diagonal\n");

	}
	else if (diff3 <= 2) {
		q.AB.type = edge;
		q.AC.type = edge;
		q.AD.type = diagonal; 

		q.BC.type = diagonal;
		q.BD.type = edge;
		q.CD.type = edge;
		printf("ad and bc should be diagonal\n");

	}
	else if(diff360 <= 2) {
	//means the shape must be concave. 
	//with four possible variations, it is impossible to determine which is 'correct'
	//as such, we will arbitrarily choose one. there is no other way
	//(this also happens with the previous if it gets the small angles of a concave shape.
	//point A will always end up being the 'head')
		q.AB.type = diagonal;
		q.CD.type = diagonal;
		//as I said, arbitrary
		q.AC.type = edge;
		q.AD.type = edge;
		q.BC.type = edge;
		q.BD.type = edge;
		printf("ab and cd should be diagonal\n");

	}
	else {
		//if the angles don't add up to each other or 360, it means there must be some error
		fprintf(stderr, "there was an unexpected error (likely floating points).\n");
		fprintf(stderr,"sidelengths: %lf, %lf, %lf, %lf, %lf, %lf\n", q.AB.length, q.AC.length, q.AD.length, q.BC.length, q.BD.length, q.CD.length);
		fprintf(stderr,"angles*: %d, %d, %d\n", aBAC, aBAD, aCAD);
		int comb1 = aBAC + aBAD;
		int comb2 = aBAC + aCAD;
		int comb3 = aBAD + aCAD;
		int comb4 = aBAC + aBAD + aCAD;
		fprintf(stderr, "angle sums*:%d, %d, %d, %d,\n",comb1,comb2,comb3,comb4);
		fprintf(stderr, "if any of the above is roughly equal to the previous, or 360*, there was a rounding/floating point error\n");
		fprintf(stderr, "* numbers have been multiplied by 1000\n");
		exit(EXIT_FAILURE);
		//there's really not much I can do
	}


	return q;
}