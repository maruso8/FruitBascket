#include"IMG.h"
#include"CONTAINER.h"
#include"SOUND_MANEGER.h"
#include"SCORE_RANK.h"


SCORE_RANK::SCORE_RANK() {
	SoundManeger = new SOUND_MANEGER;

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

SCORE_RANK::~SCORE_RANK() {
	delete SoundManeger;
}


void SCORE_RANK::rankInit(){
	RankCnt = 0;
	rankNum = 0;
	SE = 0;
}


void SCORE_RANK::draw() {
	drawImage(FreamImg, FreamPx, FreamPy, COLOR(Rad, Green, Blue, Alpha));
}

bool SCORE_RANK::drawRankScore(int Level, int score) {

	if (SE == 0) { SoundManeger->getScoreWindowAppearSE(); SE++; }

	//ランキング処理開始----------------------------------------------------------------

	for (int i = 0; i < 3; i++) {
		RankScore[i] = C->rank[Level].RankScore[i];
	}

	//1位2位3位の画像
	for (int i = 0; i < RankNum; i++) {
		drawImage(RankImg[i], ScorePx, ScorePy + (i * ScoreSpace));
	}


	//プレイヤースコアの保存

	//自分のスコア表示
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

	//ランキングのスコア表示
	if (RankCnt >= 45 && RankNum != rankNum) { SoundManeger->getScoreAppearSE(); rankNum++; RankCnt = 0; }
	else { RankCnt++; }


	for (int i = 0; i < rankNum; i++) {
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

	if (rankNum==RankNum) { return true; }
	return false;
}

void SCORE_RANK::skipRankDraw() {
	rankNum = RankNum;
}