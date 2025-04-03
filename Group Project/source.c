#include <stdio.h>
#include <math.h>
#include "interiorAngles.h"
#include "rectangles.h"
#include <stdbool.h>

void get_triangle_input() {
}

void get_rectangle_input() {

}

int main() {

  //  QUADRI c = getQuadri(1.1,3.2, 11.1,3.2, 11.1,23.2, 1.1,23.2);
    QUADRI q = getQuadri(0, 0, 0, 2, 2, 0, 2, 2);
  
    
   /* int choice;
    while (1) {
        printf("\nMenu:\n1. Triangle Feature\n2. Rectangle Feature\n3. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);
        if (choice == 1) {
            get_triangle_input();
        }
        else if (choice == 2) {
            get_rectangle_input();
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("Invalid choice. Try again.\n");
        }
    }*/

    return 0;
}
