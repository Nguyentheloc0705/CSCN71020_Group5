//sebastian solorzano --cscn71020 w25 -- group project
//interface for sidelengths

#include <math.h>
#include "sidelengths.h"
#include "interiorAngles.h"

SIDES getSides(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	SIDES q = { 0 }; //init
	//line =  squareroot(   delta x^2 + delta y^2 ) 
	q.AB = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	q.AC = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
	q.AD = sqrt(pow(x4 - x1, 2) + pow(y4 - y1, 2));
	q.BC = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	q.BD = sqrt(pow(x4 - x2, 2) + pow(y4 - y2, 2));
	q.CD = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
	// doesnt matter if delta ends up positive or negative since it gets squared

	
	//feels like finding angles is necessary to determine interior/exterior
	//because we don't know which is the diagonal, each point gets 3 angles
	//should probably be moved to seperate functions 

	//point a
	double aBAC = getAngle(q.AB, q.AC, q.BC);
	double aBAD = getAngle(q.AB, q.AD, q.BD);
	double aCAD = getAngle(q.AC, q.AD, q.CD);
	//determining diagonal:
	//if two angles are equal to the third, the bigger angle is formed between the outer sides
	//the shared side between the two smaller angles must then be a diagonal
	if (aCAD == aBAC + aBAD) {
		q.ABtype == diagonal;//shared between BAC and BAD
		q.ACtype == edge;
		q.ADtype == edge;
	}
	else if (aBAD == aBAC + aCAD) {
		q.ABtype == edge;
		q.ACtype == diagonal;
		q.ADtype == edge;
	}
	else if (aBAC == aBAD + aCAD) { 
		q.ABtype == edge;
		q.ACtype == edge;
		q.ADtype == diagonal; 
	}
	else {
		//means the shape must be concave. unsure how to solve at the moment
	}

	//point b
	double aABC = getAngle(q.AB, q.BC, q.AC);
	double aABD = getAngle(q.AB, q.BD, q.AD);
	double aCBD = getAngle(q.BC, q.BD, q.CD);
	//determining diagonal:
	//if two angles are equal to the third, the bigger angle is formed between the outer sides
	//the shared side between the two smaller angles must then be a diagonal
	if (aCBD == aABC + aABD) {
		q.ABtype == diagonal;
		q.BCtype == edge;
		q.BDtype == edge;
	}
	else if (aABD == aABC + aCBD) {
		q.ABtype == edge;
		q.BCtype == diagonal;
		q.BDtype == edge;
	}
	else if (aABC == aABD + aCBD) {
		q.ABtype == edge;
		q.BCtype == edge;
		q.BDtype == diagonal;
	}
	else {
		//means the shape must be concave. unsure how to solve at the moment
	}

	//point c
	double aACB = getAngle(q.AC, q.BC, q.AB);
	double aACD = getAngle(q.AC, q.CD, q.AD);
	double aBCD = getAngle(q.BC, q.CD, q.BD);
	//determining diagonal:
	//if two angles are equal to the third, the bigger angle is formed between the outer sides
	//the shared side between the two smaller angles must then be a diagonal
	if (aBCD == aACB + aACD) {
		q.ACtype == diagonal;
		q.BCtype == edge;
		q.CDtype == edge;
	}
	else if (aACD == aACB + aBCD) {
		q.ACtype == edge;
		q.BCtype == diagonal;
		q.CDtype == edge;
	}
	else if (aACB == aACD + aBCD) {
		q.ACtype == edge;
		q.BCtype == edge;
		q.CDtype == diagonal;
	}
	else {
		//means the shape must be concave. unsure how to solve at the moment
	}

	//point d
	double aADB = getAngle(q.AD, q.BD, q.AB);
	double aADC = getAngle(q.AD, q.CD, q.AC);
	double aBDC = getAngle(q.BD, q.CD, q.BC);
	if (aBDC == aADB + aADC) {
		q.ADtype == diagonal;
		q.BDtype == edge;
		q.CDtype == edge;
	}
	else if (aADC == aADB + aBDC) {
		q.ADtype == edge;
		q.BDtype == diagonal;
		q.CDtype == edge;
	}
	else if (aADB == aADC + aBDC) {
		q.ABtype == edge;
		q.BDtype == edge;
		q.CDtype == diagonal;
	}
	else {
		//means the shape must be concave. unsure how to solve at the moment
	}



	return q;
}