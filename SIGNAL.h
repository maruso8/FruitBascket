#pragma once
#include"IMG.h"
#include"CONTAINER.h"


class SIGNAL :public IMG {
private:
	int LevelImg[3] = {};
	float LevelPx = 0;
	float LevelPy = 0;
	float LevelSelectPx = 0;
	float LevelSelectPy = 0;
	float Height = 0;

public:
	SIGNAL() {
		Img = C->signalImg;
		for (int i = 0; i < 3; i++) {
			LevelImg[i] = C->selectLevelImg[i];
		}
		Px = C->signalPx;
		Py = C->signalPy;
		LevelPx = C->LevelPx;
		LevelPy = C->LevelPy;
		LevelSelectPx = C->LevelSelectPx;
		LevelSelectPy = C->LevelSelectPy;
		Height = C->LevelSelectHeight;
	}

	void draw(float py) {
		drawImage(Img, Px, py + Py);
	}

	void Leveldraw(float py) {
		drawImage(FreamImg, FreamPx, FreamPy);
		for (int i = 0; i < 3; i++) {
			drawImage(LevelImg[i], LevelPx, LevelPy + i * Height);
		}
		drawImage(Img, LevelSelectPx, LevelSelectPy + Height * py);
	}
};