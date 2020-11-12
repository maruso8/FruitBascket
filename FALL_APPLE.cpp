#include"FALL.h"
#include"FALL_APPLE.h"
#include"CONTAINER.h"


APPLE::APPLE() {
	Id = C->appleId;
	Img = C->appleImg;
	AdsSpeed = C->appleAdsSpeed;
	Alpha = C->appleAlpha;
	Radius = C->fallRadius;
	Score = C->appleScore;

}

void APPLE::draw(){
	drawImage(Img, Px, Py, 0);
}




