#pragma once


class IMG;

class SCORE :public IMG {
public:
	SCORE();
	void scoredraw(int score);
private:
	int ScoreImg[10] = { 0 };
};