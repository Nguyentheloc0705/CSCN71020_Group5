//sebastian solorzano --cscn71020 w25 -- group project
//interface for rectangles functions

#include <stdbool.h>
#include <math.h>
#include "sidelengths.h"
#include "rectangles.h"

bool isRectangle(SIDES q) {

	int equality = 0;
	
	if (q.AB == q.AC || q.AB == q.AD || q.AB == q.BC || q.AB == q.BD || q.AB == q.CD) {
		equality++;
	}

	if (q.AC == q.AD || q.AC == q.BC || q.AC == q.BD || q.AC == q.CD) {
		equality++;
	}

	if (q.AD == q.BC || q.AD == q.BD || q.AD == q.CD) {
		equality++;
	}

	if (q.BC == q.BD || q.BC == q.CD) {
		equality++;
	}

	if (q.BD == q.CD) {
		equality++;
	}
	//cant use else because we have to check all of these

	if (equality == 3) {
		return true;
	}
	if(equality == 4){
		return false;
	}

	//unfortunately, gives false positive for trapezoids with three equal sides, diamonds with four equal sides,
	//and gives false negative for squares. have to check for simultaneus equality somehow

}
