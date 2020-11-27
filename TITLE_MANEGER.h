#pragma once

class CONTAINER;
class IMG;
class SOUND_MANEGER;

class TITLE_MANEGER {
public:
	TITLE_MANEGER();
	~TITLE_MANEGER();
	void backGround_Draw();
	void title_Draw(int gameCheck);
	void Level_Draw(int LevelCheck);
	void changeTitleImg();
	void changeGameImg();
	bool howToPlay();
	bool credit();


	static void setContainer(CONTAINER* c) { C = c; }

private:
	
	IMG* BackGround = 0;
	IMG* Title = 0;
	IMG* Select = 0;
	IMG* HowToPlay = 0;
	IMG* Credit = 0;
	IMG* Signal = 0;
	SOUND_MANEGER* SoundManeger = 0;

	int SE = 0;
	static CONTAINER* C;
};