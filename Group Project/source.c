#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void get_triangle_input() {
    float sidelength1 = 0;
    float sidelength2 = 0;
    float sidelength3 = 0;
    float max;
    float min1;
    float min2;

    scanf("%fl", &sidelength1);
    scanf("%fl", &sidelength2);
    scanf("%fl", &sidelength3);
    max = sidelength1;
    min1 = sidelength2;
    min2 = sidelength3;
    if (sidelength2 > max) {
        max = sidelength2;
        min1 = sidelength1;
    }
    if (sidelength3 > max) {
        max = sidelength3;
        min1 = sidelength1;
        min2 = sidelength2;
    }

    printf("side1 %fl, side2 %fl, side3 %fl\n", sidelength1, sidelength2, sidelength3);
    printf(" %fl, %fl, %fl\n", max, min1, min2);
    if (max < min1 + min2) {
        printf("it is a triangle\n");
    }
}

void get_rectangle_input() {

}

int main() {
    int choice;
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
    }
    return 0;
}
