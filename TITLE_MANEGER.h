#pragma once

class CONTAINER;
class IMG;

class TITLE_MANEGER {
public:
	TITLE_MANEGER();
	~TITLE_MANEGER();
	void backGround_Draw();
	void title_Draw(int gameCheck);
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

	int Total = 0;
	static CONTAINER* C;
};