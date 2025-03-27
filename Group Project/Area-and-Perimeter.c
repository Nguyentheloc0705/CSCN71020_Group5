#include <stdio.h>
#include <stdbool.h>
#include "sidelengths.h"

void RectMath(QUADRI q, bool Rectangle) {
	float perimeter = 0;
	float sides1 = 5, sides2 = 7, sides3 = 9, sides4;
	if (q.AB.type == diagonal) {
		sides1 = q.AC.length;
		sides2 = q.BC.length;
		sides3 = q.BD.length;
		sides4 = q.AD.length;
	}
	else if (q.AC.type == diagonal) {
		sides1 = q.AB.length;
		sides2 = q.BC.length;
		sides3 = q.CD.length;
		sides4 = q.AD.length;
	}
	else if (q.AD.type == diagonal) {
		sides1 = q.AB.length;
		sides2 = q.BD.length;
		sides3 = q.CD.length;
		sides4 = q.AC.length;
	}


	perimeter = sides1 + sides2 + sides3 + sides4;
	printf("%fl\n", perimeter);
	if (Rectangle == true) {
		float area = 0, min1 = 0, min2 = 0, max = 0; //sidelenght1 * sidelenght2;
		max = sides1;
		min1 = sides2;
		min2 = sides3;
		if (sides2 > max) {
			max = sides2;
			min1 = sides1;
		}
		if (sides3 > max) {
			max = sides3;
			min1 = sides1;
			min2 = sides2;
		}
		float sideone = min1, sidetwo = min2;
		area = min1 * min2;
		printf("%fl\n", area);
	}
}