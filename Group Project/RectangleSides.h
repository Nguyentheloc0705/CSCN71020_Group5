#pragma once

typedef struct sides {
	float AB;
	float AC;
	float AD;
	float BC;
	float BD;
	float CD;
} SIDES;

SIDES getSides(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);