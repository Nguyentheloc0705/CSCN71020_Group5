#include <stdio.h>
#include <stdbool.h>
#include "TestArea and Perimeter.h"
#include "TestinteriorAngles.h"
#include "sidelengths.h"

void TestinteriorAngles(float l1,float l2,float l3, float expected1, float expected2, float expected3) {
	float actual1 = calcAngles(l1, l2, l3, 0);
	float actual2 = calcAngles(l1, l2, l3, 1);
	float actual3 = calcAngles(l1, l2, l3, 2);


	if (expected1 != actual1 || expected2 != actual2 || expected3 != actual3) {
		printf("actual1 %fl, expected1 %fl, actual2 %fl, expected2 %fl, actual3 %fl, expected3 %fl\n", actual1, expected1, actual2, expected2, actual3, expected3);
		printf("failed\n");
	}
}

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
	//perimeter
	TestAreaandPerimeter(true, true, 3, 5, 4, 4, 5, 3, edge, diagonal, edge, 14);
	//area
	TestAreaandPerimeter(true, false, 3, 5, 4, 4, 5, 3, edge, diagonal, edge, 12);
	TestAreaandPerimeter(false, false, 3, 5, 4, 4, 5, 3, edge, diagonal, edge, 0);
	//perimeter
	TestAreaandPerimeter(true, true, 3.807, 3.5, 1.5, 1.5, 3.5, 3.807, diagonal, edge, edge, 10);
	//area
	TestAreaandPerimeter(true, false, 3.807, 3.5, 1.5, 1.5, 3.5, 3.807, diagonal, edge, edge, 5.25);

	TestAreaandPerimeter(false, true, 3, 5, 4, 4, 5, 3, edge, diagonal, edge, 14);

	TestinteriorAngles(2, 2, 2, 60, 60, 60);
	TestinteriorAngles(2, 5, 5, 23.0739180656, 78.4630409672, 78.4630409672);
	TestinteriorAngles(3, 5, 7, 21.7867892983, 38.2132107017, 120);

	//this error has been fixed but if it did somehow reach it would crash
	TestinteriorAngles(0, 2, 2, 0, 0, 0);

	TestinteriorAngles(2.2, 2.2, 2.2, 60, 60, 60);
	TestinteriorAngles(3.2, 5.2, 2.2, 18.95, 148.15, 12.9);
	return 0;
}
