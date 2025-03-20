#include <math.h>
#include "RectangleSides.h"

SIDES getSides(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	SIDES q = { 0 }; //init
	//line =  squareroot(   delta x^2 + delta y^2 ) 
	q.AB = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	q.AC = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
	q.AD = sqrt(pow(x4 - x1, 2) + pow(y4 - y1, 2));
	q.BC = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	q.BD = sqrt(pow(x4 - x2, 2) + pow(y4 - y2, 2));
	q.CD = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
	// doesnt matter if delta ends up positive or negative since it gets squared

	return q;
}