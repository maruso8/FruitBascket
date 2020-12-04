#include"IMG.h"
#include"SCORE.h"
#include"SCORE_RANK.h"
#include"SCORE_MANEGER.h"


SCORE_MANEGER* SCORE_MANEGER::ScoreManeger = 0;

SCORE_MANEGER::SCORE_MANEGER() {
	Score = new SCORE;
	ScoreRank = new SCORE_RANK;

}



SCORE_MANEGER* SCORE_MANEGER::getInstans() {
	if (!ScoreManeger) {
		ScoreManeger = new SCORE_MANEGER;
	}
	return ScoreManeger;
}

SCORE_MANEGER* SCORE_MANEGER::Delete() {

	if (ScoreManeger) {
		delete ScoreManeger;
		ScoreManeger = 0;
	}
	return ScoreManeger;
}



SCORE_MANEGER::~SCORE_MANEGER() {
	delete Score;
	delete ScoreRank;
}

void SCORE_MANEGER::scoredraw(int score) {
	Score->scoredraw(score);
}

void SCORE_MANEGER::drawScoreRank() {
	ScoreRank->draw();
}


void SCORE_MANEGER::scoreRankInit() {
	ScoreRank->rankInit();
}

bool SCORE_MANEGER::scoreRankDraw(int Level, int score) {
	ScoreRank->draw();
	if (ScoreRank->drawRankScore(Level, score)) { return true; }
	else { return false; }

}
void SCORE_MANEGER::skip() {
	ScoreRank->skipRankDraw();
}