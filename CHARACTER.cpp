#include"graphic.h"
#include"CONTAINER.h"
#include"CHARACTER.h"


CONTAINER* CHARACTER::C = 0;


CHARACTER::CHARACTER() {
	C = CONTAINER::getInstance();
}

CHARACTER::~CHARACTER() {
	CONTAINER::Delete();
}


void CHARACTER::draw() {
	if (Stan / 5 % 2 == 0) {
		drawImage(MoveImg, Px, Py, 0);
	}
	
	if (Stan) {
		Stan--;
	}
	else Stan = 0;

	if (Stan <= 0) {
		stenRecovery();
	}
}


float CHARACTER::top() { return Py-Top; }
float CHARACTER::bottom(){ return Py+Bottom; }
float CHARACTER::left(){ return Px -Left; }
float CHARACTER::right(){ return Px + Right; }

void CHARACTER::speedUp() { AdsSpeed += 1.5f; }
void CHARACTER::speedDown() { AdsSpeed -= 1.5f; };
void CHARACTER::sten() { Stan = 60; AdsSpeed = 0; };

float CHARACTER::adsSpeed() { return AdsSpeed; }
