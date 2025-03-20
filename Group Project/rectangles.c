//sebastian solorzano --cscn71020 w25 -- group project
//interface for rectangles functions

#include <stdbool.h>
#include <math.h>
#include "sidelengths.h"
#include "rectangles.h"

bool isRectangle(SIDES q) {

	int equality = 0;
	
	//compares AB to all other sides
	if (q.AB == q.AC)
		equality++;
	if (q.AB == q.AD)
		equality++;
	if (q.AB == q.BC)
		equality++;
	if (q.AB == q.BD)
		equality++;
	if (q.AB == q.CD)
		equality++;
	//compares AC to all remaining sides
	if (q.AC == q.AD) 
		equality++;
	if (q.AC == q.BC)
		equality++;
	if (q.AC == q.BD)
		equality++;
	if (q.AC == q.CD)
		equality++;
	//compares AD to all remaining sides
	if (q.AD == q.BC)
		equality++;
	if (q.AD == q.BD)
		equality++;
	if (q.AD == q.CD)
		equality++;
	//compares BC to all remaining sides
	if (q.BC == q.BD ) 
		equality++;
	if (q.BC == q.CD)
		equality++;
	//compares BD to all remaining sides
	if (q.BD == q.CD) 
		equality++;

	//cant use else because we have to check all of these
	//might be prone to floating point errors but there's not much I can do about that


	if (equality == 3 || equality == 7) {
		printf("this is a rectangle");
		return true;
		
	}
	else {
		printf("this is not a rectangle");
		return false;
	}
	//rectangles have three matching pairs: short parallels, long parallels, and diagonals.
	//things like diamonds, kites or trapezoids all have less or more than three (0, 2, 4, 6, etc.)
	//in addition, since squares are rectangles, they must be included too. they have seven matching pairs 
	// (side1-2, side1-3, side1-4, side2-3, side2-4, side3-4, diagonals). all other quadrilaterals have less


}
