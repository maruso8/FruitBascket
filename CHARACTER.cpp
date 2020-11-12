#include"graphic.h"
#include"CHARACTER.h"


CONTAINER* CHARACTER::C = 0;


void CHARACTER::update() {

}


void CHARACTER::draw() {
	drawImage(Img, Px, Py,0);
}


float CHARACTER::top() { return Py-Top; }
float CHARACTER::bottom(){ return Py+Bottom; }
float CHARACTER::left(){ return Px -Left; }
float CHARACTER::right(){ return Px + Right; }

void CHARACTER::speedUp() { AdsSpeed += 1.5f; }
void CHARACTER::speedDown() { AdsSpeed -= 1.5f; };

float CHARACTER::adsSpeed() { return AdsSpeed; }
