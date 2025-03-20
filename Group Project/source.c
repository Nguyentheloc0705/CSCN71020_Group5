#include "Inputs.h"
#include <stdio.h>
#include "interiorAngles.h"
#include "rectangles.h"
#include "sidelengths.h"
#include "isTriangle.h"



int main() {

    
    int choice;
    while (1) {
        printf("\nMenu:\n1. Triangle Feature\n2. Rectangle Feature\n3. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);
        if (choice == 1) {
            float firstLength, secondLength, thirdLength;
            get_triangle_input(&firstLength, &secondLength, &thirdLength);
            if (isTriangle(firstLength, secondLength, thirdLength) == true) {
                calcAngles(firstLength, secondLength, thirdLength);
            }

        }
        else if (choice == 2) {
            float x1, x2, x3, x4, y1, y2, y3, y4;
            get_rectangle_input(&x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
            SIDES sides = getSides(x1, x2, x3, x4, y1, y2, y3, y4);
            isRectangle(sides);
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
