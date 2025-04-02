#include <stdio.h>
#include <stdbool.h>
#include "sidelengths.h"

float RectMath(QUADRI q , bool Rectangle, bool perimeter1) {
	float sides1 = 0, sides2 = 0, sides3 = 0, sides4 = 0;
		float perimeter = 0;
//		float sides1 = 0, sides2 = 0, sides3 = 0, sides4 = 0;
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
		if (perimeter1 == true) {
		perimeter = sides1 + sides2 + sides3 + sides4;
		return perimeter;
	}
	//printf("The Perimeter is % fl\n", perimeter);
	if (Rectangle == true) {
		float area = 0; //sidelenght1 * sidelenght2;
		area = sides1 * sides2;
	//	printf("The Area is %fl\n", area);
			//sides3 = q.BD.length;
			//sides4 = q.AD.length;
			return area;
	}
	return 0;
}