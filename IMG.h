#pragma once

class CONTAINER;

class IMG {
public:
	IMG();
	~IMG();
	virtual void draw(float px = 0);
	virtual void selectDraw(int select) {};
	virtual void changeTitleImg() {};
	virtual void changeGameImg() {};
	virtual void drawRankScore(int score) {};
	virtual void Leveldraw(float py,int select) {};
	void fadeIn();
	void fadeOut();
	void translucentIn();
	void translucentOut();
	float alpha();
	virtual float selectHeight();

protected:
	int Img = 0;
	int FreamImg = 0;
	int TitleImg = 0;
	int GameImg = 0;

	float Px = 0;
	float Py = 0;
	float FreamPx = 0;
	float FreamPy = 0;
	float SelectHeight = 0;

	float Rad = 1;
	float Green = 1;
	float Blue = 1;
	float Alpha = 1;


	static CONTAINER* C;
};