#include"IMG.h"
#include"CONTAINER.h"
#include"SCORE.h"


SCORE::SCORE() {
	Img = C->scoreImg;
	for (int i = 0; i < C->NumOfNum; i++) {
		ScoreNumImg[i] = C->scoreNumImg[i];
	}
	Px = C->scorePx;
	Py = C->scorePy;
}

void SCORE::scoredraw(int score) {

	drawImage(Img, 0, 0);

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
		drawImage(ScoreNumImg[num], Px + 75 * i, Py);
		place /= 10;

	}
}
