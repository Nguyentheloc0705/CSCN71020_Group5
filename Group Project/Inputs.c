#define _CRT_SECURE_NO_WARNINGS
#include "Inputs.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>


bool test_for_letter(char input[]) {
	for (int i = 0; input[i] != '\0'; i++) {
		if (isalpha(input[i]) != 0) {
			return false;
			break;

		}
	}
	return true;
}

void get_triangle_input(float* firstLength, float* secondLength, float* thirdLength) {
	char input[10];


	do {

		printf("please input first side length");
		scanf("%s", &input);


	} while (test_for_letter(input) == false);
	*firstLength = atof(input);

	do {

		printf("please input second side length");
		scanf("%s", &input);

	} while (test_for_letter(input) == false);
	*secondLength = atof(input);

	do {

		printf("please input third side length");
		scanf("%s", &input);

	} while (test_for_letter(input) == false);
	*thirdLength = atof(input);


}

void get_rectangle_input(float* x1, float* y1, float* x2, float* y2, float* x3, float* y3, float* x4, float* y4) {
	char input[10];

	do {

		printf("please input x1");
		scanf("%s", &input);


	} while (test_for_letter(input) == false);
	*x1 = atof(input);

	do {

		printf("please input y1");
		scanf("%s", &input);

	} while (test_for_letter(input) == false);
	*y1 = atof(input);

	do {

		printf("please input x2");
		scanf("%s", &input);

	} while (test_for_letter(input) == false);
	*x2 = atof(input);


	do {

		printf("please input y2");
		scanf("%s", &input);


	} while (test_for_letter(input) == false);
	*y2 = atof(input);

	do {

		printf("please input x3");
		scanf("%s", &input);

	} while (test_for_letter(input) == false);
	*x3 = atof(input);

	do {

		printf("please input y3");
		scanf("%s", &input);

	} while (test_for_letter(input) == false);
	*y3 = atof(input);


	do {

		printf("please input x4");
		scanf("%s", &input);


	} while (test_for_letter(input) == false);
	*x4 = atof(input);

	do {

		printf("please input y4");
		scanf("%s", &input);

	} while (test_for_letter(input) == false);
	*y4 = atof(input);

}