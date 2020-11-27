#include"TITLE_MANEGER.h"
#include"CONTAINER.h"
#include"IMG.h"
#include"TITLE.h"
#include"SELECT.h"
#include"HowToPlay.h"
#include"CREDIT.h"
#include"SIGNAL.h"
#include"BACK_GROUND.h"
#include"SOUND_MANEGER.h"
#include"input.h"

CONTAINER* TITLE_MANEGER::C = 0;

TITLE_MANEGER::TITLE_MANEGER() {

	BackGround = new BACK_GROUND;
	Title = new TITLE;
	Select = new SELECT;
	HowToPlay = new HOWTOPLAY;
	Credit = new CREDIT;
	Signal = new SIGNAL;
	SoundManeger = new SOUND_MANEGER;

}

TITLE_MANEGER::~TITLE_MANEGER() {
	delete BackGround;
	delete Title;
	delete Select;
	delete HowToPlay;
	delete Credit;
	delete Signal;
	delete SoundManeger;
}

void TITLE_MANEGER::backGround_Draw() {BackGround->draw();}

void TITLE_MANEGER::title_Draw(int gameCheck) {
	Title->draw();
	Select->draw();

	for (int i = 0; i < 4; i++) {
		if (gameCheck == i) {
			if (gameCheck != SE) {
				SE = gameCheck;
				SoundManeger->getSelectSE();
			}
			Signal->draw(i * Select->selectHeight());
		}
	}
}

void TITLE_MANEGER::Level_Draw(int LevelCheck) {
	Signal->Leveldraw(LevelCheck);
}


void TITLE_MANEGER::changeTitleImg() { BackGround->changeTitleImg(); }

void TITLE_MANEGER::changeGameImg() { BackGround->changeGameImg(); }

bool TITLE_MANEGER::howToPlay() {
	HowToPlay->draw();
	if (isTrigger(KEY_X)) { return true; }
	else return false;
}

bool TITLE_MANEGER::credit() {
	Credit->draw();
	if (isTrigger(KEY_X)) { return true; }
	else return false;
}
