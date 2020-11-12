#pragma once

class CONTAINER;
class CHARACTER;
class FALL;
class FALL_MANEGER;
class CHECK;
class IMG;
class TITLE_MANEGER;
class SCORE;
class TIME_LIMIT;

class GAME {
public:
	GAME();
	~GAME();
	void main();
	bool end();

private:

	int flag = 0;


	int scoreImage = 0;

	int Bgm = 0;

	int FallFruitCnt = 0;
	int FallItemCnt = 0;
	int FallLotFruitCnt = 0;

	int PlayerScore = 0;

	char Id = 'a';

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


	enum GAME_START {GAME_START_TITEL,GAME_START_PLAY,GAME_START_SCORE};
	enum GAME_TITEL {GAME_PLAY, GAME_WAIT,GAME_HowToPlay, GAME_CREDIT, GAME_END };
	enum GAME_LEVEL{GAME_LEVEL_EASY, GAME_LEVEL_NORMAL, GAME_LEVEL_HARD};


	GAME_START GameStart = GAME_START_TITEL;//GAME_MAIN_PLAY;
	GAME_TITEL GameTitel = GAME_PLAY;
	GAME_LEVEL GameLevel = GAME_LEVEL_EASY;
};