#pragma once

class CONTAINER;

class CHARACTER {
public:
	
	virtual void update();
	void draw();
	float top();
	float bottom();
	float left();
	float right();

	void speedUp();
	void speedDown();
	float adsSpeed();

	static void setContainer(CONTAINER* c) { C = c; }

protected:
	int Img = 0;
	float Px = 0;
	float Py = 0;
	float Widht = 0;
	float Height = 0;
	float AdsSpeed = 0;

	float Top = 0.0f;
	float Bottom = 0.0f;
	float Left = 0.0f;
	float Right = 0.0f;


	static CONTAINER* C;
};