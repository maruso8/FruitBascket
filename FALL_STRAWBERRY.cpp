#include"FALL.h"
#include"FALL_STRAWBERRY.h"
#include"CONTAINER.h"


STRAWBERRY::STRAWBERRY() {
	Id = C->strawberryId;
	Img = C->strawberryImg;
	AdsSpeed = C->strawberryAdsSpeed;
	Alpha = C->strawberryAlpha;
	Radius = C->fallRadius;
	Score = C->strawberryScore;
}

void STRAWBERRY::draw(){
	drawImage(Img, Px, Py, 0);
}




