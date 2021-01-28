#pragma once

class CONTAINER;
class CHARACTER;
class FALL_MANEGER;
class CHECK;
class FADE;
class TITLE_MANEGER;
class SOUND_MANEGER;
class NEEDLE;

class PROCESS {
public:
	PROCESS();
	~PROCESS();
	void ProcInit();
	int score(char Id, int score, int Level);
	int item(char Id);
	void fallFruit(int time, int score, int Level);
	void fallItem();
	char collision();
	void deleteAlpha();
	void gamedraw();
	void gameSelect(int GameTitel);
	void scoredraw();
	bool FadeIn();
	bool Fadeout();
	bool translucentIn();
	bool translucentOut();

	void flagOn();
	void flagOff();
	bool flag();

private:

	static CONTAINER* C;
	FALL_MANEGER* FallManeger = 0;
	TITLE_MANEGER* TitelManeger = 0;
	SOUND_MANEGER* SoundManeger = 0;

	int Bgm = 0;
	char Id = 0;
	int FallFruitCnt = 0;
	int FallLotFruitCnt = 0;
	int FallItemCnt = 0;
	int TimeUpCnt = 0;
	int Flag = 0;

	int Title = 0;
	int end = 0;

	float LevelTimes = 0;


	int GameLevel = 0;
	int GameCheck = 0;
	int GameLevelCheck = 0;



	char Name[256] = {};
	CHARACTER* Player = 0;
	CHECK* check = 0;
	FADE* Fade = 0;

	NEEDLE* Needle = 0;


};

