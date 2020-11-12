#include"FALL.h"
#include"FALL_ROT_APPLE.h"
#include"CONTAINER.h"


ROT_APPLE::ROT_APPLE() {
	Id = C->rotAppleId;
	Img = C->rotAppleImg;
	AdsSpeed = C->rotAppleAdsSpeed;
	Alpha = C->rotAppleAlpha;
	Radius = C->fallRadius;
	Score = C->rotAppleScore;

}

void ROT_APPLE::draw(){
	drawImage(Img, Px, Py, 0);
}




