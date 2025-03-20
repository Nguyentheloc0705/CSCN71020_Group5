#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "RectangleSides.h"

void RectMath(SIDES q, bool Rectangle) {
	float perimeter = 0;
	perimeter = q.AB + q.BC + q.CD + q.AD;
	printf("%fl\n", perimeter);
	if (Rectangle == true) {
		float area = 0; //sidelenght1 * sidelenght2;
		area = q.AB * q.BC;
		printf("%fl\n", area);
	}
}