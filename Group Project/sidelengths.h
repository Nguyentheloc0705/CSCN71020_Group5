//sebastian solorzano -- cscn 71020 w25 --group project
//interface for sidelengths functions
#pragma once

typedef enum sideType {
	edge,
	diagonal
}stypes; //intentionally mispelled so it isnt mistaken for something else

typedef struct sides {
	float AB;
	stypes ABtype;

	float AC;
	stypes ACtype;

	float AD;
	stypes ADtype;

	float BC;
	stypes BCtype;

	float BD;
	stypes BDtype;

	float CD;
	stypes CDtype;
	//surprisingly, making a new struct (length, type) would be more annoying than this
} SIDES;

SIDES getSides(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);