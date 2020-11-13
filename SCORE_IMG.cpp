#include"IMG.h"
#include"CONTAINER.h"
#include"SCORE_IMG.h"


SCORE_IMG::SCORE_IMG() {
	FreamImg = C->scoreFreamImg;
	FreamPx = C->freamPx;
	FreamPy = C->freamPy;

	RankImg = C->scoreImg;
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


	//�����L���O���3�l�̃X�R�A��ǂݍ���

	char name[256];
	for (int i = 0; i < RankNum; i++) {
		sprintf_s(name, "No.%d", i + 1);
		Rank[i] = C->getIData(name);
	}

	for (int i = 0; i < RankNum; i++) {
		drawImage(RankImg, ScorePx, ScorePy + (i * ScoreSpace));
	}


	//�v���C���[�X�R�A�̕ۑ�
	int tmp = score;

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
	//�v���C���[�X�R�A�̓ǂݍ���
	score = tmp;

	//�X�R�A�̔�r
	for (int i = 0; i < RankNum; i++) {
		if (score > Rank[i]) {
			int work = Rank[i];
			Rank[i] = score;
			score = work;
		}
	}


	//�����L���O�̃X�R�A�\��

	for (int i = 0; i < RankNum; i++) {
		place = 10000;
		num = 0;

		for (int j = 0; j < 5; j++) {
			if (Rank[i] < 0) {
				Rank[i] = 0;
			}
			num = Rank[i] / place;
			Rank[i] %= place;
			if (num == 0 && place > 1000) {
				place /= 10;
				continue;
			}
			drawImage(ScoreNumImg[num], RankPx + 75 * j, RankPy + (i * ScoreSpace));
			place /= 10;
		}
	}
}