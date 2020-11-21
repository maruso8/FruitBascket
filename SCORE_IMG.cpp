#include"IMG.h"
#include"CONTAINER.h"
#include"SCORE_IMG.h"


SCORE_IMG::SCORE_IMG() {
	FreamImg = C->scoreFreamImg;
	FreamPx = C->freamPx;
	FreamPy = C->freamPy;

	for (int i = 0; i < 3; i++) {
		RankImg[i] = C->rankNumImg[i];
	}
	RankPx = C->rankPx;
	RankPy = C->rankPy;
	RankNum = C->rankNum;
	RankWidth = C->rankWidth;

	ScorePx = C->scoreImgPx;
	ScorePy = C->scoreImgPy;
	ScoreSpace = C->scoreSpace;

	PlayerScorePx = C->PlayerScorePx;
	PlayerScorePy = C->PlayerScorePy;


	for (int i = 0; i < C->NumOfNum; i++) {
		ScoreNumImg[i] = C->scoreNumImg[i];
	}

}

void SCORE_IMG::draw() {
	drawImage(FreamImg, FreamPx, FreamPy, COLOR(Rad, Green, Blue, Alpha));
}

void SCORE_IMG::drawRankScore(int score) {


	//�����L���O�����J�n----------------------------------------------------------------

	for (int i = 0; i < 3; i++) {
		RankScore[i] = C->rank[i].RankScore;
	}
	
	//1��2��3�ʂ̉摜
	for (int i = 0; i < RankNum; i++) {
		drawImage(RankImg[i], ScorePx, ScorePy + (i * ScoreSpace));
	}


	//�v���C���[�X�R�A�̕ۑ�

	//�����̃X�R�A�\��
	place = 10000;
	num = 0;
	for (int j = 0; j < 5; j++) {
		if (score < 0) {
			score = 0;
		}
		num = score / place;
		score %= place;
		if (num == 0 && place > 1000) {
			place /= 10;
			continue;
		}
		drawImage(ScoreNumImg[num], PlayerScorePx + RankWidth * j, PlayerScorePy);
		place /= 10;
	}

	//�����L���O�̃X�R�A�\��

	for (int i = 0; i < RankNum; i++) {
		place = 10000;
		num = 0;

		for (int j = 0; j < 5; j++) {
			if (RankScore[i] < 0) {
				RankScore[i] = 0;
			}
			num = RankScore[i] / place;
			RankScore[i] %= place;
			if (num == 0 && place > 1000) {
				place /= 10;
				continue;
			}
			drawImage(ScoreNumImg[num], RankPx + 75 * j, RankPy + (i * ScoreSpace));
			place /= 10;
		}
	}
}