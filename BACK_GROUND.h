#pragma once
#include"IMG.h"
#include"CONTAINER.h"


class BACK_GROUND :public IMG {
public:
	BACK_GROUND() {
		Img = C->backGroundImg;
		TitleImg = C->backGroundImg;
		GameImg = C->gameBackGroundImg;
		Px = C->backGroundPx;
		Py = C->backGroundPy;
	}

	void draw(float px) {
		drawImage(Img, Px, Py);
	}


	void changeTitleImg() { Img = TitleImg; }

	void changeGameImg() {Img = GameImg;}

};