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
	void seveLoad(int Level,int score);
	int score(char Id,int score);
	int item(char Id);
	void fallFruit(int time, int score,int Level);
	void fallItem();
	char collision();
	void deleteAlpha();
	void gamedraw();
	void gameSelect(int GameTitel);

	bool FadeIn();
	bool Fadeout();


	static void setContainer(CONTAINER* c) { C = c; };

private:
	int Bgm = 0;
	char Id = 0;
	int FallFruitCnt = 0;
	int FallLotFruitCnt = 0;
	int FallItemCnt = 0;
	int TimeUpCnt = 0;


	char Name[256] = {};
	CHARACTER* Player = 0;
	FALL_MANEGER* FallManeger = 0;
	CHECK* check = 0;
	FADE* Fade = 0;
	TITLE_MANEGER* TitelManeger = 0;
	SOUND_MANEGER* SoundManeger = 0;
	NEEDLE* Needle = 0;

	static CONTAINER* C;
};

