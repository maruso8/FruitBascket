#pragma once

class CONTAINER;
class CHECK;
class IMG;
class FADE;
class TITLE_MANEGER;
class SCORE;
class TIME_LIMIT;
class SCORE_RANK;
class SCORE_MANEGER;
class PROCESS;
class SOUND_MANEGER;

class GAME {
public:
	GAME();
	~GAME();
	void main();
	int selectLevel();
	void gameInit();
	void titelInit();
	bool end();

private:


	int PlayerScore = 0;
	char Id = 0;

	int Title = 5;
	int GameTitle = 0;
	int GameCheck = 0;
	int GameLevelCheck = 0;

	int TimeCnt = 0;
	int TimwNotice = 0;



	CONTAINER* C = 0;
	CHECK* check = 0;
	TITLE_MANEGER* TitelManeger = 0;
	TIME_LIMIT* TimeLimit = 0;
	PROCESS* Proc = 0;
	SOUND_MANEGER* SoundManeger = 0;
	SCORE_MANEGER* ScoreManeger = 0;

	enum GAME_START { GAME_STATE_TITEL = 0, GAME_STATE_PLAY = 2, GAME_STATE_SCORE = 3,GAME_STATE_END=4 };
	enum GAME_LEVEL { GAME_LEVEL_EASY = 0, GAME_LEVEL_NORMAL = 1, GAME_LEVEL_HARD = 2, GAME_LEVEL_NULL = 3};


	GAME_START GameStart = GAME_STATE_TITEL;//GAME_STATE_TITEL;
	GAME_LEVEL GameLevel = GAME_LEVEL_NULL;
};