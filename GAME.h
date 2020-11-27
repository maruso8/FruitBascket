#pragma once

class CONTAINER;
class CHECK;
class IMG;
class FADE;
class TITLE_MANEGER;
class SCORE;
class TIME_LIMIT;
class SCORE_IMG;
class PROCESS;
class SOUND_MANEGER;

class GAME {
public:
	GAME();
	~GAME();
	void main();
	void gameInit();
	int selectLevel();
	bool end();

private:


	int PlayerScore = 0;
	char Id = 0;

	int Titel = 5;
	int GameCheck = 0;
	int GameLevelCheck = 0;

	int TimeCnt = 0;
	int TimwNotice = 0;



	CONTAINER* C = 0;
	CHECK* check = 0;
	TITLE_MANEGER* TitelManeger = 0;
	SCORE* Score = 0;
	TIME_LIMIT* TimeLimit = 0;
	SCORE_IMG* ScoreImg = 0;
	PROCESS* Proc = 0;
	SOUND_MANEGER* SoundManeger = 0;


	enum GAME_START { GAME_START_TITEL = 0, GAME_START_WAIT=1, GAME_START_PLAY = 2, GAME_START_SCORE = 3 };
	enum GAME_TITEL { GAME_PLAY, GAME_PROCESS,};
	enum GAME_LEVEL { GAME_LEVEL_EASY = 0, GAME_LEVEL_NORMAL = 1, GAME_LEVEL_HARD = 2, GAME_LEVEL_NULL = 3};


	GAME_START GameStart = GAME_START_TITEL;//GAME_START_TITEL;
	GAME_TITEL GameTitel = GAME_PLAY;
	GAME_LEVEL GameLevel = GAME_LEVEL_NULL;
};