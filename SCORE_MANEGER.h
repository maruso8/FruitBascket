#pragma once

class FADE;
class SCORE;
class SCORE_MANEGER;
class CONTAINER;

class SCORE_MANEGER {
public:
	SCORE_MANEGER();
	~SCORE_MANEGER();
	void scoredraw(int score);
	void drawScoreRank();
	void scoreRankInit(int GameLevel, int PlayerScore);
	bool scoreRankDraw(int Level, int score);
	void skip();
	


private:

	static CONTAINER* C;
	SCORE* Score = 0;
	SCORE_RANK* ScoreRank = 0;
	FADE* Fade = 0;


};
