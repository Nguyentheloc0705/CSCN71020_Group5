//sebastian solorzano --cscn71020 w25 -- group project
//interface for rectangles functions

#include <stdbool.h>
#include <math.h>
#include "sidelengths.h"
#include "rectangles.h"

bool isRectangle(QUADRI q) {

	int equality = 0;
	
	//compares AB to all other sides
	if (q.AB.length == q.AC.length)
		equality++;
	if (q.AB.length == q.AD.length)
		equality++;
	if (q.AB.length == q.BC.length)
		equality++;
	if (q.AB.length == q.BD.length)
		equality++;
	if (q.AB.length == q.CD.length)
		equality++;
	//compares AC to all remaining sides
	if (q.AC.length == q.AD.length)
		equality++;
	if (q.AC.length == q.BC.length)
		equality++;
	if (q.AC.length == q.BD.length)
		equality++;
	if (q.AC.length == q.CD.length)
		equality++;
	//compares AD to all remaining sides
	if (q.AD.length == q.BC.length)
		equality++;
	if (q.AD.length == q.BD.length)
		equality++;
	if (q.AD.length == q.CD.length)
		equality++;
	//compares BC to all remaining sides
	if (q.BC.length == q.BD.length)
		equality++;
	if (q.BC.length == q.CD.length)
		equality++;
	//compares BD to all remaining sides
	if (q.BD.length == q.CD.length)
		equality++;

	//cant use else because we have to check all of these
	//might be prone to floating point errors but there's not much I can do about that


	if (equality == 3 || equality == 7) {
		return true;
	}
	else {
		return false;
	}
	//rectangles have three matching pairs: short parallels, long parallels, and diagonals.
	//things like diamonds, kites or trapezoids all have less or more than three (0, 2, 4, 6, etc.)
	//in addition, since squares are rectangles, they must be included too. they have 7 matching pairs 
	// (side1-2, side1-3, side1-4, side2-3, side2-4, side3-4, diagonals). all other quadrilaterals have less


}
