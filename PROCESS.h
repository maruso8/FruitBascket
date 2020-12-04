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
	~PROCESS();
	void ProcInit();
	void seveLoad(int Level,int score);
	int score(char Id,int score,int Level);
	int item(char Id);
	void fallFruit(int time, int score,int Level);
	void fallItem();
	char collision();
	void deleteAlpha();
	void gamedraw();
	void gameSelect(int GameTitel);
	void scoredraw();
	bool FadeIn();
	bool Fadeout();

	void flagOn();
	void flagOff();
	bool flag();

	static PROCESS* getInstans();
	static PROCESS* Delete();


private:
	PROCESS();


	static PROCESS* Proc;
	static CONTAINER* C;
	static FALL_MANEGER* FallManeger;
	static TITLE_MANEGER* TitelManeger;
	static SOUND_MANEGER* SoundManeger;

	int Bgm = 0;
	char Id = 0;
	int FallFruitCnt = 0;
	int FallLotFruitCnt = 0;
	int FallItemCnt = 0;
	int TimeUpCnt = 0;
	int Flag = 0;

	int Title = 0;
	int end = 0;

	int GameLevel = 0;
	int GameTitle = 5;
	int GameCheck = 0;
	int GameLevelCheck = 0;

	char Name[256] = {};
	CHARACTER* Player = 0;
	CHECK* check = 0;
	FADE* Fade = 0;
	
	NEEDLE* Needle = 0;


};

