#ifndef TEST_SOURCE_H
#define TEST_SOURCE_H

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "RectangleSides.h"
#include "SpaceRectangle.h"

void run_tests() {
    printf("Running tests...\n");

    // Test getSides
    SIDES q = getSides(0, 0, 4, 0, 4, 3, 0, 3);
    assert(q.AB == 4.0);
    assert(q.BC == 3.0);
    assert(q.CD == 4.0);
    assert(q.AD == 3.0);

    // Test RectMath
    q = (SIDES){ 4.0, 3.0, 0.0, 3.0, 0.0, 4.0 };
    printf("Expected Perimeter: 14\n");
    printf("Expected Area: 12\n");
    RectMath(q, true);

    printf("All tests passed!\n");
}

#endif 
