//sebastian solorzano -- cscn 71020 w25 --group project
//interface for sidelengths functions
#pragma once

typedef enum sideType {
	edge,
	diagonal
}stypes; //intentionally mispelled so it isnt mistaken for something else

typedef struct side {
	double length;
	stypes type;
}SIDE;

typedef struct quadrilateral {
	SIDE AB;
	SIDE AC;
	SIDE AD;
	SIDE BC;
	SIDE BD;
	SIDE CD;
} QUADRI;


SIDE getSideLength(float x1, float y1, float x2, float y2);
QUADRI getQuadri(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);