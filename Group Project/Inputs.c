#define _CRT_SECURE_NO_WARNINGS
#include "Inputs.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>


bool test_for_letter(char input[]) {
	for (int i = 0; input[i] != '\0'; i++) {
		if (isalpha(input[i]) != 0 || input < 1) {
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