#pragma once


class IMG;

class SCORE :public IMG {
public:
	SCORE();
	void scoredraw(int score);
private:
	int ScoreNumImg[10] = { 0 };
};