#include"IMG.h"
#include"graphic.h"
#include"CONTAINER.h"
#include"COLOR.h"

CONTAINER* IMG::C = 0;

IMG::IMG() {
	FreamImg = C->freamImg;
	FreamPx = C->freamPx;
	FreamPy = C->freamPy;
	SelectHeight = C->selectHeight;
	
}

void IMG::draw(float px) {
	drawImage(FreamImg, FreamPx, FreamPy, COLOR(Rad, Green, Blue, Alpha));
	drawImage(Img, Px, Py, COLOR(Rad, Green, Blue, Alpha));
}

float IMG::selectHeight() {
	return SelectHeight;
}

void IMG::fadeIn() { Alpha -= C->fadeDecayAlpha; if (Alpha < 0.0f) { Alpha = 0.0f; } };
void IMG::fadeOut() { Alpha += C->fadeDecayAlpha; if (Alpha > 1.0f) { Alpha = 1.0f; } };

float IMG::alpha() { return Alpha; };