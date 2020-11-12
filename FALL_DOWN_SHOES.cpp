#include"FALL.h"
#include"FALL_DOWN_SHOES.h"
#include"CONTAINER.h"


SHOES_DOWN::SHOES_DOWN() {
	Id = C->shoesDownId;
	Img = C->shoesDownImg;
	AdsSpeed = C->shoesDownAdsSpeed;
	Alpha = C->shoesDownAlpha;
	Radius = C->fallRadius;
}

void SHOES_DOWN::draw(){
	drawImage(Img, Px, Py, 0);
}




