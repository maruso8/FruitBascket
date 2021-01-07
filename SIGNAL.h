#pragma once
#include"IMG.h"
#include"CONTAINER.h"


class SIGNAL :public IMG {
private:
	int SelectFleamImg = 0;
	int LevelImg[3] = {};
	float LevelPx = 0;
	float LevelPy = 0;
	float LevelSelectPx = 0;
	float LevelSelectPy = 0;
	float Height = 0;

	float Target = 0;
	float current = 0;

	float LevelTarget = 0;
	float Levelcurrent = 0;

public:
	SIGNAL() {
		Img = C->signalImg;
		SelectFleamImg = C->levelSelectFleamImg;
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
		Target = Py;
		current = Py;
		LevelTarget = LevelSelectPy;
		Levelcurrent = LevelSelectPy;

	}

	void draw(float py) {
		Target = Py + py;
		current += (Target - current) / 10;
		drawImage(Img, Px, current);
	}

	void Leveldraw(float py, int select) {
		drawImage(FreamImg, FreamPx, FreamPy);

		for (int i = 0; i < 3; i++) {
			if (select == i) {
				drawImage(SelectFleamImg, LevelPx, LevelPy + i * Height, COLOR(Rad, Green, Blue, Alpha));
			}
			else drawImage(SelectFleamImg, LevelPx, LevelPy + i * Height, COLOR(Rad, Green, Blue, Alpha / 2));
			

			drawImage(LevelImg[i], LevelPx, LevelPy + i * Height);
		}
		LevelTarget = LevelSelectPy + Height * py;
		Levelcurrent += (LevelTarget - Levelcurrent) / 10;
		drawImage(Img, LevelSelectPx, Levelcurrent);
	}
};