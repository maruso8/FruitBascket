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


	//ランキング処理開始----------------------------------------------------------------


	//ランキング上位3人のスコアを読み込む

	char name[256];
	for (int i = 0; i < RankNum; i++) {
		sprintf_s(name, "No.%d", i + 1);
		Rank[i] = C->getIData(name);
	}
	//1位2位3位の画像
	for (int i = 0; i < RankNum; i++) {
		drawImage(RankImg[i], ScorePx, ScorePy + (i * ScoreSpace));
	}


	//プレイヤースコアの保存
	int tmp = score;

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
	//プレイヤースコアの読み込み
	score = tmp;

	//スコアの比較
	for (int i = 0; i < RankNum; i++) {
		if (score > Rank[i]) {
			int work = Rank[i];
			Rank[i] = score;
			score = work;
		}
	}


	//ランキングのスコア表示

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