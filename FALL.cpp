#include"FALL.h"
#include"CONTAINER.h"
#include<stdlib.h>


CONTAINER* FALL::C = 0;


FALL::FALL(char* name) {
	setImg(name);
	setId(name);
	setAdsSpeed(name);
	setRadius();
	setAlpha(name);
	setScore(name);
}



void FALL::appear(float px, float py){//1770,1180,365
	Px = rand() % 1380 + 265;
	Py = 0;
	Alpha = 1;
};

bool FALL::update() {
	Py += AdsSpeed;
	if (C->windowHeight < Py) {
		Alpha = 0;
		if (Id == 'l') {
			return true;
		}
	}
	return false;
}


void FALL::draw() {
	drawImage(Img, Px, Py, 0);
}

void FALL::deleteAlpha() {Alpha = 0.0f;}

float FALL::top() { return Py - Radius+20; }
float FALL::bottom(){ return Py + Radius; }
float FALL::left(){ return Px - Radius; }
float FALL::right(){ return Px + Radius; }
int FALL::score() { return Score; };
float FALL::px() { return Px; }
float FALL::py() { return Py; }
char FALL::id() { return Id; }
float FALL::alpha() { return Alpha; }


void FALL::setImg(const char* name){
	sprintf_s(Name, "%sImg.png", name);
	Img = C->getIData(Name);
}
void FALL::setId(const char* name){
	sprintf_s(Name, "%sId",name);
	Id = C->getCData(Name);
}
void FALL::setAdsSpeed(const char* name){
	sprintf_s(Name, "%sAdsSpeed", name);
	AdsSpeed = C->getFData(Name);
}
void FALL::setRadius(){
	sprintf_s(Name, "fallRadius");
	Radius = C->getFData(Name);
}
void FALL::setAlpha(const char* name){
	sprintf_s(Name, "%sAlpha", name);
	Alpha = C->getFData(Name);
}
void FALL::setScore(const char* name){
	sprintf_s(Name, "%sScore", name);
	Score = C->getIData(Name);
}




