#pragma once
#include"IMG.h"
#include"CONTAINER.h"


class SIGNAL :public IMG {
public:
	SIGNAL() {
		Img = C->signalImg;
		Px = C->signalPx;
		Py = C->signalPy;

	}

	void draw(float py) {
		drawImage(Img, Px, py + Py);
	}
};
