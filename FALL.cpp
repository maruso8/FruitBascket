#include"FALL.h"
#include"CONTAINER.h"
#include<stdlib.h>

#include"graphic.h"
#include"debugStr.h"
CONTAINER* FALL::C = 0;
void setRandSeed();

void FALL::appear(){//1770,1180,365
	Px = rand() % 1380 + 265;
	Py = 0;
	Alpha = 1;
};

void FALL::update() {
	Py += AdsSpeed;
	if (C->windowHeight < Py) {
		Alpha = 0;
	}

}

void FALL::draw() {
	drawImage(Img, Px, Py, 0);
}

void FALL::deleteAlpha() {Alpha = 0.0f;}

float FALL::top() { return Py - Radius+20; }
float FALL::bottom(){ return Py + Radius; }
float FALL::left(){ return Px - Radius; }
float FALL::right(){ return Px + Radius; }


int FALL::score() { return Score; };
char FALL::id() { return Id; }
float FALL::alpha() { return Alpha; }

