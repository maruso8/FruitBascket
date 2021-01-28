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

private:
	static CONTAINER* C;
	
	
	SOUND_MANEGER* SoundManeger;
	IMG* BackGround = 0;
	IMG* Title = 0;
	IMG* Select = 0;
	IMG* Signal = 0;

	int SE = 0;

	int Time = 0;



	int Img = 0;
	float Px = 0;
	float Py = 0;
	int Flag = 0;
	int HowToPage = 0;


};