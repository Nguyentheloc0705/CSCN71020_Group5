#include <stdbool.h>
#include <stdio.h>

bool isTriangle(float sideLength1, float sideLength2, float sideLength3){
    float max = sideLength1;
    float min1 = sideLength2;
    float min2 = sideLength3;
    if (sideLength2 > max) {
        max = sideLength2;
        min1 = sideLength1;
    }
    if (sideLength3 > max) {
        max = sideLength3;
        min1 = sideLength1;
        min2 = sideLength2;
    }

    if (max < min1 + min2) {
        printf("it is a triangle\n");
        return true;
    }
    else {
        return false;
    }

    
}


