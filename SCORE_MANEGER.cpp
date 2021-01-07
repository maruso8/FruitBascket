#include"CONTAINER.h"
#include"IMG.h"
#include"SCORE.h"
#include"SCORE_RANK.h"
#include"SCORE_MANEGER.h"


CONTAINER* SCORE_MANEGER::C = 0;

SCORE_MANEGER::SCORE_MANEGER() {
	C = CONTAINER::getInstance();
	Score = new SCORE;
	ScoreRank = new SCORE_RANK;
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


void SCORE_MANEGER::scoreRankInit(int GameLevel, int PlayerScore) {
	C->saveData(GameLevel, PlayerScore);
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