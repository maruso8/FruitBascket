#pragma once
class IMG;
class SOUND_MANEGER;

class SCORE_RANK :public IMG {
public:
	SCORE_RANK();
	~SCORE_RANK();
	void rankInit();
	bool drawRankScore(int Level,int score);
	void skipRankDraw();
	void draw();
private:
	SOUND_MANEGER* SoundManeger = 0;

	int ScoreNumImg[10] = { 0 };
	int RankImg[3] = { 0 };
	int RankNum = 0;
	int RankScore[3] = { 0 };
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

	int RankCnt = 0;
	int rankNum = 0;
	int SE = 0;
};
