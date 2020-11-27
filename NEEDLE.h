#pragma once
#include"FALL.h"

class NEEDLE :public FALL {
	int NeedleCnt = 0;
public:
	using FALL::FALL;

	void appear(float px,float py) {
		Px = px;
		Py = py;
		NeedleCnt = 120;
		Alpha = 1;
	}

	bool update() {
		if (NeedleCnt == 0) {
			Alpha = 0;
		}
		else NeedleCnt--;
		return false;
	}

	float top() { return Py - Radius - 150; }
	float left() { return Px - Radius+30; }
	float right() { return Px + Radius-30; }

};