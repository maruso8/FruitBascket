#include"IMG.h"
#include"CONTAINER.h"
#include"FADE.h"
#include"graphic.h"
#include"debugStr.h"

FADE::FADE() {
	Img = C->fadeinImg;
	Px = C->fadePx;
	Py = C->fadePy;
	Alpha = 0;
}

void FADE::draw(float px) {
	drawImage(Img, Px, Py, COLOR(Rad, Green, Blue, Alpha));
}
