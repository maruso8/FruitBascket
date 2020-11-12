#pragma once
class CONTAINER;
class DRAW;

class FALL {
public:

	void appear();
	virtual void update();
	void draw();
	void deleteAlpha();
	
	float top();
	float bottom();
	float left();
	float right();


	char id();
	float alpha();
	int score();
	static void setContainer(CONTAINER* c) { C = c; }

protected:
	DRAW* Draw;
	int Img = 0;
	int Score = 0;
	char Id = 0;
	float Px = 0.0f;
	float Py = 0.0f;
	float AdsSpeed = 0.0f;
	float Alpha=0.0f;
	float Radius = 0.0f;

	static CONTAINER* C;
};