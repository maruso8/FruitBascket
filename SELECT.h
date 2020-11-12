#pragma once

class IMG;
class CONTAINER;

class SELECT : public IMG {
public:
	SELECT();

	void draw(float px = 0);

private:
	int SelectImg[4] = {0,0,0,0};
	int TotalSelect = 0;

};

