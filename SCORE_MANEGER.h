#pragma once

class IMG;
class SCORE;
class SCORE_MANEGER;

class SCORE_MANEGER {
public:
	~SCORE_MANEGER();
	void scoredraw(int score);
	void drawScoreRank();
	void scoreRankInit();
	bool scoreRankDraw(int Level, int score);
	void skip();
	static SCORE_MANEGER* getInstans();
	static SCORE_MANEGER* Delete();


private:
	SCORE_MANEGER();
	static SCORE_MANEGER* ScoreManeger;

	SCORE* Score = 0;
	SCORE_RANK* ScoreRank = 0;



};
