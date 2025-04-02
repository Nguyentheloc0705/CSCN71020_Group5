#include <stdio.h>
#include <stdbool.h>
#include "TestArea and Perimeter.h"
#include "sidelengths.h"

void TestAreaandPerimeter(bool rectangle, bool perimeter, float side1, float side2, float side3, float side4,float side5, float side6, stypes AB, stypes AC, stypes AD, float expected) {
	QUADRI q = {0};
	q.AB.length = side1;
	q.AC.length = side2;
	q.AD.length = side3;
	q.BC.length = side4;
	q.BD.length = side5;
	q.CD.length = side6;
	q.AB.type = AB;
	q.AC.type = AC;
	q.AD.type = AD;
	float actual = RectMath(q, rectangle, perimeter);

	if (expected != actual) {
		printf("failed");
	}
}

int main(void) {
	TestAreaandPerimeter(true, true, 3, 5, 4, 4, 5, 3, edge, diagonal, edge, 14);
	TestAreaandPerimeter(true, false, 3, 5, 4, 4, 5, 3, edge, diagonal, edge, 12);
	TestAreaandPerimeter(false, false, 3, 5, 4, 4, 5, 3, edge, diagonal, edge, 0);
	
	TestAreaandPerimeter(true, true, 3.807, 3.5, 1.5, 1.5, 3.5, 3.807, diagonal, edge, edge, 10);
	TestAreaandPerimeter(true, false, 3.807, 3.5, 1.5, 1.5, 3.5, 3.807, diagonal, edge, edge, 5.25);


	return 0;
}
