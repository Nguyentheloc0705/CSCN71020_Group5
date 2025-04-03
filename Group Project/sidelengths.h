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


SIDE getSideLength(double x1, double y1, double x2, double y2);
QUADRI getQuadri(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);