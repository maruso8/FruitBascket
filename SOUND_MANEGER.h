#pragma once

class SOUND_MANEGER {
public:
	SOUND_MANEGER();
	void getTitelBgm();
	void getGameBgm();
	void getScoreBgm();

	//SEを作って確認する！！
	void getSelectSE();
	void getDecisionSE();
	void getFruitGetSE();
	void getRotFruitGetSE();
	void getTimeUpSE();
	void getTimeDownSE();
	void getShoesGetSE();
	void getTimwNotice();
	void getScoreAppearSE();
	void getScoreWindowAppearSE();

	void stopBgm();


private:

	//BGM
	int TitelBgm = 0;
	int GameBgm = 0;
	int ScoreBgm = 0;
	//決定と選択音
	int SelectSE = 0;
	int DecisionSE = 0;
	//ゲーム関連SE
	int FruitGetSE = 0;
	int RotFruitGetSE = 0;
	int TimeUpSE = 0;
	int TimeDownSE = 0;
	int ShoesGetSE = 0;
	int TimwNotice = 0;
	//スコア関連SE
	int ScoreAppearSE = 0;
	int ScoreWindowAppearSE = 0;


};