#include"FALL.h"
#include"FALL_BANANA.h"
#include"CONTAINER.h"


BANANA::BANANA() {
	Id = C->bananaId;
	Img = C->bananaImg;
	AdsSpeed = C->bananaAdsSpeed;
	Alpha = C->bananaAlpha;
	Radius = C->fallRadius;
	Score = C->bananaScore;
}

void BANANA::draw(){
	drawImage(Img, Px, Py, 0);
}




