#pragma once


class IMG;

class SCORE_IMG :public IMG {
public:
	SCORE_IMG();
	void drawRankScore(int score);
	void draw();
private:
	int ScoreNumImg[10] = { 0 };
	int RankImg = 0;
	int RankNum = 0;
	int Rank[3] = { 0 };
	float RankPx = 0;
	float RankPy = 0;
	float RankWidth = 0;
	float ScorePx = 0;
	float ScorePy = 0;
	float ScoreSpace = 0;
	int place = 0;
	int num = 0;
	float PlayerScorePx = 0;
	float PlayerScorePy = 0;
};
