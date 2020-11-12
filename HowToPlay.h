#pragma once
#include"IMG.h"
#include"CONTAINER.h"


class HOWTOPLAY :public IMG {
public:
	HOWTOPLAY() {
		Img = C->howToPlayImg;
		Px = C->howToPlayPx;
		Py = C->howToPlayPy;
	}
};
