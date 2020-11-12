#include"FALL.h"
#include"FALL_UP_SHOES.h"
#include"CONTAINER.h"


SHOES_UP::SHOES_UP() {
	Id = C->shoesUpId;
	Img = C->shoesUpImg;
	AdsSpeed = C->shoesUpAdsSpeed;
	Alpha = C->shoesUpAlpha;
	Radius = C->fallRadius;
}

void SHOES_UP::draw(){
	drawImage(Img, Px, Py, 0);
}




