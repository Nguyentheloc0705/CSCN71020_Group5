//sebastian solorzano --cscn71020 w25 -- group project
//interface for rectangles functions

#include <stdbool.h>
#include <math.h>
#include "sidelengths.h"
#include "rectangles.h"

bool isRectangle(QUADRI q) {

	int equality = 0;

	//in theory, if they're equal, they should be equal, but you never know with floats...
	int lAB = trunc(q.AB.length * 1000000.0);//it should be fine if this one keeps its digits, right?
	int lAC = trunc(q.AC.length * 1000000.0);
	int lAD = trunc(q.AD.length * 1000000.0);
	int lBC = trunc(q.BC.length * 1000000.0);
	int lBD = trunc(q.BD.length * 1000000.0);
	int lCD = trunc(q.CD.length * 1000000.0);


	//compares AB to all other sides
	if (lAB == lAC)
		equality++;
	if (lAB == lAD)
		equality++;
	if (lAB == lBC)
		equality++;
	if (lAB == lBD)
		equality++;
	if (lAB == lCD)
		equality++;
	//compares AC to all remaining sides
	if (lAC == lAD)
		equality++;
	if (lAC == lBC)
		equality++;
	if (lAC == lBD)
		equality++;
	if (lAC == lCD)
		equality++;
	//compares AD to all remaining sides
	if (lAD == lBC)
		equality++;
	if (lAD == lBD)
		equality++;
	if (lAD == lCD)
		equality++;
	//compares BC to all remaining sides
	if (lBC == lBD)
		equality++;
	if (lBC == lCD)
		equality++;
	//compares BD to all remaining sides
	if (lBD == lCD)
		equality++;

	//cant use else because we have to check all of these

	if (equality == 3 || equality == 7) {
		return true;
	}
	else {
		return false;
	}
	//rectangles have 3 matching pairs: short parallels, long parallels, and diagonals.
	//things like diamonds, kites or trapezoids all have less or more than 3 (0, 2, 4, 6, etc.)
	//in addition, since squares are rectangles, they must be included too. they have 7 matching pairs 
	// (side1-2, side1-3, side1-4, side2-3, side2-4, side3-4, diagonals). all other quadrilaterals have less.


}