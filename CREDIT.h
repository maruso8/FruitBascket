#pragma once
#include"IMG.h"
#include"CONTAINER.h"


class CREDIT :public IMG {
public:
	CREDIT() {
		Img = C->creditImg;
		Px = C->creditPx;
		Py = C->creditPy;

	}
};
