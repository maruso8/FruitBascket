#include"IMG.h"
#include"CONTAINER.h"
#include"SCORE.h"

#include"graphic.h"
#include"debugStr.h"

SCORE::SCORE() {
	Img = C->appleImg;
	for (int i = 0; i < 10; i++) {
		ScoreImg[i] = C->scoreImg[i];
	}
	Px = C->scorePx;
	Py = C->scorePy;
}

void SCORE::scoredraw(int score) {


	int place = 10000;
	int num = 0;

	for(int i=0;i<5;i++){
		if (score < 0) {
			score = 0;
		}
		num = score / place;
		score %= place;
		if (num == 0 && place > 1000) {
			place /= 10;
			continue;
		}
		drawImage(ScoreImg[num], Px + 75 * i, Py);
		place /= 10;
		setDebugStr("SCORE=%d",num);

	}
}
