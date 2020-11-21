#pragma once

class CONTAINER;
class CHARACTER;
class FALL_MANEGER;
class CHECK;
class IMG;
class FADE;
class TITLE_MANEGER;
class SCORE;
class TIME_LIMIT;
class SCORE_IMG;
class PROCESS;

class GAME {
public:
	GAME();
	~GAME();
	void main();
	void gameInit();
	bool end();

private:

	int Bgm = 0;



	int FallFruitCnt = 0;
	int FallItemCnt = 0;
	int FallLotFruitCnt = 0;

	int PlayerScore = 0;
	int TimeUpCnt = 0;


	char Id = 0;



	int GameCheck = 0;
	int TimeCnt = 0;
	float SelectHeight = 0;



	CONTAINER* C = 0;
	CHARACTER* Player = 0;
	FALL_MANEGER* FallManeger = 0;
	CHECK* check = 0;
	TITLE_MANEGER* TitelManeger = 0;
	IMG* Fade = 0;
	SCORE* Score = 0;
	TIME_LIMIT* TimeLimit = 0;
	SCORE_IMG* ScoreImg = 0;
	PROCESS* Process = 0;



	enum GAME_START {GAME_START_TITEL,GAME_START_PLAY,GAME_START_SCORE};
	enum GAME_TITEL {GAME_PLAY, GAME_WAIT,GAME_HowToPlay, GAME_CREDIT, GAME_END };
	enum GAME_LEVEL { GAME_LEVEL_EASY = 0, GAME_LEVEL_NORMAL = 1, GAME_LEVEL_HARD = 2 };


	GAME_START GameStart = GAME_START_TITEL;//GAME_START_TITEL;
	GAME_TITEL GameTitel = GAME_PLAY;
	GAME_LEVEL GameLevel = GAME_LEVEL_EASY;
};