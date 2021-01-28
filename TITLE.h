#pragma once
#include"IMG.h"
#include"CONTAINER.h"


class TITLE :public IMG {
public:
	TITLE() {
		Img = C->titleImg;
		Px = C->titlePx + C->TitleScroll;
		Py = C->titlePy;
	}

	void draw(float px) {
		drawImage(Img, Px, Py);

		if (Px <= C->titlePx) { Px = C->titlePx; }
		else Px -= C->TitleScroll / 60;
	}

};