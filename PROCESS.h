#pragma once

class CONTAINER;

class PROCESS {
public:
	void seveLoad(int Level,int score);

	static void setContainer(CONTAINER* c) { C = c; };

private:
	char Name[256] = {};
	static CONTAINER* C;
};