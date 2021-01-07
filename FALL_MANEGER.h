#pragma once

class CONTAINER;
class FALL;

class FALL_MANEGER {
public:
	FALL_MANEGER();
	~FALL_MANEGER();
	void appear(char Id);
	virtual void update();
	void draw();
	void deleteAlpha();
	char collision(float top, float bottom, float left, float right);
	int getScore(char id);

	



private:
	
	int Total = 0;
	FALL** AllFall;
	static CONTAINER* C;


};