#include"FALL.h"
#include"FALL_UP_CLOCK.h"
#include"CONTAINER.h"


CLOCK_UP::CLOCK_UP() {
	Id = C->clockUpId;
	Img = C->clockUpImg;
	AdsSpeed = C->clockUpAdsSpeed;
	Alpha = C->clockUpAlpha;
	Radius = C->fallRadius;
}

void CLOCK_UP::draw(){
	drawImage(Img, Px, Py, 0);
}




