#pragma once


class IMG;

class TIME_LIMIT :public IMG {
public:
	TIME_LIMIT();
	void timeLimitdraw(int Time);
private:
	int TimeImg[10] = { 0 };
};