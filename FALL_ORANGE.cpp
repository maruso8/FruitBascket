#include"FALL.h"
#include"FALL_ORANGE.h"
#include"CONTAINER.h"


ORANGE::ORANGE() {
	Id = C->orangeId;
	Img = C->orangeImg;
	AdsSpeed = C->orangeAdsSpeed;
	Alpha = C->orangeAlpha;
	Radius = C->fallRadius;
	Score = C->orangeScore;

}

void ORANGE::draw(){
	drawImage(Img, Px, Py, 0);
}




