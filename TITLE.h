#pragma once
#include"IMG.h"
#include"CONTAINER.h"


class TITLE :public IMG {
public:
	TITLE() {
		Img = C->titleImg;
		Px = C->titlePx;
		Py = C->titlePy;
	}

	void draw(float px) {
		drawImage(Img, Px, Py);
	}

};