#pragma once
class CONTAINER;

class FALL {
public:

	FALL(char* name);

	virtual void appear(float px = 0, float py = 0);
	virtual bool update();
	void draw();
	void deleteAlpha();
	
	virtual float top();
	float bottom();
	virtual float left();
	virtual float right();

	float px();
	float py();

	char id();
	float alpha();

	void setImg(const char* name);
	void setId(const char* name);
	void setAdsSpeed(const char* name);
	void setRadius();
	void setAlpha(const char* name);
	void setScore(const char* name);
	

	int score();
	static void setContainer(CONTAINER* c) { C = c; }

protected:
	int Img = 0;
	int Score = 0;
	char Id = 0;
	float Px = 0.0f;
	float Py = 0.0f;
	float AdsSpeed = 0.0f;
	float Alpha=0.0f;
	float Radius = 0.0f;
	char Name[256] = { 0 };

	static CONTAINER* C;

};