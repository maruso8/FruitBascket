#include"FALL.h"
#include"FALL_DOWN_CLOCK.h"
#include"CONTAINER.h"


CLOCK_DOWN::CLOCK_DOWN() {
	Id = C->clockDownId;
	Img = C->clockDownImg;
	AdsSpeed = C->clockDownAdsSpeed;
	Alpha = C->clockDownAlpha;
	Radius = C->fallRadius;
}

void CLOCK_DOWN::draw(){
	drawImage(Img, Px, Py, 0);
}




