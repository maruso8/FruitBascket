#include"FALL.h"
#include"FALL_ROT_ORANGE.h"
#include"CONTAINER.h"


ROT_ORANGE::ROT_ORANGE() {
	Id = C->rotOrangeId;
	Img = C->rotOrangeImg;
	AdsSpeed = C->rotOrangeAdsSpeed;
	Alpha = C->rotOrangeAlpha;
	Radius = C->fallRadius;
	Score = C->rotOrangeScore;

}

void ROT_ORANGE::draw(){
	drawImage(Img, Px, Py, 0);
}




